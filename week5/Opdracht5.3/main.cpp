//written by Dylan Griffioen
//contains tests for Opdracht5.3


#include "set.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

/*
Test the max value function in an int array
First it fills the array with a bunch of ints
Then it tests if the max function actually returns the max value
Which in this case is 10000
It also prints the array and the max value so you can check it for yourself
*/
TEST_CASE( "check max from int array" ){
	set<int,12> vI;
	vI.add(33);
	vI.add(10000);
	vI.add(129);
	vI.add(689);
	vI.add(700);
	std::cout << vI<< std::endl;
	std::cout << vI.max()<< std::endl;
	REQUIRE( vI.max() == 10000);   
}

/*
Test the max value function in an float array
First it fills the array with a bunch of floats
Then it tests if the max function actually returns the max value
Which in this case is 669.0
It also prints the array and the max value so you can check it for yourself
*/
TEST_CASE("check max from float array"){
	set<float,5> vF;
	vF.add(2.2);
	vF.add(669.5);
	vF.add(33.3);
	vF.add(88.22);
	vF.add(9.00);
	vF.add(55.6); //overflow array to test if add() shields against out of bounds
	std::cout << vF<< std::endl;
	std::cout << vF.max()<< std::endl;
	REQUIRE(vF.max() == 669.5);
}

/*
Test the max value function in an char array
First it fills the array with a bunch of chars
Then it tests if the max function actually returns the max value
Which in this case is z
It also prints the array and the max value so you can check it for yourself
*/
TEST_CASE("check max from char array"){
	set<char,3> vC;
	vC.add('a');
	vC.add('G');
	vC.add('z');
	std::cout << vC<< std::endl;
	std::cout << vC.max()<< std::endl;
	REQUIRE(vC.max() == 'z');
}

