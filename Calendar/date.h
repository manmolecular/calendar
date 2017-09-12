#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip> 

enum month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
bool check_leap(int y);
bool check(int d, int m, int y);						// Проверка корректности даты | 1 - корректна | 0 - ошибка

class date
{
	int day, month, year;
	static int date_format;								// Формат вывода даты

public:
	date(int d = 0, int m = 0, int y = 0);				// 0 - текущее значение, без параметров - текущая дата

	void change_date(int d = 0, int m = 0, int y = 0);	// 0 - текущее значение, без параметров - текущая дата
	void change_d(int d = 0);
	void change_m(int m = 0);
	void change_y(int y = 0);

	void show_date(int type = -1);						// Вывод на экран
	std::string get_date(int type = -1);				// Возвращение строки

	int get_d() { return day; };
	int get_m() { return month; };
	int get_y() { return year; };
 
	date operator++(int);
	date operator++();
	date operator--(int);
	date operator--();

	friend void change_format(int type = 0);			// Выбор формата вывода даты | 0 - d.m.y | 1 - m.d.y | 2 - d / m / y | 3 - m / d / y | 4 - d Month y

	friend std::istream& operator >> (std::istream& in, date& obj);
	friend std::ostream& operator << (std::ostream& os, date& obj);

	friend bool operator==(date &date1, date &data2);
	friend bool operator!=(date &date1, date &data2);
	friend bool operator>(date &date1, date &data2);
	friend bool operator<(date &date1, date &data2);
	friend bool operator>=(date &date1, date &data2);
	friend bool operator<=(date &date1, date &data2);
};

class date_exception
{
	std::string error_text;
public:
	date_exception(std::string a) : error_text(a) {};
};