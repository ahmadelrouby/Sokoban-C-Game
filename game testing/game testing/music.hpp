//
//  music.hpp
//  game testing
//
//  Created by Ahmad Refaat on 5/9/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#ifndef music_hpp
#define music_hpp

#include <stdio.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include "ResourcePath.hpp"
using namespace std;
using namespace sf;


class music {
    
    
private:
    
    SoundBuffer buffer;
    
    Music musica;
    
    Sound sound;
    
    SoundBuffer inPlacebuffer;
    Sound inPlacesound;

    SoundBuffer moveBoxbuffer;
    Sound moveBoxsound;
   
    
    SoundBuffer movebuffer;
    Sound movesound;
    
    
    SoundBuffer buttonBuffer;
    Sound buttonSound;

    
    SoundBuffer typingBuffer;
    Sound typingSound;


public:
    
    music();
    void backgroundmusic();
    void walking();
    void moveBox();
    void lose();
    void levelUp();
    void inplace();
    void typing();
    void button();
    bool stillPlaying();
	void setVolume(int);
    int volume = 100;

    
};
#endif /* music_hpp */
