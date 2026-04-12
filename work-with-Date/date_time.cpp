#include "date_time.h"
char months_name[][17] = { "января", "февраля", "марта", "апреля", "мая", "июня",
							"июля", "августа", "сентября", "октября", "ноября", "декабря" };
char days31[] = "101010110101";
char days_name[][23] = {
	"понедельник",
	"вторник",
	"среда",
	"четверг",
	"пятница",
	"суббота",
	"воскресенье"
};

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
	*day = 1;
	*month = 1;
	*year = 2001;
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
void find_YMDtime(const char* date, int* day, int* month, int* year, int* sec) {
	*day = 1;
	*month = 1;
	*year = 2001;
	*sec = 0;
	int count = 0;
	const char* slice = date;
	for (int i = 0; date[i] != '\0'; i++) {
		if (date[i] == '-' && count < 1) {
			slice = &date[i + 1];
			*year = atoi(date);
			*month = atoi(slice);
			count++;
		}
		else if (date[i] == '-') {
			slice = &date[i + 1];
			*day = atoi(slice);
			count++;
		}
		if (date[i] == 'T')
		{
			slice = &date[i + 1];
			*sec += atoi(slice) * 3600;
			count++;
		}
		if (date[i] == ':' && count < 4)
		{
			slice = &date[i + 1];
			*sec += atoi(slice) * 60;
			count++;
		}
		else if (date[i] == ':') {
			slice = &date[i + 1];
			*sec += atoi(slice);
		}

	}
}

//Вспомогательные
double date_time::toJulian_date() const {
	//формула с вики
	int a = (14 - month)/12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;
	double jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

	//секунды
	double h = sec / 3600.0;
	double mi = (sec % 3600) / 60.0;
	double s= (sec % 3600) % 60;
	double jd = (h - 12) / 24 + mi / 1440 + s / 86400;
	jd < 0 ? jd *= -1 : jd;
	jdn += jd;
	return jdn;
}
void date_time::Check_enters() const {
	//самые простые исключения
	if (month > 12 || month < 1 || day < 1 || year < 0 || day > 31){ throw date_TimeException(); }
	//февраль
	if (month == 2 && (year % 4 == 0 || year % 400 == 0) && day > 29) {
		throw date_TimeException();
	}
	else if(month == 2 && (year % 4 != 0 || year % 400 != 0) && day > 28){ throw date_TimeException(); }
	//месяцы
	else if (days31[month-1] != '1' && day > 30) { throw date_TimeException(); }
	//Время
	if (sec < 0 || sec > 86399 || sec / 3600 > 23 || (sec % 3600) / 60 > 59 || (sec % 3600) % 60 > 59) { throw date_TimeException(); }
}

//Конструктор по умолчанию и  с параматерами:
date_time::date_time()
{
	day = 1;
	month = 1;
	year = 2001;
	sec = 0;
	day_week = 0;
}
date_time::date_time(const char* date)
{
	for (int i = 0; date[i] != '\0'; i++) {
		if (date[i] == ' ' || date[i] == '.') {
			find_DMY(date, &day, &month, &year);
			break;
		}
		else {
			find_YMDtime(date, &day, &month, &year, &sec);
		}
	}
	Check_enters();
}

//Конструктор копирования
date_time date_time:: operator = (const date_time& date) {
	day = date.day;
	month = date.month;
	year = date.year;
	sec = date.sec;
	day_week = date.day_week;
	Check_enters();
	return *this;
}

//разница между датами в днях
int date_time::dates_diff(const date_time& date1) const {
	int diff = toJulian_date() - date1.toJulian_date();
	if (diff < 0) diff = -diff;
	return diff;
}
//день недели
const char* date_time::day_of_week() {
	int day_i = (int(toJulian_date()) % 7);
	return days_name[day_i];
}

//сравнение 
bool date_time::operator ==(const date_time& r) const
{
	return (toJulian_date() == r.toJulian_date());
}
bool date_time::operator !=(const date_time& r) const
{
	return !(*this == r);
}
bool date_time::operator > (const date_time& r) const
{
	return (toJulian_date() > r.toJulian_date());
}
bool date_time::operator >= (const date_time& r) const
{
	return (toJulian_date() >= r.toJulian_date());
}
bool date_time::operator < (const date_time& r) const
{
	return (toJulian_date() < r.toJulian_date());
}
bool date_time::operator <= (const date_time& r) const
{
	return !(*this >= r);
}


//ввод, вывод
ostream& operator <<(ostream& out, const date_time& str)
{
	if (str.day < 10) {
		out << 0 << str.day << '.';
	}
	else { out << str.day << '.'; }
	if (str.month < 10) {
		out << 0 << str.month << '.';
	}
	else { out << str.month << '.'; }
	out << str.year << ' ';
	if (str.sec != 0) { out << str.sec / 3600 << ':' << (str.sec % 3600) / 60<< ':' << (str.sec % 3600) % 60; }
	out <<endl<< "-------------------------------"<<endl;
	if (str.day < 10) {
		out << 0 << str.day << ' ';
	}
	else { out << str.day << ' '; }
	out << months_name[str.month - 1]<< ' '; 
	out << str.year << ' ';
	if (str.sec != 0) { out << str.sec / 3600 << ':' << (str.sec % 3600) / 60 << ':' << (str.sec % 3600) % 60; }
	return out;
}
istream& operator >>(istream& in, date_time& date) {
	char date_str[26]; //Змаенить везде!!!!!я считать не умею
	char symbol;
	int i = 0;
	while (i < 25 && in.get(symbol) && symbol != '\n' && symbol != '\r') {
		date_str[i++] = symbol;
	}
	date_str[i] = '\0';

	try {
		date_time temporary_date(date_str);

		date.day = temporary_date.day;
		date.month = temporary_date.month;
		date.year = temporary_date.year;
		date.sec = temporary_date.sec;
		date.Check_enters();
	}
	catch (const date_TimeException&) {
		in.setstate(ios::failbit); // это не позволит ввести черти что
	}
	return in; //не работает с "18 августа 2017" 
}