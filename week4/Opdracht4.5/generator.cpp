//written by Dylan Griffioen
//contains a compressor and decompressor
//compresses both to a txt and asm file



#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 

int main( void ){	
	lz_compressor< 4096 > compressor;

	std::ifstream f1;
	f1.open( "wilhelmus.txt" );
	if( ! f1.is_open()){
		std::cerr << "input file not opened";
		return -1;      
	}

	std::ofstream f2;
	f2.open( "compressed.txt" );
	if( ! f2.is_open()){
		std::cerr << "output file not opened 1\n";
		return -1;      
	}
	   
	std::ofstream f3;
	f3.open( "asmCompressed.asm" );
	if( ! f3.is_open()){
	  std::cerr << "output file not opened 2\n";
	  return -1;
	}
	
	f3 << ".cpu cortex-m0 \n";
	f3 << ".align 2 \n";
	f3 << ".text \n";
	f3 << ".global compressed \n \n";
	f3 << "compressed: .asciz \"";

	compressor.compress( 
		[ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
		[ &f2, &f3 ]( char c ){ f2.put( c ); f3.put(c);}
	);

	f3 << "\"";

	f1.close();
	f2.close();
	f3.close();

//	f1.open( "compressed.txt" );
//	if( ! f1.is_open()){
//		std::cerr << "compressed file not opened";
//		return -1;      
//	}   
//
//	lz_decompressor decompressor;
//	decompressor.decompress( 
//		[ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
//		[ &f2 ]( char c ){ std::cout << c; }
//	);
}