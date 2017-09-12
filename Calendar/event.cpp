#include "event.h"

/*
********
Блок Алихана
*******
*/

event::event(std::string _name): name(_name), start_time(), end_time() {}

event::event(time_event _time, std::string _name): start_time(_time), end_time(_time), name(_name) {}

event::event(time_event _start_time, time_event _end_time, std::string _name): name(_name)
{
	if(_start_time <= _end_time)
	{
		start_time = _start_time;
		end_time   = _end_time;
	}
	else
		throw eventException("eventException: end time is earlier than start time");

    return;
}

event::event(const event &src) : name(src.name), start_time(src.start_time), end_time(src.end_time) {};

/*
********
Блок Владимира
********
*/

void event::set_name(std::string name_event)
{
	name = name_event;
	return;
}

void event::show_name()
{
	std::cout << name;
	return;
}

std::string event::get_name()
{
	return name;
}

void event::show_event_info()
{
	start_time.show_time();
	std::cout << " - ";
	end_time.show_time();
	std::cout << " | " << name;
	return;
}

std::string event::get_event_info()
{
	return start_time.get_time() + " - " + end_time.get_time() + ": " + name;
}

/*
********
Блок Дмитрия
********
*/

void event::show_start_time()
{
	start_time.show_time();
    return;
}

void event::show_end_time()
{
	end_time.show_time();
	return;
}

void event::change_start_time(time_event _start_time)
{
	if(_start_time > end_time)
		throw eventException("eventException: end time is earlier than start time");
	start_time = _start_time;
    return;
}

void event::change_end_time(time_event _end_time)
{
	if(_end_time < start_time)
		throw eventException("eventException: end time is earlier than start time");
	end_time = _end_time;
	return;
}

void event::change_time(time_event _start_time, time_event _end_time)
{
    if (_end_time < _start_time)
        throw eventException("eventException: end time is earlier than start time");
    end_time = _end_time;
    start_time = _start_time;
    return;
}

void event::show_duration()
{
	time_event a = end_time;
	a -= start_time;
	a.show_time();
	return;
}

time_event event::get_duration()
{
	time_event a = end_time;
   	a -= start_time;
	return a;
}

time_event event::get_start_time()
{
    return start_time;
}

time_event event::get_end_time()
{
    return end_time;
}