#include "hwlib.hpp"

extern "C" {
	void decoder();
	void uart_put_char( char c ){hwlib::cout << c;}
}

int main( void ){
   hwlib::wait_ms(100);
   decoder();
}
