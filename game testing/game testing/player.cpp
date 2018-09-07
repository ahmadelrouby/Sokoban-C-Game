//
//  player.cpp
//  game testing
//
//  Created by Ahmad Refaat on 4/22/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#include "player.hpp"
#include "hints.hpp"
player::player(game& mygame){
    
    
    if (!texture.loadFromFile(resourcePath() + "4.png")) {
        return EXIT_FAILURE;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,xSize,ySize));
    sprite.setPosition(mygame.getP());
    
    
    
    
}

void player::pickplayer(RenderWindow& w,game& mygame ,int& n ,Time elapsed , Clock& clock1, Sprite& birdy)
{
    
    if (!b1.loadFromFile(resourcePath() + "B1.png", IntRect(0, 0, 64, 64)))
    {
        cout << "no";
    }
    if (!b2.loadFromFile(resourcePath() + "B2.png", IntRect(0, 0, 64, 64)))
    {
        cout << "no";
    }
    if (!b3.loadFromFile(resourcePath() + "B3.png", IntRect(0, 0, 64, 64)))
    {
        cout << "no";
    }
    if (!b4.loadFromFile(resourcePath() + "B4.png", IntRect(0, 0, 64, 64)))
    {
        cout << "no";
    }
    if (!b5.loadFromFile(resourcePath() + "B5.png", IntRect(0, 0, 64, 64)))
    {
        cout << "no";
    }
    if (!background.loadFromFile(resourcePath() + "background.png"))
    {
        cout << "no";
    }
    if (!box.loadFromFile(resourcePath() + "box1.png"))
    {
        cout << "no";
    }
    if (!option1.loadFromFile(resourcePath() + "1.png"))
    {
        cout << "no";
    }
    if (!option2.loadFromFile(resourcePath() + "2.png"))
    {
        cout << "no";
    }
    if (!option3.loadFromFile(resourcePath() + "3.png"))
    {
        cout << "no";
    }
    if (!option4.loadFromFile(resourcePath() + "4.png"))
    {
        cout << "no";
    }
    if (!option5.loadFromFile(resourcePath() + "5.png"))
    {
        cout << "no";
    }
	//if (!bubble.loadFromFile(resourcePath() + "bubble.png"))
	//{
	//	cout << "no";
	//}
	if (!font.loadFromFile(resourcePath() + "kan.ttf"))
	{
		cout << "no";
	}
	Text text;
    B1.setTexture(b1);
    B2.setTexture(b2);
    B3.setTexture(b3);
    B4.setTexture(b4);
    B5.setTexture(b5);
    box1.setTexture(box);
	//bubble1.setTexture(bubble);
	text.setFont(font);

    B1.setPosition(0 * x, y);
    B2.setPosition(1 * x, y);
    B3.setPosition(2 * x, y-3);
    B4.setPosition(3 * x, y);
    B5.setPosition(4 * x, y);
	birdy.setPosition(100, 100);
	//bubble1.setPosition(240, 30);
	box1.setPosition(d, y - 3);
	text.setPosition(380, 140);
	text.setCharacterSize(90);
	text.setColor(Color::Black);

	if (d == 0 * x)
		text.setString("nerdy girl?");
	else
	if (d == 1 * x)
		text.setString("The Hipster?");
	else
	if (d == 2 * x)
		text.setString("The Hunter?");
	else
	if (d == 3 * x)
		text.setString("The nerd?");
	else
	if (d == 4 * x)
		text.setString("The princess?");

    Event e;
    
    while (w.pollEvent(e))
    {
        if(elapsed.asSeconds()>=0.12){
            clock1.restart();
        switch (e.key.code)
        {
                
            case Keyboard::Right:
                d = d + x;
                if (d > 4 * x)
                    d = 0;
                break;
            case Keyboard::Left:
                d = d - x;
                if (d < 0)
                    d = 4 * x;
                break;
            case Keyboard::Return:
                s =1;
                if (d == 0 * x)
					texture.loadFromFile(resourcePath() + "1.png");
                else if (d==1*x)
					texture.loadFromFile(resourcePath() + "2.png");
                else if (d==2*x)
					texture.loadFromFile(resourcePath() + "3.png");
                else if (d==3*x)
					texture.loadFromFile(resourcePath() + "4.png");
                else if (d==4*x)
					texture.loadFromFile(resourcePath() + "5.png");
                n=1;
                break; 
            default:
                box1.move(0, 0); 
                break;
        }
        }
    }
   
        w.draw(bg);
        w.draw(B1);
        w.draw(B2);
        w.draw(B3);
        w.draw(B4);
        w.draw(B5);
        w.draw(box1);
		w.draw(birdy);
		//w.draw(bubble1);
		w.draw(text);
   
    
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(xSize*0,ySize*0,xSize,ySize));
    sprite.setPosition(mygame.getP());

    
}

void player::updateMovement(int& count, game& mygame, hints& k,music& mymusic) {
    

    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)&&mygame.checkDifference())
                {
                    cout <<"Undo"<<endl ;
                    mygame.undo(sprite, myI, myJ);
                    count++;
                    direction=oldDirection;
                    mygame.intlGame();
                    mygame.displayArray();
                }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mygame.displaySolution();
        
    }

    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&mygame.checkCol(sprite,-1,0))
    {
        mygame.copyArray();
        if(mygame.checkBox(sprite,-1,0,mymusic)){
          
        mymusic.walking();
        myI=(sprite.getPosition().x-xfactor)/xSize; myJ=(sprite.getPosition().y-yfactor)/ySize;
        oldDirection=direction;
        sprite.move(-speed, 0);
        direction=1;
        sprite.setTextureRect(IntRect(xSize*0,ySize*1,xSize,ySize));
        count--;
        mygame.movePlayer(myI, myJ, -1, 0);
		if (k.hint == true)
			k.x++;
        }
        else
            mygame.deleteArray();
//        mygame.displayArray();
//        cout << endl ;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&mygame.checkCol(sprite,1,0))
    {
        
        mygame.copyArray();
        if(mygame.checkBox(sprite,1,0,mymusic)){
           
        mymusic.walking();
        myI=(sprite.getPosition().x-xfactor)/xSize; myJ=(sprite.getPosition().y-yfactor)/ySize;
        oldDirection=direction;
        sprite.move(speed, 0);
        direction=2;
        sprite.setTextureRect(IntRect(xSize*0,ySize*2,xSize,ySize));
        count--;
        mygame.movePlayer(myI, myJ, 1, 0);
		if (k.hint == true)
			k.x++;
        }
        else
            mygame.deleteArray();
        
        //        mygame.displayArray();
//        cout << endl ;
    }
    
    
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&mygame.checkCol(sprite,0,-1))
    {
        mygame.copyArray();
        if(mygame.checkBox(sprite,0,-1,mymusic)){
           
        mymusic.walking();
        myI=(sprite.getPosition().x-xfactor)/xSize; myJ=(sprite.getPosition().y-yfactor)/ySize;
        oldDirection=direction;
        sprite.move(0, -speed);
        direction=3;
        sprite.setTextureRect(IntRect(xSize*0,ySize*3,xSize,ySize));
        count--;
        mygame.movePlayer(myI, myJ, 0, -1);
		if (k.hint == true)
			k.x++;
        }
        else
            mygame.deleteArray();
//        mygame.displayArray();
//        cout << endl ;
    }
    
    
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&mygame.checkCol(sprite,0,1))
    {
        mygame.copyArray();
        
        if(mygame.checkBox(sprite,0,1,mymusic)){
        
        mymusic.walking();
        myI=(sprite.getPosition().x-xfactor)/xSize; myJ=(sprite.getPosition().y-yfactor)/ySize;
        oldDirection=direction;
        sprite.move(0, speed);
        direction=4;
        sprite.setTextureRect(IntRect(xSize*0,ySize*0,xSize,ySize));
        count--;
        mygame.movePlayer(myI, myJ, 0, 1);
		if (k.hint == true)
			k.x++;
        }
        else
            mygame.deleteArray();
//        mygame.displayArray();
//        cout << endl ;
    }
    
    
//    if(mygame.boxPushed)
//        cout << "pushed" <<endl ;
//    else
//        cout <<"not pushed"<<endl;
    
}

Sprite player::getPlayer(){
    
    return sprite;
}

void player::updatelvlP(game& myGame){
   sprite.setPosition(myGame.getP());
}
