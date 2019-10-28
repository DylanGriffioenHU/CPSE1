#include "verzameling.hpp"

/* 
function that adds a value to the array 
by first checking how many valid items it 
has(not 0) after it checks it the array
is not already full or already contains the element
if this passes the value is added at position of the
valid items + 1 so it wont write over any values 
*/  
void verzameling::add(int n){
	int validItems =0;
	for(int i=0; i < 10; i++){
		if(dataSet[i] != 0){validItems++;}
		}
	if(validItems != 10 && !contains(n)){dataSet[validItems+1] = n;} 
}

/*
function that removes a value from the array by
first checking if the given value exists in the array.
If this passes than it will loop trough the array
looking for a values that machtes n. If n is 
found the element at the value of "indexValue" 
will be set to zero and the function will end.
If n is not found "indexValue" gets incremented 
*/
void verzameling::remove(int n){
	int indexValue = 0;
	if(contains(n)){
		for(int i =0; i < 10; i++){
			if(dataSet[i] == n){
				dataSet[indexValue] =0;
				break;
			}
			else{indexValue++;}
		}
	}
}

/*
function that checks element existance
The function will loop trough the array
looking for element n. If element n is found
it returns True. If n is not found it returns False
*/
bool verzameling::contains(int n){
	for(int i =0; i < 10; i++){
		if(dataSet[i] == n){return true;}
	}
	return false;
}

/*
Operator that takes in the array formats it
and than loops trough every value adding it
to output upon completion it will return
output so it will be printed
*/
std::ostream& operator<<(std::ostream & output, const std::array<int,10>& dataSet){
	output << '[';
	for(int i=0; i<10; i++){
		output <<dataSet[i];
		if(i != 10){output << ',';}
	}
	output<<"]\n";
	return output;
}