//
//  music.cpp
//  game testing
//
//  Created by Ahmad Refaat on 5/9/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#include "music.hpp"


music::music(){
    
    cout << "loaded music correctly" << endl ;
    
}



void music::backgroundmusic()
{
    if (!musica.openFromFile(resourcePath()+"backMusic1.ogg"))
        cout << "error";
    musica.setLoop(true);
    musica.setVolume(50);

    musica.play();
    
   
}
void music::walking()
{
    if (!movebuffer.loadFromFile(resourcePath()+"Walking_Fast_on_Tile_[SOUND_EFFECT_1_-_Part.wav"))
        cout<<"error in walking";
    
    movesound.setBuffer(movebuffer);
    while (movesound.getStatus() == sf::Sound::Playing)
        sleep(milliseconds(100));
    movesound.setLoop(false);
    movesound.play();
	movesound.setVolume(volume);
}
void music::moveBox()
{
    if (!moveBoxbuffer.loadFromFile(resourcePath()+"Sound_Effects_Foley_Movements_Box_Slide_On_Cement_.wav"))
        cout << "error in walking";
    moveBoxsound.setBuffer(moveBoxbuffer);
   // while (sound.getStatus() == sf::Sound::Playing)
     //   sleep(milliseconds(100));
    //sound.setLoop(false);
    moveBoxsound.play();
	moveBoxsound.setVolume(volume);
}
void music::lose()
{
    if (!buffer.loadFromFile(resourcePath()+"Epic_Fail_Sound_Effects_-_Part.wav"))
        cout << "error in walking";
    
    sound.setBuffer(buffer);
    while (sound.getStatus() == sf::Sound::Playing)
        sleep(milliseconds(100));
    sound.setLoop(false);
    sound.play();
	sound.setVolume(volume);
}
void music::levelUp()
{
    if (!buffer.loadFromFile(resourcePath()+"Epic_Win_Sound_Effects_-_Part.wav"))
        cout << "error in walking";
    sound.setBuffer(buffer);
    while (sound.getStatus() == sf::Sound::Playing)
        sleep(milliseconds(100));
    sound.setLoop(false);
    sound.play();
	sound.setVolume(volume);
}
void music::inplace()
{
    if (!inPlacebuffer.loadFromFile(resourcePath()+"Correct_Answer_Button_Sound_Effect_1_-_Part.wav"))
        cout << "error in walking";
    inPlacesound.setBuffer(inPlacebuffer);
   // while (sound.getStatus() == sf::Sound::Playing)
     //   sleep(milliseconds(100));
    //sound.setLoop(false);
    inPlacesound.play();
	inPlacesound.setVolume(volume);
}
void music::typing()
{
    if (!typingBuffer.loadFromFile(resourcePath()+"type.wav"))
        cout << "error in walking";
    typingSound.setBuffer(typingBuffer);
    // while (sound.getStatus() == sf::Sound::Playing)
    //   sleep(milliseconds(100));
    //sound.setLoop(false);
    typingSound.play();
	typingSound.setVolume(volume);
}
void music::button()
{
    if (!buttonBuffer.loadFromFile(resourcePath()+"mouseB.wav"))
        cout << "error in walking";
    buttonSound.setBuffer(buttonBuffer);
     while (buttonSound.getStatus() == sf::Sound::Playing)
       sleep(milliseconds(100));
    buttonSound.setLoop(false);
    buttonSound.play();
	buttonSound.setVolume(volume);
}

bool music::stillPlaying(){
    
    if(buttonSound.getStatus() == sf::Sound::Playing)
        return true;
    
    return false ;
}
void music::setVolume(int x)
{

    volume = x;
    musica.setVolume(volume/2.0);
//    if(volume-70>0)
//        musica.setVolume(volume-70);
//    else
//        musica.setVolume(0);

}

