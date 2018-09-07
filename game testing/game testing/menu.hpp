//
//  menu.hpp
//  game testing
//
//  Created by Ahmad Refaat on 4/22/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include "entity.hpp"
#include "Game.hpp"
#include "player.hpp"
#include "tiles.hpp"
#include "music.hpp"

class menu: public entity {
    
    
    
public:
    
    menu(int,int);
    void getName(Event&,int&,RenderWindow&,Time,Clock&);
    void mainMenu(int&,RectangleShape,RenderWindow&,int&,Sprite&,Clock&,music& );
    string returnName();
	void options(int&, int&, RenderWindow&, Sprite&,Clock&);
	void diffuculty(RenderWindow&, int&, int&, int&,Clock&,string&);
	void volume(RenderWindow&, int&, int&, music&,Clock&);
	void nightmode(RenderWindow&, int&, int&,Clock&);
    bool nighty = false;
	void selectlevel(RenderWindow&, int&, int&, int, int&, RectangleShape, string&,Clock& clock);
	void back1(RenderWindow&, int&, RectangleShape, bool&);
   private:
    
    int previous=0;
    int current=1 ;
	int state = 0;
    
    RectangleShape startRectangle;
    RectangleShape highScoresRectangle;
    RectangleShape optionsRectangle;
    
    RectangleShape nxt;
    RectangleShape back;
    
    string nameS;
    
    Text enter;
    Text name1;
    Text startT;
    Text highT;
    Text nxtT;
    Text backT;
    
    Sprite startButton ;
    Sprite optionsButton ;
    Sprite highScoresButton ;
   
    Texture optionsTexture ;
    Texture startTexture ;
    Texture highScoresTexture ;
    
    
    Sprite backgroundSprite;
    Texture backgroundTexture ;
   
       
    Clock clock1;
    Time elapsed;
    
    int counter=0 ;
    int counter2= 0;

	int y2; bool flag = false;
};




#endif /* menu_hpp */
