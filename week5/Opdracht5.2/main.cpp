//Written by Dylan Griffioen
//contains tests for opdracht5.2

#include "set.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>


/*
Tests adding ints to an int array
It will add a bunch of ints to the array and then checks if they are actually added
It also prints the array so you can see for yourself if everything is the way it should be
*/
TEST_CASE( "Test adding ints to an int array" ){
	set<int,12> vI;
	vI.add(33);
	vI.add(10000);
	vI.add(129);
	vI.add(689);
	vI.add(700);
	std::cout << vI<< std::endl;
	REQUIRE( vI.contains(33) == true);   
	REQUIRE( vI.contains(10000) == true);   
	REQUIRE( vI.contains(129) == true);   
	REQUIRE( vI.contains(689) == true);   
	REQUIRE( vI.contains(700) == true);   
}

/*
Tests adding removing an int from int array
It fills the array with ints
Then it removes one of them and checks if every int but the one that got removed is in the array
It also prints the array so you can see for yourself if everything is the way it should be
*/
TEST_CASE( "Tests removing int from int array" ){
	set<int,12> vI2;
	vI2.add(33);
	vI2.add(10000);
	vI2.add(129);
	vI2.add(689);
	vI2.add(700);
	vI2.remove(10000);
	std::cout << vI2<< std::endl;
	REQUIRE( vI2.contains(33) == true);   
	REQUIRE( vI2.contains(10000) == false);   
	REQUIRE( vI2.contains(129) == true);   
	REQUIRE( vI2.contains(689) == true);   
	REQUIRE( vI2.contains(700) == true);   
}


/*
Tests adding floats to an float array
It will add a bunch of floats to the array and then checks if they are actually added
It also prints the array so you can see for yourself if everything is the way it should be
*/
TEST_CASE("c"){
	set<float,5> vF;
	vF.add(2.2);
	vF.add(669.0);
	vF.add(33.3);
	vF.add(88.22);
	vF.add(9.00);
	vF.add(55.6); //overflow array to test if add() shields against out of bounds
	std::cout << vF << std::endl;
	REQUIRE(vF.contains(2.2) == true);
	REQUIRE(vF.contains(669.0) == true);
	REQUIRE(vF.contains(33.3) == true);
	REQUIRE(vF.contains(88.22) == true);
	REQUIRE(vF.contains(9.00) == true);
	REQUIRE(vF.contains(55.6) == false);
}

/*
Tests adding chars to an chars array
It will add a bunch of chars to the array and then checks if they are actually added
It also prints the array so you can see for yourself if everything is the way it should be
*/
TEST_CASE("check max from char array"){
	set<char,3> vC;
	vC.add('a');
	vC.add('G');
	vC.add('z');
	std::cout << vC << std::endl;
	REQUIRE(vC.contains('a') == true);
	REQUIRE(vC.contains('G') == true);
	REQUIRE(vC.contains('z') == true);
}

