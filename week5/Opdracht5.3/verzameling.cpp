//#include "verzameling.hpp"
//
//void verzameling::add(int n){
//	int validItems =0;
//	for(int i=0; i < 10; i++){
//		if(dataSet[i] != 0){validItems++;}
//		}
//	if(validItems != 10 && !contains(n)){dataSet[validItems+1] = n;} 
//}
//
//void verzameling::remove(int n){
//	int indexValue = 0;
//	if(contains(n)){
//		for(int i =0; i < 10; i++){
//			if(dataSet[i] == n){
//				dataSet[indexValue] =0;
//				break;
//			}
//			else{indexValue++;}
//		}
//	}
//}
//
//bool verzameling::contains(int n){
//	for(int i =0; i < 10; i++){
//		if(dataSet[i] == n){return true;}
//	}
//	return false;
//}
//
//std::ostream& operator<<(std::ostream & output, const std::array<int,10>& dataSet){
//	output << '[';
//	for(int i=0; i<10; i++){
//		output <<dataSet[i];
//		if(i != 10){output << ',';}
//	}
//	output<<"]\n";
//	return output;
//}