#ifndef _VERZAMELING_H
#define _VERZAMELING_H
#include "iostream"
#include "array"
class verzameling {
	private:
		std::array<int,10> dataSet = {};
	public:
		void add(int n);
		void remove(int n);
		bool contains(int n);
};
#endif