#pragma once
#include <string>
#include "time_event.h"

class eventException
{
private:
	std::string errmsg;
public:
	eventException(std::string msg = "") : errmsg(msg) {};
};

class event
{
private:
	std::string name;
	time_event start_time, end_time;
public:
	event(std::string _name = "NONAME");
	event(time_event, std::string  _name = "NONAME");
	event(time_event, time_event, std::string _name = "NONAME");
	event(const event &src);
	void set_name(std::string);
	void show_name();
	void show_event_info();           // hh1:mm1:ss1 - hh2:mm2:ss2: name
	std::string get_event_info();     // return "hh1:mm1:ss1 - hh2:mm2:ss2: name"
	std::string get_name();
	void show_start_time();           // hh:mm:ss
	void show_end_time();
	void change_start_time(time_event);
	void change_end_time(time_event);
	void change_time(time_event, time_event);
	void show_duration();             // hh:mm:ss
	time_event get_duration();
	time_event get_start_time();
	time_event get_end_time();
};