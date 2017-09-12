#include "time_event.h"

/*������� ����� �� �������*/
time_event::time_event()
{
	time_t t;
	tm *tk;
	time(&t);
	tk = localtime(&t);
	h = tk->tm_hour;
	m = tk->tm_min;
	s = tk->tm_sec;
}

/*������ �������� ����� cpp ���*/
time_event::time_event(int _h, int _m, int _s)
{
	h = _h;
	m = _m;
	s = _s;
}

time_event::time_event(const time_event &src) : h(src.h), m(src.m), s(src.s) {};

/*��������� ������� �����*/
void time_event::time_now()
{
	time_t t;
	tm *tk;
	time(&t);
	tk = localtime(&t);
	h = tk->tm_hour;
	m = tk->tm_min;
	s = tk->tm_sec;
}

/*������ ����� ����� ������ � ������*/
void time_event::set_time()
{
	std::cout << "������� �����: " << std::endl;
	std::cout << "���� (0-24): ";
	std::cin >> h;
	/*�� ��� ���, ���� ���� �� �����*/
	while (h >= 24 || h < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "���� (0 - 24) : ";
		std::cin >> h;
	}
	std::cout << "������ (0-60): ";
	std::cin >> m;
	/*�� ��� ���, ���� ���� �� �����*/
	while (m >= 60 || m < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "������ (0 - 60) : ";
		std::cin >> m;
	}
	/*��� ���, ��� � ���� ������ � ������� �����, ��� ������*/
	std::cout << "������� (0-60): ";
	std::cin >> s;
	/*�� ��� ���, ���� ���� �� �����*/
	while (s >= 60 || s < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "������� (0 - 60) : ";
		std::cin >> s;
	}
	std::cout << std::endl;
}

/*������ ����� ����� ���������*/
int time_event::set_time(int _h, int _m, int _s)
{
	if ((h >= 24 || h < 0) || (m >= 60 || m < 0) || (s >= 60 || s < 0))
	{
		std::cout << "������: �������� ������. ��������� ���������." << std::endl;
		return 0;
	}
	else
	{
		h = _h;
		m = _m;
		s = _s;
		return 1;
	}
}

/*�������� �����*/
void time_event::change_time()
{
	std::cout << "������� �����: " << std::endl;
	std::cout << "���� (0-24): ";
	std::cin >> h;
	/*�� ��� ���, ���� ���� �� �����*/
	while (h >= 24 || h < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "���� (0 - 24) : ";
		std::cin >> h;
	}
	std::cout << "������ (0-60): ";
	std::cin >> m;
	/*�� ��� ���, ���� ���� �� �����*/
	while (m >= 60 || m < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "������ (0 - 60) : ";
		std::cin >> m;
	}
	/*��� ���, ��� � ���� ������ � ������� �����, ��� ������*/
	std::cout << "������� (0-60): ";
	std::cin >> s;
	/*�� ��� ���, ���� ���� �� �����*/
	while (s >= 60 || s < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "������� (0 - 60) : ";
		std::cin >> s;
	}
	std::cout << std::endl;
}

/*�������� ����� ���������*/
int time_event::change_time(int _h, int _m, int _s)
{
	{
		if ((h >= 24 || h < 0) || (m >= 60 || m < 0) || (s >= 60 || s < 0))
		{
			std::cout << "������: �������� ������. ��������� ���������." << std::endl;
			return 0;
		}
		else
		{
			h = _h;
			m = _m;
			s = _s;
			return 1;
		}
	}
}

/*���������� �����*/
void time_event::show_time()
{
	if (h == 0 && m == 0 && s == 0)
	{
		std::cout << "00:00:00";
		return;
	}
	if (h >= 0 && h < 10)
	{
		std::cout << "0" << h << ":";
	}
	else
	{
		std::cout << h << ":";
	}
	if (m >= 0 && m < 10)
	{
		std::cout << "0" << m << ":";
	}
	else
	{
		std::cout << m << ":";
	}
	if (s >= 0 && s < 10)
	{
		std::cout << "0" << s;
	}
	else
	{
		std::cout << s;
	}
}

/*���������� �������*/
void time_event::add_time()
{
	std::cout << "�������� ������� �� ����� ������� �����: " << std::endl;
	std::cout << "+ ����: ";
	int _h, _m, _s;
	std::cin >> _h;
	while (h + _h >= 24 || h + _h < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "���� (0 - 24) : ";
		std::cin >> _h;
	}
	h = h + _h;
	std::cout << "+ ������: ";
	std::cin >> _m;
	while (m + _m >= 60 || m + _m < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "������ (0 - 60) : ";
		std::cin >> _m;
	}
	m = m + _m;
	std::cout << "+ �������: ";
	std::cin >> _s;
	while (s + _s >= 60 || s + _s < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "�������: (0 - 60) : ";
		std::cin >> _s;
	}
	s = s + _s;
}

/*��������� �������*/
void time_event::dec_time()
{
	std::cout << "������ ����� ������ �����: " << std::endl;
	std::cout << "- ����: ";
	int _h, _m, _s;
	std::cin >> _h;
	while (h - _h >= 24 || h - _h < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "���� (0 - 24) : ";
		std::cin >> _h;
	}
	h = h - _h;
	std::cout << "- ������: ";
	std::cin >> _m;
	while (m - _m >= 60 || m - _m < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "������ (0 - 60) : ";
		std::cin >> _m;
	}
	m = m - _m;
	std::cout << "- �������: ";
	std::cin >> _s;
	while (s - _s >= 60 || s - _s < 0)
	{
		std::cout << "������: ������������ ������. " << std::endl;
		std::cout << "�������: (0 - 60) : ";
		std::cin >> _s;
	}
	s = s - _s;
}

/*���������� ������� ����� ���������*/
int time_event::add_time(int _h, int _m, int _s)
{
	if ((h + _h >= 24 || h + _h < 0) || (m + _m >= 60 || m + _m < 0) || (s + _s >= 60 || s + _s < 0))
	{
		std::cout << "������: �������� ������. ��������� ���������." << std::endl;
		return 0;
	}
	else
	{
		h = h + _h;
		m = m + _m;
		s = s + _s;
		return 1;
	}
}

/*��������� ������� ����� ���������*/
int time_event::dec_time(int _h, int _m, int _s)
{
	if ((h - _h >= 24 || h - _h < 0) || (m - _m >= 60 || m - _m < 0) || (s - _s >= 60 || s - _s < 0))
	{
		std::cout << "������: �������� ������. ��������� ���������." << std::endl;
		return 0;
	}
	else
	{
		h = h - _h;
		m = m - _m;
		s = s - _s;
		return 1;
	}
}

std::string time_event::get_time()
{
	return (std::to_string(static_cast<long long>(h)) + ":" + std::to_string(static_cast<long long>(m)) + ":" + std::to_string(static_cast<long long>(s)));
}

/*���������� -=*/
time_event& time_event::operator-=(time_event &a)
{
	h -= a.h;
	m -= a.m;
	s -= a.s;
	return *this;
}

/*������ �����*/
bool time_event::operator<=(time_event &a)
{
	if (h != a.h)
	{
		return h <= a.h;
	}
	else if (m != a.m)
	{
		return m <= a.m;
	}
	else return s <= a.s;
}

/*������ �����*/
bool time_event::operator>=(time_event &a)
{
	if (h != a.h)
	{
		return h >= a.h;
	}
	else if (m != a.m)
	{
		return m >= a.m;
	}
	else return s >= a.s;
}

/*������*/
bool time_event::operator<(time_event &a)
{
	if (h != a.h)
	{
		return h < a.h;
	}
	else if (m != a.m)
	{
		return m < a.m;
	}
	else return s < a.s;
}

/*������*/
bool time_event::operator>(time_event &a)
{
	if (h != a.h)
	{
		return h > a.h;
	}
	else if (m != a.m)
	{
		return m > a.m;
	}
	else return s > a.s;
}

/*�����*/
bool time_event::operator==(time_event &a)
{
	if (h != a.h)
	{
		return h == a.h;
	}
	else if (m != a.m)
	{
		return m == a.m;
	}
	else return s == a.s;
}

/*���������� -*/
time_event operator-(time_event a, time_event b)
{
	time_event r;
	r = a;
	return r -= b;
}

/*���������� +=*/
time_event& time_event::operator+=(time_event &a)
{
	h += a.h;
	m += a.m;
	s += a.s;
	return *this;
}

/*���������� +*/
time_event operator+(time_event a, time_event b)
{
	time_event r;
	r = a;
	return r += b;
}

/*������� ����*/
int time_event::return_h()
{
	return h;
}

/*������� ������*/
int time_event::return_m()
{
	return m;
}

/*������� �������*/
int time_event::return_s()
{
	return s;
}

/*�������� ��� ���?*/
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	time_event sometime, anothertime;
//	sometime.set_time(9, 9, 6);
//	anothertime.set_time(2, 3, 4);
//	sometime = sometime - anothertime;
//	sometime.show_time();
//	sometime = sometime + anothertime;
//	sometime.show_time();
//	anothertime.show_time();
//
//	std::cout << std::endl;
//	if (sometime == anothertime)
//	{
//		std::cout << "yeah";
//	}
//	else
//	{
//		std::cout << "nope";
//	}
//	std::cout << std::endl;
//
//	std::cout << sometime.get_time() << std::endl;
//	return 0;
//}