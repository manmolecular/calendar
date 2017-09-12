#include "time_event.h"

/*Текущее время по дефолту*/
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

/*Ручное вбивание через cpp код*/
time_event::time_event(int _h, int _m, int _s)
{
	h = _h;
	m = _m;
	s = _s;
}

time_event::time_event(const time_event &src) : h(src.h), m(src.m), s(src.s) {};

/*Указываем текущее время*/
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

/*Задаем время через диалог с юзером*/
void time_event::set_time()
{
	std::cout << "Введите время: " << std::endl;
	std::cout << "Часы (0-24): ";
	std::cin >> h;
	/*до тех пор, пока юзер не поймёт*/
	while (h >= 24 || h < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Часы (0 - 24) : ";
		std::cin >> h;
	}
	std::cout << "Минуты (0-60): ";
	std::cin >> m;
	/*до тех пор, пока юзер не поймёт*/
	while (m >= 60 || m < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Минуты (0 - 60) : ";
		std::cin >> m;
	}
	/*для тех, кто в себе уверен и стопроц знает, что успеет*/
	std::cout << "Секунды (0-60): ";
	std::cin >> s;
	/*до тех пор, пока юзер не поймёт*/
	while (s >= 60 || s < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Секунды (0 - 60) : ";
		std::cin >> s;
	}
	std::cout << std::endl;
}

/*Задаем время через аргументы*/
int time_event::set_time(int _h, int _m, int _s)
{
	if ((h >= 24 || h < 0) || (m >= 60 || m < 0) || (s >= 60 || s < 0))
	{
		std::cout << "Ошибка: неверный формат. Проверьте аргументы." << std::endl;
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

/*Изменить время*/
void time_event::change_time()
{
	std::cout << "Введите время: " << std::endl;
	std::cout << "Часы (0-24): ";
	std::cin >> h;
	/*до тех пор, пока юзер не поймёт*/
	while (h >= 24 || h < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Часы (0 - 24) : ";
		std::cin >> h;
	}
	std::cout << "Минуты (0-60): ";
	std::cin >> m;
	/*до тех пор, пока юзер не поймёт*/
	while (m >= 60 || m < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Минуты (0 - 60) : ";
		std::cin >> m;
	}
	/*для тех, кто в себе уверен и стопроц знает, что успеет*/
	std::cout << "Секунды (0-60): ";
	std::cin >> s;
	/*до тех пор, пока юзер не поймёт*/
	while (s >= 60 || s < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Секунды (0 - 60) : ";
		std::cin >> s;
	}
	std::cout << std::endl;
}

/*Изменить через аргументы*/
int time_event::change_time(int _h, int _m, int _s)
{
	{
		if ((h >= 24 || h < 0) || (m >= 60 || m < 0) || (s >= 60 || s < 0))
		{
			std::cout << "Ошибка: неверный формат. Проверьте аргументы." << std::endl;
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

/*Отображаем время*/
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

/*Добавление времени*/
void time_event::add_time()
{
	std::cout << "Отложить задание на более позднее время: " << std::endl;
	std::cout << "+ часы: ";
	int _h, _m, _s;
	std::cin >> _h;
	while (h + _h >= 24 || h + _h < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Часы (0 - 24) : ";
		std::cin >> _h;
	}
	h = h + _h;
	std::cout << "+ минуты: ";
	std::cin >> _m;
	while (m + _m >= 60 || m + _m < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Минуты (0 - 60) : ";
		std::cin >> _m;
	}
	m = m + _m;
	std::cout << "+ секунды: ";
	std::cin >> _s;
	while (s + _s >= 60 || s + _s < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Секунды: (0 - 60) : ";
		std::cin >> _s;
	}
	s = s + _s;
}

/*Убавление времени*/
void time_event::dec_time()
{
	std::cout << "Задать более раннее время: " << std::endl;
	std::cout << "- часы: ";
	int _h, _m, _s;
	std::cin >> _h;
	while (h - _h >= 24 || h - _h < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Часы (0 - 24) : ";
		std::cin >> _h;
	}
	h = h - _h;
	std::cout << "- минуты: ";
	std::cin >> _m;
	while (m - _m >= 60 || m - _m < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Минуты (0 - 60) : ";
		std::cin >> _m;
	}
	m = m - _m;
	std::cout << "- секунды: ";
	std::cin >> _s;
	while (s - _s >= 60 || s - _s < 0)
	{
		std::cout << "Ошибка: недопустимый формат. " << std::endl;
		std::cout << "Секунды: (0 - 60) : ";
		std::cin >> _s;
	}
	s = s - _s;
}

/*Добавление времени через аргументы*/
int time_event::add_time(int _h, int _m, int _s)
{
	if ((h + _h >= 24 || h + _h < 0) || (m + _m >= 60 || m + _m < 0) || (s + _s >= 60 || s + _s < 0))
	{
		std::cout << "Ошибка: неверный формат. Проверьте аргументы." << std::endl;
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

/*Убавление времени через аргументы*/
int time_event::dec_time(int _h, int _m, int _s)
{
	if ((h - _h >= 24 || h - _h < 0) || (m - _m >= 60 || m - _m < 0) || (s - _s >= 60 || s - _s < 0))
	{
		std::cout << "Ошибка: неверный формат. Проверьте аргументы." << std::endl;
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

/*Перегрузка -=*/
time_event& time_event::operator-=(time_event &a)
{
	h -= a.h;
	m -= a.m;
	s -= a.s;
	return *this;
}

/*меньше равно*/
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

/*больше равно*/
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

/*Меньше*/
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

/*Больше*/
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

/*Равно*/
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

/*Перегрузка -*/
time_event operator-(time_event a, time_event b)
{
	time_event r;
	r = a;
	return r -= b;
}

/*Перегрузка +=*/
time_event& time_event::operator+=(time_event &a)
{
	h += a.h;
	m += a.m;
	s += a.s;
	return *this;
}

/*Перегрузка +*/
time_event operator+(time_event a, time_event b)
{
	time_event r;
	r = a;
	return r += b;
}

/*Вернуть часы*/
int time_event::return_h()
{
	return h;
}

/*Вернуть минуты*/
int time_event::return_m()
{
	return m;
}

/*Вернуть секунды*/
int time_event::return_s()
{
	return s;
}

/*Работает или нет?*/
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