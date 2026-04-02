#include "data_time.h"
char months_name[][17] = { "января", "февраля", "марта", "апреля", "мая", "июня",
							"июля", "августа", "сентября", "октября", "ноября", "декабря" };

void find_DMY_index(char str[20])
{
	int count = 0;
	char* slice;
	int day, month, year;
	for (int i = 0; i < 20; i++) {
		if ((str[i] == ' ' || str[i] == '.') && count < 1) {
			slice = &str[i + 1]; 
			day = atoi(str);
			month = atoi(slice);
			count++;
		}
		if ((str[i] == ' ' || str[i] == '.') && count >= 1) {
			slice = &str[i + 1];
			year = atoi(slice);
			count++;
		}
	}
	if (count != 2) { throw Data_TimeException(); } //своебразная проверка ввода, если разделителей оказалась больше или меньше 2, то была допущена ошибка
}

//Конструктор по умолчанию и  с параматерами:
data_time::data_time()
{
	day = 1;
	month = 1;
	year = 2001;
	sec = 0;
}
data_time::data_time(const char* date) : data_time()// чтобы кампилятор не возмущался сначала инициализируем значения по умолчанию
{
	int count = 0;
	const char* slice = date;
	for (int i = 0; i != '/0' && i < 20; i++) { //напоминание: спросить, какого && i < 20 решает 
		if ((date[i] == ' ' || date[i] == '.') && count < 1) {
			slice = &date[i + 1];
			day = atoi(date);
			month = atoi(slice);
			count++;
		}
		else if ((date[i] == ' ' || date[i] == '.') && count >= 1) {
			slice = &date[i + 1];
			year = atoi(slice);
			count++;
		}

	}

	if (count != 2) { throw Data_TimeException(); }//своебразная проверка ввода

}

//ввод, вывод
ostream& operator <<(ostream& out, const data_time& str)
{

	//проверить все возможные ошибки, например:
					//1.диапазоны дат. в определенных месяцах 30 дней, 31, в Феврале 28 или 29.
					//2.это не отрицательные значения, хотя з них можно сделать время до н.э. 
					//3.они больше нуля(касается только месяцев и дней)
					// Проверку можно вынести в отдельную функецию, чтобы пользоваться ею на всех этапах!!!
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
istream& operator >>(istream& in, data_time& str);
