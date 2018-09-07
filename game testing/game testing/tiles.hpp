//
//  tiles.hpp
//  game testing
//
//  Created by Ahmad Refaat on 4/21/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#ifndef tiles_hpp
#define tiles_hpp

#include <stdio.h>
#include "entity.hpp"
using namespace sf;

class tiles // :public entity {
{
    
public:
    
    
    tiles();
    void setType(int,int);
    void setPos(int,int,int,int);
    Sprite getSprite();
    void setTheme(int);
    
private:
  
    
    int xSize=64;
    int ySize=64;
    Texture box ;
    Texture back;
    Texture wall ;
    Texture white ;
    Texture boxG ;
	Texture goal;
    Sprite mySprite ;
    RectangleShape myRect ;
    
    
};

#endif /* tiles_hpp */
