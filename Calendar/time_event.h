#pragma once
#include <string>
#include <iostream>
#include <ctime>

/*Реализовать перегрузки >, <, >=, <=, -
(больше, меньше, больше равно, меньше равно, минус
и возвращаеть булевы true или false*/

class time_event
{
private:
	int h, m, s;								// часы, минуты, секунды (why not - привет перфекционистам)
public:
	time_event();								// по умолчанию - текущее время
	time_event(int _h, int _m, int _s);			// метод задания времени
	time_event(const time_event &src);			//
	void set_time();							// задание времени
	int set_time(int _h, int _m, int _s);		// задание через аргументы
	void change_time();							// изменить время
	int change_time(int _h, int _m, int _s);	// изменить время через аргумент
	void show_time();							// показать время
	void add_time();							// добавить время
	int add_time(int _h, int _m, int _s);		// добавить через аргументы
	void dec_time();							// убавить время
	int dec_time(int _h, int _m, int _s);		// убавить через аргументы
	void time_now();							// указываем текущее время
	int return_h();								// вернуть часы
	int return_m();								// вернуть минуты
	int return_s();								// вернуть секунды
	std::string get_time();						// вернуть строку со временем
	time_event& operator-=(time_event &a);		// перегрузка минус равно
	time_event& operator+=(time_event &a);		// перегрузка плюс равно
	bool operator<(time_event &a);				// 
	bool operator==(time_event &a);				//	 сравнения
	bool operator>(time_event &a);				// 
	bool operator>=(time_event &a);				// 
	bool operator<=(time_event &a);				// 
};