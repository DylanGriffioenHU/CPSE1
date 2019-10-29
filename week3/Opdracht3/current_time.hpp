//written by Dylan griffioen
//contains a class used to keep the current time by using hwlib::now_us()


#ifndef _CURRENT_TIME_HPP
#define _CURRENT_TIME_HPP

/*
class used to calculate and keep track of the current_time the clock should be at
It calculates the time using now_us which returns how much time has passed in us since the function was first called
*/
class current_time{
private:
	int  seconds = 0;
	int  minutes = 0;
	int  hours = 0;
	int  add_hours = 0;
	int  add_minutes = 0;
public:

	current_time(){}
	
	int get_seconds();	
	int get_minutes();	
	int get_hours();
	void add_hour();	
	void add_minute();	
	void update_time();
};


#endif
