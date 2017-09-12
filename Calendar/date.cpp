#include "date.h"

int date::date_format = 0;

/* Функции класса */

date::date(int d, int m, int y)
{
	/* Узнаем текущую дату */
	time_t seconds;
	time(&seconds);
	struct tm *timeinfo;
	timeinfo = localtime(&seconds);
	/***********************/

	if (!d) d = timeinfo->tm_mday;
	if (!m) m = timeinfo->tm_mon;
	if (!y) y = timeinfo->tm_year + 1900;

	if (!check(d, m, y)) throw date_exception("incorrect_date"); 	//бросаем исключение incorrect_date
	day = d;
	month = m;
	year = y;
}

void date::change_date(int d, int m, int y)
{
	/* Узнаем текущую дату */
	time_t seconds;
	time(&seconds);
	struct tm* timeinfo = localtime(&seconds);
	/***********************/

	if (!d) d = timeinfo->tm_mday;
	if (!m) m = timeinfo->tm_mon;
	if (!y) y = timeinfo->tm_year + 1900;

	if (!check(d, m, y))  throw date_exception("incorrect_date"); 	//бросаем исключение incorrect_date
	day = d;
	month = m;
	year = y;
}

void date::change_d(int d)
{
	if (!d)
	{
		time_t seconds;
		time(&seconds);
		struct tm* timeinfo = localtime(&seconds);
		d = timeinfo->tm_mday;
	}
	if (!check(d, month, year)) throw date_exception("incorrect_date"); 	//бросаем исключение incorrect_date
	day = d;
}

void date::change_m(int m)
{
	if (!m)
	{
		time_t seconds;
		time(&seconds);
		struct tm* timeinfo = localtime(&seconds);
		m = timeinfo->tm_mon;
	}
	if (!check(day, m, year)) throw date_exception("incorrect_date"); 	//бросаем исключение incorrect_date
	month = m;
}

void date::change_y(int y)
{
	if (!y)
	{
		time_t seconds;
		time(&seconds);
		struct tm* timeinfo = localtime(&seconds);
		y = timeinfo->tm_year + 1900;
	}
	if (!check(day, month, y)) throw date_exception("incorrect_date"); 	//бросаем исключение incorrect_date
	year = y;
}

void date::show_date(int type )
{
	if (type < 0 && type > 4) //Если мы указали тип - используем указанный. Если нет - используем стандартный
	{
		type = date_format;
	}
	switch (type)
	{
	case 0:
	{
		std::cout << std::setfill('0') << std::setw(2) << day << "." << std::setfill('0') << std::setw(2) << month << "." << year;
		break;
	}
	case 1:
	{
		std::cout << std::setfill('0') << std::setw(2) << month << "." << std::setfill('0') << std::setw(2) << day << "." << year;
		break;
	}

	case 2:
	{
		std::cout << std::setfill('0') << std::setw(2) << day << "/" << std::setfill('0') << std::setw(2) << month << "/" << year;
		break;
	}

	case 3:
	{
		std::cout << std::setfill('0') << std::setw(2) << month << "/" << std::setfill('0') << std::setw(2) << day << "/" << year;
		break;
	}

	case 4:
	{
		std::string mass[12] = { "January","February","March","April","May","June","Jule","August","September","October","November","December" };
		std::cout << day << " " << mass[month - 1] << " " << year;
		break;
	}
	}
}

std::string date::get_date(int type)
{
	std::string date_as_string;
	if (type < 0 && type > 4) //Если мы указали тип - используем указанный. Если нет - используем стандартный
	{
		type = date_format;
	}
	switch (type)
	{
	case 0:
	{
		if (day < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(day)) + ".";
		if (month < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(month)) + "." + std::to_string(static_cast<long long>(year));
		return date_as_string;
	}
	case 1:
	{
		if (month < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(month)) + ".";
		if (day < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(day)) + "." + std::to_string(static_cast<long long>(year));
		return date_as_string;
	}

	case 2:
	{
		if (day < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(day)) + "/";
		if (month < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(month)) + "/" + std::to_string(static_cast<long long>(year));
		return date_as_string;
	}

	case 3:
	{
		if (month < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(month)) + "/";
		if (day < 10) date_as_string += '0';
		date_as_string += std::to_string(static_cast<long long>(day)) + "/" + std::to_string(static_cast<long long>(year));
		return date_as_string;
	}

	case 4:
	{
		std::string mass[12] = { "January","February","March","April","May","June","Jule","August","September","October","November","December" };
		date_as_string += std::to_string(static_cast<long long>(day)) + " " + mass[month - 1] + " " + std::to_string(static_cast<long long>(year));
		return date_as_string;
	}
	}

}

date date::operator++(int)		// ПЕРЕГРУЗКА ПОСТФИКСНОЙ ВЕРСИИ ОПЕРАТОРА ++
{
	date a;
	a = *this;

	if (day < 30 && month != 2)
	{
		day += 1;
		return a;
	}

	if (day == 30)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) day += 1;
		else
		{
			day = 1;
			month += 1;
		}
		return a;
	}


	if (day == 31)
	{
		if (month == 12)
		{
			day = 1;
			month = 1;
			year += 1;
		}
		else
		{
			day = 1;
			month += 1;
		}
		return a;
	}


	if (month == 2)
	{
		if (day == 29)
		{
			day = 1;
			month += 1;
			return a;
		}

		if (day == 28)
		{
			if (check_leap(year))
			{
				day += 1;
				return a;
			}
			if (!check_leap(year))
			{
				day = 1;
				month += 1;
				return a;
			}
		}

		if (day < 28)
		{
			day += 1;
			return a;
		}
	}


	return a;
}

date date::operator++()		//ПЕРЕГРУЗКА ПРЕФИКСНОЙ ВЕРСИИ ОПЕРАТОРА ++
{

	if (day < 30 && month != 2)
	{

		day += 1;
		return *this;
	}

	if (day == 30)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) day += 1;
		else
		{
			day = 1;
			month += 1;
		}
		return *this;
	}


	if (day == 31)
	{
		if (month == 12)
		{
			day = 1;
			month = 1;
			year += 1;
		}
		else
		{
			day = 1;
			month += 1;
		}
		return *this;
	}


	if (month == 2)
	{
		if (day == 29)
		{
			day = 1;
			month += 1;
			return *this;
		}

		if (day == 28)
		{
			if (check_leap(year))
			{
				day += 1;
				return *this;
			}
			if (!check_leap(year))
			{
				day = 1;
				month += 1;
				return *this;
			}
		}

		if (day < 28)
		{
			day += 1;
			return *this;
		}
	}

}

date date::operator--(int)		//ПЕРЕГРУЗКА ПОСТФИКСНОЙ ВЕРСИИ ОПЕРАТОРА--
{
	date a;
	a = *this;

	if (day > 1)
	{
		day--;
		return a;
	}

	if (day == 1)
	{
		if (month == 1)
		{
			day = 31;
			month = 12;
			year -= 1;
			return a;
		}

		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
		{
			day = 31;
			month -= 1;
			return a;
		}

		if (month == 3)
		{
			if (check_leap(year))
			{
				day = 29;
				month -= 1;
			}
			else
			{
				day = 28;
				month -= 1;
			}
			return a;
		}

		if (month == 5 || month == 7 || month == 10 || month == 12)
		{
			day = 30;
			month -= 1;
			return a;
		}


	}

}

date date::operator--()		//ПЕРЕГРУЗКА ПРЕФИКСНОЙ ВЕРСИИ ОПЕРАТОРА-- 
{
	if (day > 1)
	{
		day--;
		return *this;
	}

	if (day == 1)
	{
		if (month == 1)
		{
			day = 31;
			month = 12;
			year -= 1;
			return *this;
		}

		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
		{
			day = 31;
			month -= 1;
			return *this;
		}

		if (month == 3)
		{
			if (check_leap(year))
			{
				day = 29;
				month -= 1;
			}
			else
			{
				day = 28;
				month -= 1;
			}
			return *this;
		}

		if (month == 5 || month == 7 || month == 10 || month == 12)
		{
			day = 30;
			month -= 1;
			return *this;
		}


	}

}





/* Внешние функции */

void change_format(int type)
{
	if (type > -1 && type < 5)
		date::date_format = type;
}

bool check(int d, int m, int y)
{
	if (y < 1970 || y > 2500) return 0;
	if (m < 1 || m > 12) return 0;
	if (d < 1 || d > 31) return 0;
	switch (m)
	{
	case JAN:
	{
		if (d > 31) return 0;
		return 1;
	}
	case FEB:
	{
		if (check_leap(y))
		{
			if (d > 29) return 0;
			return 1;
		}
		if (d > 28) return 0;
		return 1;
	}
	case MAR:
	{
		if (d > 31) return 0;
		return 1;
	}
	case APR:
	{
		if (d > 30) return 0;
		return 1;
	}
	case MAY:
	{
		if (d > 31) return 0;
		return 1;
	}
	case JUN:
	{
		if (d > 30) return 0;
		return 1;
	}
	case JUL:
	{
		if (d > 31) return 0;
		return 1;
	}
	case AUG:
	{
		if (d > 31) return 0;
		return 1;
	}
	case SEP:
	{
		if (d > 30) return 0;
		return 1;
	}
	case OCT:
	{
		if (d > 31) return 0;
		return 1;
	}
	case NOV:
	{
		if (d > 30) return 0;
		return 1;
	}
	case DEC:
	{
		if (d > 31) return 0;
		return 1;
	}
	}

}

bool check_leap(int y)		//Проверка високосный ли год 
{
	if (y % 4) return 0;
	if (y % 100) return 1;
	if (y % 400) return 0;
	return 1;
}


bool operator==(date &date1, date &date2)
{
	return (date1.year == date2.year) && (date1.month == date2.month) && (date1.day == date2.day);
}

bool operator!=(date &date1, date &date2)
{
	return !(date1 == date2);
};

bool operator<(date &date1, date &date2)
{
	if (date1.year != date2.year)
		return date1.year < date2.year;
	else if (date1.month != date2.month)
		return date1.month < date2.month;
	else return date1.day < date2.day;
}

bool operator>(date &date1, date &date2)
{
	if (date1.year != date2.year)
		return date1.year > date2.year;
	else if (date1.month != date2.month)
		return date1.month > date2.month;
	else return date1.day > date2.day;
}

bool operator>=(date &date1, date &date2)
{
	return !(date1 < date2);
}

bool operator<=(date &date1, date &date2)
{
	return !(date1 > date2);
}


std::istream& operator >> (std::istream& in, date& obj)
{
	int d, m, y;

	if (obj.date_format == 0 || obj.date_format == 2 || obj.date_format == 4)
	{
		in >> d >> m >> y;
	}
	else
	{
		in >> m >> d >> y;
	}
	obj.change_date(d, m, y);
	return in;
}

std::ostream& operator << (std::ostream& os, date& obj)
{
	switch (obj.date_format)
	{
	case 0:
	{
		os << std::setfill('0') << std::setw(2) << obj.day << "." << std::setfill('0') << std::setw(2) << obj.month << "." << obj.year;
		break;
	}
	case 1:
	{
		os << std::setfill('0') << std::setw(2) << obj.month << "." << std::setfill('0') << std::setw(2) << obj.day << "." << obj.year;
		break;
	}

	case 2:
	{
		os << std::setfill('0') << std::setw(2) << obj.day << "/" << std::setfill('0') << std::setw(2) << obj.month << "/" << obj.year;
		break;
	}

	case 3:
	{
		os << std::setfill('0') << std::setw(2) << obj.month << "/" << std::setfill('0') << std::setw(2) << obj.day << "/" << obj.year;
		break;
	}

	case 4:
	{
		std::string mass[12] = { "January","February","March","April","May","June","Jule","August","September","October","November","December" };
		os << obj.day << " " << mass[obj.month - 1] << " " << obj.year;
		break;
	}
	}
	return os;
}





