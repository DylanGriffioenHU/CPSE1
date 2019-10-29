//written by Dylan Griffioen
//tests for opdracht5.1  


#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include <ostream>
#include "set.hpp"
#include <catch2/catch.hpp>

//Test adding ints to the array
//This test will add a bunch of ints to the array and then checks if they are actually in the array
//It also prints the array so that you can check it for yourself
TEST_CASE( "set, add(), contains" ){
	set list;
	list.add( 1 );
	list.add( 2 );
	list.add( 3 );
	list.add( 4 );
	list.add( 5 );
	list.add( 5 ); //checks if a value won't get added twice
	list.add( 6 );
	list.add( 7 );
	list.add( 8 );
	list.add( 9 );
	list.add( 10 );
	list.add( 11 ); //checks if the add function protects against overloading
	std::cout << list << std::endl;
	REQUIRE( list.contains(1) == true );   
	REQUIRE( list.contains(2) == true );   
	REQUIRE( list.contains(3) == true );   
	REQUIRE( list.contains(4) == true );   
	REQUIRE( list.contains(5) == true );    
	REQUIRE( list.contains(6) == true );    
	REQUIRE( list.contains(7) == true );    
	REQUIRE( list.contains(8) == true );    
	REQUIRE( list.contains(9) == true );    
	REQUIRE( list.contains(10) == true );    
	REQUIRE( list.contains(11) == false );    
}

//Tests removing an int from the array
//This test wil first fill the array with ints and then remove one
//Then it will check if the removed value isn't in the array while the others are
//It also prints the array so you can check it yourself
TEST_CASE( "set, remove(), contains()" ){
	set list;
	list.add( 5 );
	list.add( 5 );
	list.add( 6 );
	list.add( 7 );
	list.add( 8 );
	list.add( 9 );
	list.remove( 5 );
	std::cout << list << std::endl;
	REQUIRE( list.contains(5) == false ); 
	REQUIRE( list.contains(6) == true );
	REQUIRE( list.contains(7) == true );   
	REQUIRE( list.contains(8) == true );   
	REQUIRE( list.contains(9) == true );      
}