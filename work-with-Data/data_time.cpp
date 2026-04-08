#include "data_time.h"
char months_name[][17] = { "января", "февраля", "марта", "апреля", "мая", "июня",
							"июля", "августа", "сентября", "октября", "ноября", "декабря" };
char days31[] = "101010110101";

void Copy_string(const char* str_in, int start, int end, char* str_out)
{
	if (start < 0 || end > 20 || start >= end) {
		str_out[0] = '\0';
		return;
	}

	int j = 0;
	for (int i = start; i < end; i++) {
		str_out[j] = str_in[i];
		j++;
	}
	str_out[j] = '\0';

}
bool compare_chars(const char* one, const char* two) {
	if (strlen(one) != strlen(two)) {
		return false;
	}
	for (int i = 0; one[i] != '\0' && two[i] != '\0'; i++) {
		if (one[i] != two[i]) {
			return false;
		}
	}
	return true;
}
int Find_months_index(char* month) {
	for (int i = 0; i < 12; i++) {
		if (compare_chars(months_name[i], month)) {
			return i+1;
		}
	}
	return -1;
}
void find_DMY(const char* date, int* day, int* month, int* year) {
	int month_start_i = 0;
	int count = 0;
	const char* slice = date;
	for (int i = 0; date[i] != '\0'; i++) {
		if ((date[i] == ' ' || date[i] == '.') && count < 1) {
			slice = &date[i + 1];
			*day = atoi(date);
			atoi(slice) != 0 ? *month = atoi(slice) : month_start_i = i + 1;
			count++;
		}
		else if (date[i] == ' ' || date[i] == '.') {
			if (month_start_i != 0) {
				char result[17];
				Copy_string(date, month_start_i, i, result);
				*month = Find_months_index(result);
			}
			slice = &date[i + 1];
			*year = atoi(slice);
			count++;
		}

	}
}
void find_YMDtime(const char* date, int* day, int* month, int* year) {
	int month_start_i = 0;
	int count = 0;
	const char* slice = date;
	for (int i = 0; date[i] != '\0'; i++) {
		if ((date[i] == ' ' || date[i] == '.') && count < 1) {
			slice = &date[i + 1];
			*day = atoi(date);
			atoi(slice) != 0 ? *month = atoi(slice) : month_start_i = i + 1;
			count++;
		}
		else if (date[i] == ' ' || date[i] == '.') {
			if (month_start_i != 0) {
				char result[17];
				Copy_string(date, month_start_i, i, result);
				*month = Find_months_index(result);
			}
			slice = &date[i + 1];
			*year = atoi(slice);
			count++;
		}

	}
}
unsigned int data_time::toJulian_date() const {
	//формула с вики
	int a = (14 - month)/12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;
	unsigned int jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
	return jdn;
}
void data_time::Check_enters() const {
	//самые простые исключения
	if (month > 12 || month < 1 || day < 1 || year < 0 || day > 31){ throw Data_TimeException(); }
	//февраль
	if (month == 2 && (year % 4 == 0 || year % 400 == 0) && day > 29) {
		throw Data_TimeException();
	}
	else if(month == 2 && (year % 4 != 0 || year % 400 != 0) && day > 28){ throw Data_TimeException(); }
	//остальное
	else if (days31[month-1] != '1' && day > 30) { throw Data_TimeException(); }
}


//Конструктор по умолчанию и  с параматерами:
data_time::data_time()
{
	day = 1;
	month = 1;
	year = 2001;
	sec = 0;
	day_week = 0;
}
data_time::data_time(const char* date) : data_time()
{
	int i = 0;
	while (date[i] == ' ' || date[i] == '.' || date[i] == '-')
	{
		(date[i] == ' ' || date[i] == '.') ? find_DMY(date, &day, &month, &year) : find_YMDtime(date, &day, &month, &year);
		i++;
	}

	Check_enters();
}

//сравнение 
bool data_time::operator ==(const data_time& r) const
{
	return (toJulian_date() == r.toJulian_date());
}
bool data_time::operator !=(const data_time& r) const
{
	return !(*this == r);
}
bool data_time::operator > (const data_time& r) const
{
	return (toJulian_date() > r.toJulian_date());
}
bool data_time::operator >= (const data_time& r) const
{
	return (toJulian_date() >= r.toJulian_date());
}
bool data_time::operator < (const data_time& r) const
{
	return (toJulian_date() < r.toJulian_date());
}
bool data_time::operator <= (const data_time& r) const
{
	return !(*this >= r);
}


//ввод, вывод
ostream& operator <<(ostream& out, const data_time& str)
{
	if (str.day < 10) {
		out << 0 << str.day << '.';
	}
	else { out << str.day << '.'; }
	if (str.month < 10) {
		out << 0 << str.month << '.';
	}
	else { out << str.month << '.'; }
	out << str.year << endl;
	out << "-------------------------------"<<endl;
	if (str.day < 10) {
		out << 0 << str.day << ' ';
	}
	else { out << str.day << ' '; }
	out << months_name[str.month - 1]<< ' '; 
	out << str.year;
	return out;
}
istream& operator >>(istream& in, data_time& date) {
	char date_str[26]; //Змаенить везде!!!!!я считать не умею
	char symbol;
	int i = 0;
	while (i < 25 && in.get(symbol) && symbol != '\n' && symbol != '\r') {
		date_str[i++] = symbol;
	}
	date_str[i] = '\0';

	try {
		data_time temporary_date(date_str);

		date.day = temporary_date.day;
		date.month = temporary_date.month;
		date.year = temporary_date.year;
		date.sec = temporary_date.sec;
		date.Check_enters();
	}
	catch (const Data_TimeException&) {
		in.setstate(ios::failbit); // это не позволит ввести черти что
	}
	return in; //не работает с "18 августа 2017" 
}