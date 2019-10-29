//Written by dylan griffioen
//contains functions for a class used to keep calculate the time by using hwlib::now_us()



#include "hwlib.hpp"
#include "current_time.hpp"


int current_time::get_seconds(){
	return seconds;
};

int current_time::get_minutes(){
	return minutes;
};

int current_time::get_hours(){
	return hours;
};

/*
function used to increase add_hours
add_hours is added to hours in order to set the current time
*/
void current_time::add_hour(){
	add_hours++;
};

/*
function used to increase add_minutes
add_minutes is added to minutes in order to set the current time
*/
void current_time::add_minute(){
	add_minutes++;
};

/*
updates the time variables stored in the class to the current time
now_us gives us the time in us that has passed since it's initial use in our case right before the loop starts
then it devides time_us by 1'000'000 to turn it into time_s since seconds are easier to work with

keep in mind that it's not possible to reset now_us()
add_minutes and add_hours are added to minutes and hours to allow the user to set the current time

for seconds:
	seconds is time_s modulo 60 to keep it from going above 60 seconds

for minutes:
	time_s is devided by 60 to turn it into minutes and add_minutes is added to that
	then modulo 60 is used to keep it from going over 60 minutes

for hours:
	add_minutes is multiplied by 60 to turn it into seconds and combined with time_s
	this combination get's devided by 3600 to turn it into hours and add_hours get's added to that
	then modulo 12 get's applied to ensure that hours do not go above 12
*/
void current_time::update_time(){
	unsigned int time_us = hwlib::now_us();
	unsigned int time_s = (time_us / 1'000'000);
	seconds = (time_s % 60);
	minutes =  ((add_minutes + (time_s / 60)) % 60);
	hours = ((add_hours + ((time_s + (add_minutes * 60)) / 3600)) % 12);
};