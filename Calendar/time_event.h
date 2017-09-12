#pragma once
#include <string>
#include <iostream>
#include <ctime>

/*����������� ���������� >, <, >=, <=, -
(������, ������, ������ �����, ������ �����, �����
� ����������� ������ true ��� false*/

class time_event
{
private:
	int h, m, s;								// ����, ������, ������� (why not - ������ ���������������)
public:
	time_event();								// �� ��������� - ������� �����
	time_event(int _h, int _m, int _s);			// ����� ������� �������
	time_event(const time_event &src);			//
	void set_time();							// ������� �������
	int set_time(int _h, int _m, int _s);		// ������� ����� ���������
	void change_time();							// �������� �����
	int change_time(int _h, int _m, int _s);	// �������� ����� ����� ��������
	void show_time();							// �������� �����
	void add_time();							// �������� �����
	int add_time(int _h, int _m, int _s);		// �������� ����� ���������
	void dec_time();							// ������� �����
	int dec_time(int _h, int _m, int _s);		// ������� ����� ���������
	void time_now();							// ��������� ������� �����
	int return_h();								// ������� ����
	int return_m();								// ������� ������
	int return_s();								// ������� �������
	std::string get_time();						// ������� ������ �� ��������
	time_event& operator-=(time_event &a);		// ���������� ����� �����
	time_event& operator+=(time_event &a);		// ���������� ���� �����
	bool operator<(time_event &a);				// 
	bool operator==(time_event &a);				//	 ���������
	bool operator>(time_event &a);				// 
	bool operator>=(time_event &a);				// 
	bool operator<=(time_event &a);				// 
};