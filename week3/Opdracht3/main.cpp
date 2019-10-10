#include <array>
#include "hwlib.hpp"
#include <math.h>
#include <chrono>
#include <ctime>    

//constexpr double pow( double g, int n ){
//   double result = 1;
//   while( n > 0 ){
//       result *= g;
//       --n;
//   }
//   return result;
//}
//
//constexpr double fac( int n ){
//   double result = 1;
//   while( n > 0 ){
//       result *= n;
//       --n;
//   }
//   return result;
//}
//
//constexpr double sin( double a ){
//   return 
//      a 
//      - pow( a, 3 ) / fac( 3 ) 
//      + pow( a, 5 ) / fac( 5 ) 
//      - pow( a, 7 ) / fac( 7 )
//      + pow( a, 9 ) / fac( 9 ) 
//      - pow( a, 11 ) / fac( 11 ) 
//      + pow( a, 13 ) / fac( 13 );
//}

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

template< int N, typename T >
class lookup {
private:    
   std::array< T, N > values = {};

public: 

   template< typename F >
   constexpr lookup( F function ){
      for( int i = 0; i < N; ++i ){
          values[ i ] = function( 10 * i );
      }
   }

   constexpr T get( int n ) const {
      return values[ n / 10 ];    
   }
};

int main( void ){

	namespace target = hwlib::target;
	

	auto scl = target::pin_oc( target::pins::scl );
	auto sda = target::pin_oc( target::pins::sda );

	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );

	auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  

	constexpr auto sinusses = lookup< 360, int >( scaled_sine_from_degrees );
	constexpr auto cosinusses = lookup< 360, int >( scaled_cosine_from_degrees );

	for(;;){
		display.clear();
		int time_us = hwlib::now_us();
		int time_s = (time_us / 1'000'000);
		int seconds = (time_s % 60);
		int minutes =  ((59 +(time_s / 60)) % 60);
		int hours = ((10 + (3540 + time_s) / 3600) % 12);
		
		int seconds_angle = 360 - (seconds * 6);
		int minutes_angle = 360 - (minutes * 6);
		int hours_angle = ((360 - (hours * 30) - (minutes * 0.5)));
		
		
		hwlib::cout << hours << " : " << minutes << " : " << seconds << hwlib::endl;
		for( int j = 0; j <= 360; j += 30 ){
			display.write( hwlib::xy( sinusses.get(j), cosinusses.get(j) ) );
		}
		hwlib::line(hwlib::xy( 64, 31.5 ), hwlib::xy( sinusses.get(hours_angle),   cosinusses.get(hours_angle))).draw( display );
		hwlib::line(hwlib::xy( 64, 31.5 ), hwlib::xy( sinusses.get(minutes_angle),   cosinusses.get(minutes_angle))).draw( display );
		hwlib::line(hwlib::xy( 64, 31.5 ), hwlib::xy( sinusses.get(seconds_angle),   cosinusses.get(seconds_angle))).draw( display );
		display.flush();
	}
}