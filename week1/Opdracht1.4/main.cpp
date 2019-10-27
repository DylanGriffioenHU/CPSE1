//writen by: Dylan Griffioen
//Changes the uppercase letters to lowercase letters 
//And changes the lowercase letters to uppercase letters
//After that prints the string one character at a time
//Written on 17-9-2019

#include "hwlib.hpp"

extern "C" {
    
    void application();
        
    void print_asciz(const char *);
    
    void toggle_case( char c );

    void uart_put_char( char c ){
       hwlib::cout << c;
    }

    //If char c is lowercase the function makes it uppercase
    //If char c is uppercase the function makes it lowercase
    //And then it prints char c
//    void toggle_case( char c ){
//        if (c >= 'A' && c <= 'Z'){
//            c += 32;
//        } else if (c >= 'a' && c <= 'z'){
//            c -= 32;
//        }
//        uart_put_char( c );
//    }

    /*
    void print_asciz( const char * s ){
       while( *s != '\0'){
          uart_put_char( *s );
          ++s;
       }
    }
    */
  

//    void application(){
//       print_asciz( "Hello world\n" );	
//    }

}


int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}