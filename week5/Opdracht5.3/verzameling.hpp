#ifndef _VERZAMELING_H
#define _VERZAMELING_H
#include "iostream"
#include "array"

template <typename T, unsigned int size>
class verzameling{
private : 
	std::array<T,size> dataSet = {};
	int validItems =0;
	T maximum = 0;
public:
	
	T setMax(){
		maximum = dataSet[0];
		for(unsigned int i=0; i < size; i++){
			if(maximum < dataSet[i]){maximum = dataSet[i];}
		}
		return maximum;
	}

	/* 
	function that adds a value to the array 
	by first checking how many valid items it 
	has(not 0) after it checks it the array
	is not already full or already contains the element
	if this passes the value is added at position of the
	valid items + 1 so it wont write over any values 
	*/  
	void add(T n){
			if(validItems != size && !contains(n)){dataSet[validItems] = n; validItems++;} 
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
	void remove(T n){
		int indexValue = 0;
		if(contains(n)){
			for(unsigned int i =0; i < size; i++){
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
	bool contains(T n){
		for(unsigned int i =0; i < size; i++){
			if(dataSet[i] == n){return true;}
		}
		return false;
	}

	template<typename S, unsigned int N>
	friend std::ostream& operator<<(std::ostream & output, const verzameling<S,N> & set);

};

	/*
	Operator that takes in the array formats it
	and than loops trough every value adding it
	to output upon completion it will return
	output so it will be printed
	*/
template<typename S, unsigned int N>
std::ostream& operator<<(std::ostream & output, const verzameling<S,N> & set){
			output << "[";
		for(size_t i=0; i< N; i++){
			output <<set.dataSet[i];
			if(i != N-1){output << ",";}
		}
		output<<"]\n";
		return output;
}
#endif