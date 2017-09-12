#include "calendar.h"
#include <string>
#include <iostream>
#include "Windows.h"
#include <fstream>

/*

*******************************
*	    interface block		  *
*******************************

*/

calendar import(calendar object_cal)
{
	date object_dat;
	time_event object_tim_start;
	time_event object_tim_end;
	std::ifstream f;
	std::cout << "Форматирование документа для импорта: " << std::endl;
	std::cout << "dd.mm.yyyy; hh:mm:ss - hh:mm:ss; your note here; " << std::endl;
	std::cout << "(пробел после завершающей точки с запятой необходим)" << std::endl;
	std::cout << "Введите имя файла: " << std::endl;
	std::string filename;
	std::cin.ignore();
	std::getline(std::cin, filename);
	std::cout << "Выберите формат для импорта: " << std::endl;
	std::cout << "1. csv" << std::endl;
	std::cout << "2. txt" << std::endl;
	int choose;
	std::cout << "Ввод: ";
	std::cin >> choose;
	switch (choose)
	{
	case 1:
		filename += ".csv";
		break;
	case 2:
		filename += ".txt";
		break;
	}

	f.open(filename);
	if (f.is_open() == 0)
	{
		std::cout << std::endl << "Ошибка: файл не существует или не может быть открыт" << std::endl;
		exit(1);
	}
	else
	{
		std::cout << std::endl << "Файл успешно загружен!" << std::endl;
		char trash;
		int day, month, year;
		int sec, min, hour;
		char temp[100];
		int count = 0;
		while (!f.eof())
		{
			std::cout << ++count << ". ";
			f >> day >> trash >> month >> trash >> year >> trash;
			//std::cout << "дата: " << day << ":" << month << ":" << year << " | ";
			std::cout << "дата: ";
			object_dat.change_date(day, month, year);
			object_dat.show_date(1);
			std::cout << " | ";

			f >> hour >> trash >> min >> trash >> sec >> trash;
			//std::cout << "время: " << hour << ":" << min << ":" << sec << " - ";
			std::cout << "время: ";
			object_tim_start.set_time(hour, min, sec);
			object_tim_start.show_time();
			std::cout << " - ";

			f >> hour >> trash >> min >> trash >> sec >> trash;
			//std::cout << hour << ":" << min << ":" << sec << " | ";
			object_tim_end.set_time(hour, min, sec);
			object_tim_end.show_time();
			std::cout << " | ";

			f.getline(temp, 100 - 1, '\n');
			std::string name = temp;
			name.erase(name.find(' '), 1);
			name.erase(name.find(';'), 1);
			name.erase(name.rfind(' '), 1);
			std::cout << "событие: " << name << std::endl;
			event object_eve(object_tim_start, object_tim_end, name);
			object_cal.create_event(object_eve, object_dat);
		}
	}
	f.close();
	return object_cal;
}

/*Создание нового события в календаре*/
calendar create_new_event(calendar object_cal)
{
	date object_dat;
	time_event object_tim_start;
	time_event object_tim_end;

	int year, month, day;
	std::cout << std::endl << "Введите календарную дату события:" << std::endl;
	std::cout << "Год: ";
	std::cin >> year;
	std::cout << "Месяц: ";
	std::cin >> month;
	std::cout << "День: ";
	std::cin >> day;
	object_dat.change_date(day, month, year);
	std::cout << std::endl;
	std::cout << "Введите время начала события:" << std::endl;
	object_tim_start.set_time();
	std::cout << "Введите время окончания события:" << std::endl;
	object_tim_end.set_time();
	std::cout << "Введите событие: ";
	std::string temp;
	std::cin.ignore();				//omg
	std::getline(std::cin, temp);
	event object_eve(object_tim_start, object_tim_end, temp);
	std::cout << std::endl << "Проверка - введённое событие: " << std::endl;
	std::cout << "Дата: ";
	object_dat.show_date(4);
	std::cout << std::endl;
	std::cout << "Начало: ";
	object_eve.show_start_time();
	std::cout << std::endl;
	std::cout << "Конец: ";
	object_eve.show_end_time();
	std::cout << std::endl;
	std::cout << "Название: ";
	object_eve.show_name();
	std::cout << std::endl;
	object_cal.create_event(object_eve, object_dat);
	std::cout << "Событие было успешно создано в календаре." << std::endl;
	return object_cal;
}

/*Входное окно*/
int intro_opener()
{
	int a;
	std::cout << std::endl << std::endl;
	std::cout << "		" << " _____       _                _            " << std::endl;
	std::cout << "		" << "/  __ \\     | |              | |           " << std::endl;
	std::cout << "		" << "| /  \\/ __ _| | ___ _ __   __| | __ _ _ __ " << std::endl;
	std::cout << "		" << "| |    / _` | |/ _ \\ '_ \\ / _` |/ _` | '__|" << std::endl;
	std::cout << "		" << "| \\__/\\ (_| | |  __/ | | | (_| | (_| | |   " << std::endl;
	std::cout << "		" << "\\_____/\\__,_|_|\\___|_| |_|\\__,_|\\__,_|_|   " << std::endl;
	std::cout << "	" << "		" << "К а л е н д а р ь (v.0.9 - beta):" << std::endl;
	std::cout << std::endl;
	std::cout << "	" << "		" << "Выберите действие: " << std::endl;
	std::cout << "	" << "		" << "1. Создать событие" << std::endl;
	std::cout << "	" << "		" << "2. Показать даты, на которые назначены события" << std::endl;
	std::cout << "	" << "		" << "3. Показать события на дату" << std::endl;
	std::cout << "	" << "		" << "4. Показать все события" << std::endl;
	std::cout << "	" << "		" << "5. Экспортировать в csv/txt" << std::endl;
	std::cout << "	" << "		" << "6. Импортировать из csv/txt" << std::endl;
	std::cout << std::endl;
	std::cout << "	" << "		" << "Другие действия: " << std::endl;
	std::cout << "	" << "		" << "0. Выход из программы" << std::endl;
	std::cout << "	" << "		" << "10. Credits / about" << std::endl;
	std::cout << std::endl << "	" << "		" << "Ввод: ";
	std::cin >> a;
	return a;
}

//calendar delete_some_event(calendar object_cal)
//{
//	date object_dat;
//	int year, month, day;
//	std::cout << std::endl << "Введите дату, на которую нужно удалить событие" << std::endl;
//	std::cout << "Год: ";
//	std::cin >> year;
//	std::cout << "Месяц: ";
//	std::cin >> month;
//	std::cout << "День: ";
//	std::cin >> day;
//	object_dat.change_date(day, month, year);
//	if (check_date)
//	{
//		std::cout << std::endl << "События на данную дату:" << std::endl;
//		object_cal.show_date(object_dat);
//		std::cout << std::endl << "Выберите событие, которое следует удалить: " << std::endl;
//	}
//	else
//	{
//		std::cout << std::endl << "Не найдено событий для заданой даты." << std::endl;
//	}
//	return object_cal;
//}

calendar show_all_dates(calendar object_cal)
{
	std::cout << "В каком формате следует вывести даты?" << std::endl;
	std::cout << "1. day.month.year" << std::endl;
	std::cout << "2. month.day.year" << std::endl;
	std::cout << "3. day/month/year" << std::endl;
	std::cout << "4. month/day/year" << std::endl;
	std::cout << "5. day month(word) year" << std::endl;
	std::cout << "Ввод: ";
	int flag;
	std::cin >> flag;
	object_cal.show_all_dates(flag-1);
	return object_cal;
}

calendar show_date_eve(calendar object_cal)
{
	date object_dat;
	int year, month, day;
	std::cout << std::endl << "Введите дату, на которую следует показать события:" << std::endl;
	std::cout << "Год: ";
	std::cin >> year;
	std::cout << "Месяц: ";
	std::cin >> month;
	std::cout << "День: ";
	std::cin >> day;
	object_dat.change_date(day, month, year);
	if (object_cal.check_date(object_dat))
	{
		std::cout << "События, назначенные на заданную дату:" << std::endl;
		object_cal.show_date(object_dat);
	}
	else
	{
		std::cout << "На данную дату событий не найдено." << std::endl;
	}
	return object_cal;
}

calendar show_all_eve(calendar object_cal)
{
	std::cout << std::endl;
	object_cal.show_all_events();
	std::cout << std::endl;
	return object_cal;
}

void aboutus()
{
std::cout << std::endl;
std::cout << "	" << "Совместный проект группы 04505 (Компьютерная безопасность, 2-й курс) " << std::endl;
Sleep(300);
std::cout << "	" << "механико-математического факультета Томского Государственного университета. " << std::endl;
Sleep(300);
std::cout << "	" << " " << std::endl;
Sleep(300);
std::cout << "	" << "Выражаем благодарности: " << std::endl;
Sleep(300);
std::cout << "	" << "1. Николаю Николаевичу Богословскому и Чуруксаевой Владиславе Васильевне -  " << std::endl;
Sleep(300);
std::cout << "	" << "за то, что верили, что у нас все получится, и за всю оказанную нам помощь " << std::endl;
Sleep(300);
std::cout << "	" << "в процессе работы над проектом. " << std::endl;
Sleep(300);
std::cout << "	" << " " << std::endl;
Sleep(300);
std::cout << "	" << "2. Всему составу группы 04505 и каждой из 4-х классовых групп в отдельности. " << std::endl;
Sleep(300);
std::cout << "	" << " " << std::endl;
Sleep(300);
std::cout << "	" << "3. Бьёрну Страуструпу " << std::endl;
Sleep(300);
std::cout << std::endl;
}

calendar output_to_file(calendar object_cal)
{
	std::cout << "Введите имя файла для записи: " << std::endl;
	std::string name;
	std::cin.ignore();				//omg
	std::getline(std::cin, name);
	std::cout << "Выберите формат для экспорта: " << std::endl;
	std::cout << "1. csv" << std::endl;
	std::cout << "2. txt" << std::endl;
	int choose;
	std::cout << "Ввод: ";
	std::cin >> choose;
	switch (choose)
	{
		case 1:
			name = name + ".csv";
			break;
		case 2:
			name = name + ".txt";
			break;
	}
	object_cal.output_to_file(name);
	std::cout << "Файл был успешно записан" << std::endl;
	return object_cal;
}

/*Свитч, выбирающий действие*/
calendar main_choose(int choose, calendar object_cal)
{
	switch (choose)
	{
	case 0:
		exit(1);
		break;
	case 1:
		object_cal = create_new_event(object_cal);
		break;
	case 2:
		object_cal = show_all_dates(object_cal);
		break;
	case 3:
		object_cal = show_date_eve(object_cal);
		break;
	case 4:
		object_cal = show_all_eve(object_cal);
		break;
	case 5:
		object_cal = output_to_file(object_cal);
		break;
	case 6:
		object_cal = import(object_cal);
		break;
	case 10:
		aboutus();
		break;
	}
	return object_cal;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("MODE CON: COLS=90 LINES=40");
	calendar object_cal;
	int choose;
	int combo_breaker = 1;
	while (combo_breaker)
	{
		choose = intro_opener();
		object_cal = main_choose(choose, object_cal);
		std::cout << std::endl << "Вернуться в главное меню? [0/1]: ";
		std::cin >> combo_breaker;
		if (combo_breaker)
		{
			system("cls");
		}
	}
	return 0;
}