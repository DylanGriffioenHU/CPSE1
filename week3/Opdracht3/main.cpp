//written by dylan griffioen
//creates a clock using constexpr arrays with sine and cosine values
//keeps the time by using a current time class that updates itself based on hwlib::now_us()


#include <array>
#include "hwlib.hpp"
#include <math.h>
#include "lookup.hpp"
#include "current_time.hpp"
#include "print_clock.hpp"

//Get Radials from degrees
constexpr double radians_from_degrees( int degrees ){
   return 2 * 3.14 * ( degrees / 360.0 );
}

// Get the sines of the point
constexpr int scaled_sine_from_degrees( int degrees ){
    return 64 + ( 32 * sin( radians_from_degrees(degrees) ));
}

//Get the cosinus of the point
constexpr int scaled_cosine_from_degrees( int degrees ){
    return 31.5 + ( 32 * cos( radians_from_degrees(degrees)));
}


int main( void ){

	namespace target = hwlib::target;
	

	auto scl = target::pin_oc( target::pins::scl );
	auto sda = target::pin_oc( target::pins::sda );
	auto minutes_button = target::pin_in(target::pins::d7);
	auto hours_button = target::pin_in(target::pins::d6);

	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );

	auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  

	constexpr auto sinusses = lookup< 360, int >( scaled_sine_from_degrees );
	constexpr auto cosinusses = lookup< 360, int >( scaled_cosine_from_degrees );
	
	auto c_time = current_time();
	hwlib::xy clock_xy = hwlib::xy(64, 31.5);
	auto c_print = print_clock(clock_xy);
	
	hwlib::now_us();

	for(;;){
		c_time.update_time();
		
		int seconds = c_time.get_seconds();
		int minutes = c_time.get_minutes();
		int hours   = c_time.get_hours();
		
		hwlib::cout << hours << " : " << minutes << " : " << seconds << hwlib::endl;
		
		if(hours_button.read()){
			c_time.add_hour();
		}
		
		if(minutes_button.read()){
			c_time.add_minute();
		}
		
		c_print.update_angles(seconds,minutes,hours);
		c_print.print(display, sinusses, cosinusses);
	}
}