//written by Dylan Griffioen
//contains a class used to store a constexpr array

#ifndef _LOOKUP_HPP
#define _LOOKUP_HPP



//class template used to store all the sine or cosine values for the clock using a constexpr array
template< int N, typename T >
class lookup {
private:    
   std::array< T, N > values = {};

public: 
	//fills the array with the results from the given function
	template< typename F >
	constexpr lookup( F function ){
	  for( int i = 0; i < N; ++i ){
		  values[ i ] = function( 10 * i );
	  }
	}

	//returns value's from the array
	constexpr T get( int n ) const {
	  return values[ n / 10 ];    
	}
};

#endif
