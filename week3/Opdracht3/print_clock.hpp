#ifndef _PRINT_CLOCK_HPP
#define _PRINT_CLOCK_HPP


//class used to print the clock
//it also calculates the angles for the hour hand, minute hand and second hand
class print_clock {
private:
	int       	seconds_angle = 360;
	int			minutes_angle = 360;
	int			hours_angle   = 360;
	hwlib::xy	clock_xy;
public:
	print_clock(hwlib::xy & clock_xy):
		clock_xy(clock_xy)
	{}
	
	void update_angles(const int & seconds, const int & minutes, const int & hours);
	
	
	//prints the actual clock
	//the circle is drawn by getting the x and y coordinates from the sinusses and cosinusses arrays with increments of 30
	//the lines are drawn in a simular way but it uses the middle point of the circle(clock_xy) for one end
	//and gets it's xy data for the other end from the sinusses and cosinusses arrays by using the corresponding angle
	void print(auto & display, const auto & sinusses, const auto & cosinusses){
		display.clear();
		for( int j = 0; j <= 360; j += 30 ){
			display.write( hwlib::xy( sinusses.get(j), cosinusses.get(j) ) );
		}
		hwlib::line(clock_xy, hwlib::xy( sinusses.get(hours_angle),   cosinusses.get(hours_angle))).draw( display );
		hwlib::line(clock_xy, hwlib::xy( sinusses.get(minutes_angle),   cosinusses.get(minutes_angle))).draw( display );
		hwlib::line(clock_xy, hwlib::xy( sinusses.get(seconds_angle),   cosinusses.get(seconds_angle))).draw( display );
		display.flush();
	};
};


#endif
