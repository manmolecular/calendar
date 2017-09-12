#pragma once
#include "date.h"
#include "event.h"

class calendar
{
private:
	struct eventNode
	{
		event _event;
		eventNode *next = NULL;
	};
	struct dateNode
	{
		date _date;
		eventNode *eventHead = NULL;
		dateNode *next = NULL;
	};
	dateNode *dateHead;
public:
	calendar();
	calendar(const calendar &src);
	void show_all_events();
	void create_event(event, date);
	void show_date(date);
	bool check_date(date);
	void show_all_dates(int flag = 4);
	void output_to_file(std::string filename);
};