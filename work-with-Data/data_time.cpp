#include "data_time.h"

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

data_time::data_time()
{
	day = 1;
	month = 1;
	year = 2001;
	sec = 0;
}

data_time::data_time(char date[20])
{
	data_time(); // чтобы кампилятор не возмущался сначала инициализируем значения по умолчанию
	int count = 0;
	char* slice;
	for (int i = 0; i < 20; i++) {
		if ((date[i] == ' ' || date[i] == '.') && count < 1) {
			slice = &date[i + 1];
			day = atoi(date);
			month = atoi(slice);
			count++;
		}
		if ((date[i] == ' ' || date[i] == '.') && count >= 1) {
			slice = &date[i + 1];
			year = atoi(slice);
			count++;
		}
	}
	if (count != 2) { throw Data_TimeException(); }//своебразная проверка ввода

}