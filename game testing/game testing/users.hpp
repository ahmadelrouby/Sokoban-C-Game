//
//  users.hpp
//  game testing
//
//  Created by Ahmad Refaat on 4/22/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#ifndef users_hpp
#define users_hpp

#include <stdio.h>
#include "entity.hpp"
#include <string>
#include <fstream>
using namespace sf;
class users: public entity{
    
public:
    
    
    users(int,int);
    void userMenu(RenderWindow&);
    void createAccount(Event& event,int& n,RenderWindow& window,Time elapsed1,Clock& clock2,RectangleShape,int&);
    void login(Event& event,int& n,RenderWindow& window,Time elapsed1,Clock& clock2,RectangleShape,int&);
    string returnName();
    void addAccount(string,string);
    void loginMenu(int&,RectangleShape,RenderWindow&,int&,Sprite&,Text&);
private:
    
    int myX ,myY;
    bool logged=false ;
    bool flag=false ;
    string userName,Password ;
    string user,pass;
    int type=0 ;
    string temp;
    Text enter;
    Text name1;
    bool newLine = false ;
    string encryptDecrypt(string toEncrypt);
    string name ; 
    Text passwordEnter , passwordText ;
    RectangleShape loginR;
    Text loginWord;
    
    Text signMenu ;
    Text RegisterMenu;
    
    RectangleShape signRectangle;
    RectangleShape registerRectangle;
    
    Text createAcc ;
    
    Sprite backgroundSprite;
    
    Texture backgroundTexture ;

    
    
    Sprite loginButton ;
    Sprite createButton ;
    Sprite registerButton ;
    
    Texture loginTexture ;
    Texture createTexture ;
    Texture registerTexture;
    
    
};


#endif /* users_hpp */
