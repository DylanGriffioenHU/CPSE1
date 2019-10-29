//written by Dylan Griffioen
//contains an array class


#ifndef _LIST_HPP
#define _LIST_HPP

#include <iostream>
#include <array>

class set{
private:
	std::array<int, 10> data = {};
	int used = 0;
public:
	set(){};

	void add( int n );
	void remove(int n);
	bool contains( int n);
	
	friend std::ostream & operator <<( std::ostream & lhs, const set & rhs ){
		lhs << '[';
		for (int i = 0; i < rhs.used; i++){
        	lhs <<rhs.data[i];
			if(i != rhs.used-1){lhs << ",";}
		}
		lhs << ']';
		return lhs;
	}
};
#endif 