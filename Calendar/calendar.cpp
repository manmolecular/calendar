#include "calendar.h"
#include <fstream>

calendar::calendar() : dateHead(NULL) {};

calendar::calendar(const calendar &src) : dateHead(NULL)
{
	if (!src.dateHead)
		return;
	dateNode *datePtr = src.dateHead;
	while (datePtr)
	{
		eventNode *eventPtr = datePtr->eventHead;
		while (eventPtr)
		{
			create_event(eventPtr->_event, datePtr->_date);
			eventPtr = eventPtr->next;
		}
		datePtr = datePtr->next;
	}
}

/*Вывод в файл*/
/*МЕНЯЛОСЬ!*/
void calendar::output_to_file(std::string filename)
{
	std::ofstream f;
	f.open(filename);
	dateNode *datePtr = dateHead;
	time_event a;
	while (datePtr)
	{
		eventNode *eventPtr = datePtr->eventHead;
		while (eventPtr)
		{
			f << datePtr->_date << "; ";
			a = eventPtr->_event.get_start_time();
			f << a.get_time() << " - ";
			a = eventPtr->_event.get_end_time();
			f << a.get_time() << "; ";
			f << eventPtr->_event.get_name() << "; ";
			if (eventPtr->next || datePtr->next)
			{
				f << std::endl;
			}
			eventPtr = eventPtr->next;
		}
		datePtr = datePtr->next;
	}
	f.close();
}

/*МЕНЯЛОСЬ!*/
void calendar::show_all_events()
{
	dateNode *datePtr = dateHead;
	while (datePtr)
	{
		eventNode *eventPtr = datePtr->eventHead;
		while (eventPtr)
		{
			std::cout << "дата: " << datePtr->_date << " | время: ";
			eventPtr->_event.show_event_info();
			std::cout << std::endl;
			eventPtr = eventPtr->next;
		}
		datePtr = datePtr->next;
	}
}



void calendar::create_event(event src_event, date src_date)
{
	//Если календарь пуст:
	if (!dateHead)
	{
		dateHead = new dateNode;
		dateHead->_date = src_date;
		dateHead->eventHead = new eventNode;
		dateHead->eventHead->_event = src_event;
		return;
	}
	//Если не пуст, просматриваем все имеющиеся даты
	dateNode *datePtr = dateHead;
	while (datePtr)
	{
		if (datePtr->_date == src_date) //Если в календаре нашлась такая дата, то в её список нужно вставить новое
		{
			eventNode *eventPtr = datePtr->eventHead;
				//Если событие назначено на ранее время, чем самое раннее, вставляем перед ним
				if (src_event.get_start_time() < eventPtr->_event.get_start_time())
				{
					eventPtr = new eventNode;
					eventPtr->_event = src_event;
					eventPtr->next = datePtr->eventHead;
					datePtr->eventHead = eventPtr;
					return;
				}
			//Если нет: ищем то событие, после которого нужно вставить
			while (eventPtr->next && (eventPtr->next->_event.get_start_time() < src_event.get_start_time()))
				eventPtr = eventPtr->next;
			//Вставляем после него
			eventNode *eventTmpPtr = eventPtr->next;
			eventPtr->next = new eventNode;
			eventPtr->next->_event = src_event;
			eventPtr->next->next = eventTmpPtr;
			return;
		}
		datePtr = datePtr->next;
	}
	//Если в календаре НЕ нашлось уже существующей даты:
	//Если назначенная дата раньше самой ранней, вставляем перед ней
	if (src_date < dateHead->_date)
	{
		datePtr = new dateNode;
		datePtr->_date = src_date;
		datePtr->eventHead = new eventNode;
		datePtr->eventHead->_event = src_event;
		datePtr->next = dateHead;
		dateHead = datePtr;
		return;
	}
	//Иначе ищем после какой даты необходимо вставить нашу
	datePtr = dateHead;
	while (datePtr->next && (datePtr->next->_date < src_date))
		datePtr = datePtr->next;
	//Вставляем после неё
	dateNode *dateTmpPtr = datePtr->next;
	datePtr->next = new dateNode;
	datePtr->next->_date = src_date;
	datePtr->next->eventHead = new eventNode;
	datePtr->next->eventHead->_event = src_event;
	datePtr->next->next = dateTmpPtr;
	return;
}

void calendar::show_date(date src_date)
{
	dateNode *datePtr = dateHead;
	while (datePtr)
	{
		if (datePtr->_date == src_date)
		{
			eventNode *eventPtr = datePtr->eventHead;
			while (eventPtr)
			{
				eventPtr->_event.show_event_info();
				std::cout << std::endl;
				eventPtr = eventPtr->next;
			}
			return;
		}
		datePtr = datePtr->next;
	}
	return;
}

bool calendar::check_date(date src_date)
{
	dateNode *datePtr = dateHead;
	while (datePtr)
	{
		if (datePtr->_date == src_date)
			return 1;
		datePtr = datePtr->next;
	}
	return 0;
}

void calendar::show_all_dates(int flag)
{
	dateNode *datePtr = dateHead;
	while (datePtr)
	{
		datePtr->_date.show_date(flag);
		std::cout << std::endl;
		datePtr = datePtr->next;
	}
	return;
}