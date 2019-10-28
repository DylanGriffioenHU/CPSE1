#include "verzameling.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
//Written by Ramon Petri 

/*
Test the max value in a int array
This test first fills the array with values
After it test if the setMax function
returns the maximum value in the array
wich is 10000
*/
TEST_CASE( "check max from int array" ){
	verzameling<int,12> vI;
	vI.add(33);
	vI.add(10000);
	vI.add(129);
	vI.add(689);
	vI.add(700);
	REQUIRE( vI.setMax() == 10000);   
}

/*
Test the max value in a float array
This test first fills the array with values
After it test if the setMax function
returns the maximum value in the array
wich is 669.0
*/
TEST_CASE("check max from float array"){
	verzameling<float,5> vF;
	vF.add(2.2);
	vF.add(669.0);
	vF.add(33.3);
	vF.add(88.22);
	vF.add(9.00);
	vF.add(55.6); //overflow array to test if add() shields against out of bounds
	REQUIRE(vF.setMax() == 669.0);
}

/*
Test the max value in a char array
This test first fill the array with values
After it test if the setMax function
returns the maximum value in the array
*/
TEST_CASE("check max from char array"){
	verzameling<char,3> vC;
	vC.add('a');
	vC.add('G');
	vC.add('z');
	REQUIRE(vC.setMax() == 'z');
}

