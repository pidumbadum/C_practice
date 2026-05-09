#pragma once
// Перечисление
enum Cell
{
	EMPTY,
	RED,
	YELLOW
};

class Field
{
	static constexpr int FIELD_WIDTH = 7;
	static constexpr int FIELD_HEIGHT = 6;
	Cell cells[FIELD_WIDTH][FIELD_HEIGHT];
	bool isRedTurn;
	Cell winner;
public:
	Field(bool isRedFirst);
	void clear(bool isRedFirst);
	bool makeTurn(int column);
	bool isWon(bool red) const;
	bool isOver() const;
	Cell getCell(int i, int j) const; // Возвращает значение ячейки поля (e, y, r)
	bool isRedTurnNow() const; //Проверка очереди
	void print() const; //вывод поля
	void printResult() const;// вывод результата игры
	void checkWinner();

};
