#include "hwlib.hpp"
#include "note_player_native.hpp"

  
void note_player_native::play( const note & n ){
   if( n.frequency != 0 ){
        hwlib::cout << "Frequency: " << n.frequency << " Duration: " << n.duration << hwlib::endl;
   }    
}
