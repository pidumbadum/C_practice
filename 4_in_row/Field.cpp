#include "Field.h"
#include <clocale>
#include <iostream>
using namespace std;

char cells_name[][17] = {' ', 'R', 'Y'};
const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;

Field::Field(bool isRedFirst)
{
	clear(isRedFirst);
}
void Field::clear(bool isRedFirst)
{
	isRedTurn = isRedFirst;
	winner = EMPTY;
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
			cells[i][j] = EMPTY;
}
bool Field::makeTurn(int column) //
{
	if (winner != EMPTY || column < 1 || column > FIELD_WIDTH)
		return false;
	int i = column - 1;
	for (int j = 0; j < FIELD_HEIGHT; j++)
		if (cells[i][j] == EMPTY)
		{
			cells[i][j] = isRedTurn ? RED : YELLOW;
			checkWinner();
			isRedTurn = !isRedTurn;
			return true;
		}
	return false;
}
void Field::checkWinner()
{
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			Cell start = cells[i][j];
			if (start == EMPTY) continue;
			for (int dir = 0; dir < DIR_NUMBER; dir++)
			{
				int length = 0, iline = i, jline = j;
				while (++length < WIN_LENGTH)
				{
					iline += di[dir];
					jline += dj[dir];
					if (iline < 0 || iline >= FIELD_WIDTH ||
						jline < 0 || jline >= FIELD_HEIGHT)
						break;
					if (cells[iline][jline] != start) break;
				}
				if (length == WIN_LENGTH)
				{
					winner = start;
					return;
				}
			}
		}
}
bool Field::isOver() const
{
	if (winner != EMPTY) { return true; }
	for (int i = 0; i < FIELD_WIDTH; i++) {
		for (int j = 0; j < FIELD_HEIGHT; j++) {
			// Если хоть одна ячейка свободна,
			// игра не окончена
			if (cells[i][j] == EMPTY) { return false; }
		}
	}
	// Все ячейки заняты
	return true;
}
Cell Field::getCell(int i, int j) const {
	return cells[i][j];
}
bool Field::isRedTurnNow() const {
	return isRedTurn;
}
void Field::print() const {
	for (int w = 0; w < FIELD_WIDTH; w++) {
		cout << ' ' << w + 1 << ' ';
	}
	cout << "\n-----------------------\n";
	for (int h = 0; h < FIELD_HEIGHT; h++) {
		for (int w = 0; w < FIELD_WIDTH; w++) {
			if (w == 0) { cout << '|';}
			switch (cells[w][h]) {
			case EMPTY: cout << "   "; break;
			case RED:   cout << " 🔴 "; break; 
			case YELLOW:cout << " 🟡 "; break; 
			}
			if (w == FIELD_WIDTH - 1) { cout << "| \n"; }
		}
	}
	cout << "\n-----------------------\n";
}
void Field::printResult() const {
	switch (winner) {
	case EMPTY: cout << "Ничья!"; break;
	case RED:   cout << "Победа красных! 🔴"; break;
	case YELLOW:cout << "Победа желтых! 🟡 "; break;
	}
}
