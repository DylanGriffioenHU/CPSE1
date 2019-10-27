#ifndef _NOTE_PLAYER_NATIVE_HPP
#define _NOTE_PLAYER_NATIVE_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note player for a speaker connected to a GPIO pin
//
// ===========================================================================

class note_player_native : public note_player {
public: 
   note_player_native(){}
   
   void play( const note & n ) override;
};

#endif
