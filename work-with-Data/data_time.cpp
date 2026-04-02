#include "data_time.h"

void find_MY_index(char str[20], int *month_i, int *year_i)
{
	int count = 0;
	for (int i = 0; i < 20; i++) {
		if (str[i] == ' ' && count < 1) {
			*month_i = i; //тут я получаю индекс пробела между днем и месяцем
			count++;
		}
		if (str[i] == ' ' && count >= 1) {
			*month_i = i;
			count++;
		}
	}
	if (count > 2) { throw Data_TimeException(); }
}

data_time::data_time()
{
	day = 1;
	month = 1;
	year = 2001;
	sec = 0;
}
//data_time::data_time(char date[20])
//{
//	
//	
//
//}