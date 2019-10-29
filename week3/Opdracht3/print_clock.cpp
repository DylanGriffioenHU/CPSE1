//written by Dylan Griffioen
//Contains a function for the print_clock template that calculates the angles the hour hand, minute hand and second hand should be at


#include "hwlib.hpp"
#include "print_clock.hpp"


/*this function calculates the angles the hour hand, minute hand and second hand should be at
seconds get multiplied by 6 and that value get's subtracted from 360
minutes get multiplied by 6 and that value get's subtracted from 360
hours get multiplied by 30, this get's combined with minutes multiplied by 0.5 and that combination gets subtracted from 360
the reason everything get's subtracted from 360 is to ensure the the clock going clockwise
*/
void print_clock::update_angles(const int & seconds, const int & minutes, const int & hours){
	seconds_angle = 360 - (seconds * 6);
	minutes_angle = 360 - (minutes * 6);
	hours_angle = (360 - ((hours * 30) + (minutes * 0.5)));
};