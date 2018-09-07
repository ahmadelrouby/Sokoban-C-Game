//
//  player.hpp
//  game testing
//
//  Created by Ahmad Refaat on 4/22/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "entity.hpp"
#include "Game.hpp"
#include "hints.hpp"
#include "music.hpp"

class player //: entity
{

public:
    entity entity1;
    player(game&);
	void updateMovement(int&, game&, hints&,music&);
    Sprite getPlayer();
    void updatelvlP(game&);
    void pickplayer(RenderWindow&,game& mygame, int& n , Time , Clock&,Sprite&);
    int xfactor=320;
    int yfactor=128;
    int xSize=64;
    int ySize=64;
private:
  
    
    sf::RectangleShape rect ;
    sf::Sprite sprite ;
    sf::Text text ;
    sf::Texture texture;
    sf::Font font;
    int speed = 64 ;
    int myI=128 , myJ=128 ;
    int direction=0 , oldDirection;
    Sprite walker;
    
     Sprite B1, B2, B3, B4, B5, bg,box1,bubble1;
    Texture b1, b2, b3, b4, b5, background, box, option1, option2, option3, option4, option5,bubble ;
	//Font font;
    int x = 130*2, y = 175*2,d=0*x,s=0;
    //int x = 100*2, y = 175*2,d=0*x,s=0;

    
    Sprite backgroundSprite;
    
    Texture backgroundTexture ;
    
};
#endif /* player_hpp */
