//
//  menu.cpp
//  game testing
//
//  Created by Ahmad Refaat on 4/22/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#include "menu.hpp"

menu::menu(int x,int y){
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }

    if(!backgroundTexture.loadFromFile(resourcePath()+"sky.jpg"))
        return EXIT_FAILURE;
   
    
    
    if(!startTexture.loadFromFile(resourcePath()+"startbutton.png"))
        return EXIT_FAILURE;

    if(!optionsTexture.loadFromFile(resourcePath()+"optionsbutton.png"))
        return EXIT_FAILURE;

    if(!highScoresTexture.loadFromFile(resourcePath()+"highscorebutton.png"))
        return EXIT_FAILURE;


    
    backgroundSprite.setTexture(backgroundTexture);
    startButton.setTexture(startTexture);
    optionsButton.setTexture(optionsTexture);
    highScoresButton.setTexture(highScoresTexture);

    
    
    enter.setFont(font);
    name1.setFont(font);
    enter.setCharacterSize(50);
    enter.setPosition(Vector2f(x/2-220,y/2-100));
    name1.setCharacterSize(40);
    name1.setPosition(Vector2f(x/2-100,y/2));

    startT.setFont(font);
     highT.setFont(font);
     nxtT.setFont(font);
     backT.setFont(font);
    
    startT.setCharacterSize(50);
    highT.setCharacterSize(50);

    enter.setString("Enter Your Name");
    enter.setColor(Color::Black);
    name1.setColor(Color::Cyan);
    startT.setColor(Color::White);
    highT.setColor(Color::White);
    nxtT.setColor(Color::White);
    backT.setColor(Color::White);

    startT.setString("Start");
    highT.setString("High Scores");

    
       nxt.setFillColor(Color::Black);
    back.setFillColor(Color::Black);

    
    startT.setPosition(x/2-65, y/2-185);
    highT.setPosition(x/2-140, y/2+15);
    
    optionsRectangle.setPosition(x/2-220, y/2-50);
    optionsRectangle.setSize(Vector2f(436,148));
    optionsRectangle.setFillColor(Color::Black);

    startRectangle.setPosition(x/2-220, y/2-250);
    highScoresRectangle.setPosition(x/2-220, y/2+150);
    highScoresRectangle.setSize(Vector2f(436,148));
    startRectangle.setSize(Vector2f(436,148));
    startRectangle.setFillColor(Color::Black);
    highScoresRectangle.setFillColor(Color::Black);
    
    
    
    startButton.setPosition(startRectangle.getPosition());
    optionsButton.setPosition(optionsRectangle.getPosition());
    highScoresButton.setPosition(highScoresRectangle.getPosition());


    
}



void menu::mainMenu(int& n,RectangleShape mouse,RenderWindow& window,int& prev,Sprite& birdySprite,Clock& clock,music& myMusic){
    
    window.draw(startButton);
    window.draw(optionsButton);
    window.draw(highScoresButton);
    window.draw(birdySprite);
    
    
    
    
    
    
    if(mouse.getGlobalBounds().intersects(startRectangle.getGlobalBounds())){
    
        previous=current;
        birdySprite.setPosition(startRectangle.getPosition().x-200, startRectangle.getPosition().y-30);
        current=1;
        
       
        if(!myMusic.stillPlaying()&&previous!=current)
            myMusic.button();
    }
    
    else if(mouse.getGlobalBounds().intersects(optionsRectangle.getGlobalBounds())) {
        
        previous=current;
        birdySprite.setPosition(optionsRectangle.getPosition().x-200, optionsRectangle.getPosition().y-30);
        current=2;
        
        if(!myMusic.stillPlaying()&&previous!=current)
            myMusic.button();


    }
    
    else if(mouse.getGlobalBounds().intersects(highScoresRectangle.getGlobalBounds())) {
        
        previous=current;
        birdySprite.setPosition(highScoresRectangle.getPosition().x-200, highScoresRectangle.getPosition().y-30);
        current=3;
        
        if(!myMusic.stillPlaying()&&previous!=current)
            myMusic.button();


           }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& clock.getElapsedTime().asSeconds()>0.5){
        clock.restart();
        if(mouse.getGlobalBounds().intersects(startRectangle.getGlobalBounds())){
            prev=n;
            n=2;
            cout << "N IS 2" << endl ;
        }
    
    
        if(mouse.getGlobalBounds().intersects(optionsRectangle.getGlobalBounds())){
            prev=n;
        n=8; nameS="";
        }
 
        
        
        if(mouse.getGlobalBounds().intersects(highScoresRectangle.getGlobalBounds())){
            prev=n;
            n=6; nameS="";
        }

    }
    
    
    
    
    
}
void menu::options(int& n, int& prev, RenderWindow& w, Sprite& birdy,Clock& clock)
{


	sf::Event event;
	while (w.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			w.close();
	}
	Texture B1, B2, B3, B4, B5;
	if (!B1.loadFromFile(resourcePath() + "selectplayerbutton.png"))
	{
		cout << "no";
	}

	if (!B2.loadFromFile(resourcePath() + "volumebutton.png"))
	{
		cout << "no";
	}

	if (!B3.loadFromFile(resourcePath() + "difficultybutton.png"))
	{
		cout << "no";
	}

	if (!B4.loadFromFile(resourcePath() + "nightmodebutton.png"))
	{
		cout << "no";
	}
	
	Sprite b1, b2, b3, b4, b5;

	b1.setTexture(B1); b2.setTexture(B2); b3.setTexture(B3); b4.setTexture(B4);// s.setTexture(sky);
	b1.setPosition(232 + 150, 50); b2.setPosition(232 + 150, 200); b3.setPosition(232 + 150, 350); b4.setPosition(232 + 150, 500);
	Vector2i Pmouse = Mouse::getPosition(w);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& clock.getElapsedTime().asSeconds()>0.5)
	{
        clock.restart();


		if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y>50 && Pmouse.y < 50 + 148)
		{
			prev = n; n = 5;
		}
		else
		{
			if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y>200 && Pmouse.y < 200 + 148)
			{
				//make it go to volume
				prev = n; n = 9;
				
			}
			else
			{
				if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y> 350 && Pmouse.y < 350 + 148)
				{
					prev = n; n = 7;
					//make it go to diffuculty
				
				}
				else
				{
					if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y>  500 && Pmouse.y < 500 + 148)
					{
						//make it go to night mode
						prev = n; n = 10;
					}
				}
			}
		}
	}
	if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y>50 && Pmouse.y < 50 + 148)
		birdy.setPosition(200, 0);
	else

	if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y>200 && Pmouse.y < 200 + 148)
		birdy.setPosition(200, 150);
	else
	if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y> 350 && Pmouse.y < 350 + 148)
		birdy.setPosition(200, 300);
	else

	if (Pmouse.x > 232 + 150 && Pmouse.x<232 + 150 + 436 && Pmouse.y>  500 && Pmouse.y < 500 + 148)
		birdy.setPosition(200, 450);


	w.draw(b1);
	w.draw(b2);
	w.draw(b3);
	w.draw(b4);
	w.draw(birdy);
}
void menu::diffuculty(RenderWindow& w, int& n, int&prev, int& level, Clock& clock, string& diff)
{
	Texture easyb, mediumb, hardb;
	if (!easyb.loadFromFile(resourcePath() + "easybutton.png"))
	{
		cout << "no";
	}
	if (!mediumb.loadFromFile(resourcePath() + "mediumbutton.png"))
	{
		cout << "no";
	}
	if (!hardb.loadFromFile(resourcePath() + "hardbutton.png"))
	{

		cout << "no";
	}

	Sprite easy, medium, hard;
	easy.setTexture(easyb); medium.setTexture(mediumb); hard.setTexture(hardb);
	easy.setPosition(232 + 150, 50); medium.setPosition(232 + 150, 250); hard.setPosition(232 + 150, 450);
	Mouse mouse;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& clock.getElapsedTime().asSeconds() > 0.5 )
	{//game mygame;
        clock.restart();
		Vector2i Pmouse = Mouse::getPosition(w);
		if (Pmouse.x > 232 + 150 && Pmouse.x  < 232 + 436 + 150 && Pmouse.y > 50 && Pmouse.y < 50 + 148)
		{
			level = 1; n = 15; diff = "easy";
		}
		else
		if (Pmouse.x > 232 + 150 && Pmouse.x < 232 + 436 + 150 && Pmouse.y > 250 && Pmouse.y < 250 + 148)
		{
			level = 11; n = 15; diff = "medium";
		}
		else
		if (Pmouse.x > 232 + 150 && Pmouse.x < 232 + 436 + 150 && Pmouse.y > 450 && Pmouse.y < 450 + 148)
		{
			level = 21; n = 15; diff = "hard";
		}

	}

	w.draw(easy);
	w.draw(medium);
	w.draw(hard);
}
void menu::volume(RenderWindow& w, int& n, int& prev, music& sound,Clock& clock)
{


	Texture pointer, grade, mute, maxv, done;
	if (!pointer.loadFromFile(resourcePath() + "pointer.png"))
	{
		cout << "no";
	}
	if (!grade.loadFromFile(resourcePath() + "loudness.png"))
	{
		cout << "no";
	}
	if (!mute.loadFromFile(resourcePath() + "mutebutton.png"))
	{
		cout << "no";
	}
	if (!maxv.loadFromFile(resourcePath() + "maxvolbutton.png"))
	{
		cout << "no";
	}
	if (!done.loadFromFile(resourcePath() + "donebutton.png"))
	{
		cout << "no";
	}
	Sprite p, g, mutes, maxvs, dones;
	p.setTexture(pointer); g.setTexture(grade);
	g.setPosition(300, 100);

	if (flag == false)
		p.setPosition(300, 730);
	else
		p.setPosition(300, y2);


	mutes.setTexture(mute); maxvs.setTexture(maxv); dones.setTexture(done);
	mutes.setPosition(600, 100); maxvs.setPosition(600, 300); dones.setPosition(600, 500);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&clock.getElapsedTime().asSeconds()>0.5)
	{
		flag = true;
		Vector2i Pmouse = Mouse::getPosition(w);

		if (Pmouse.x >= 600 && Pmouse.x <= 600 + 265 && Pmouse.y > 100 && Pmouse.y < 100 + 146)
		{
			sound.setVolume(0); y2 = 100;
		}
		else
		if (Pmouse.x >= 600 && Pmouse.x <= 600 + 265 && Pmouse.y > 300 && Pmouse.y < 300 + 146)
		{
			sound.setVolume(100); y2 = 679 + 100 - 44;
		}
		else
		if (Pmouse.x >= 600 && Pmouse.x <= 600 + 265 && Pmouse.y > 500 && Pmouse.y < 500 + 146)
			n = 1;
		else
		{
			y2 = Pmouse.y;
			if (y2 >= 100 && y2 <= 100 + 679 && Pmouse.x>300 && Pmouse.x < 400)
				p.setPosition(300, y2);
			else if (y2 < 100 && Pmouse.x>300 && Pmouse.x < 400)
				y2 = 100;
			else
				y2 = 679 + 100 - 44;

			float vol, l1, l2;
			l1 = y2 - 100;
			l2 = l1 / 639;
			vol = l2 * 100;
            cout << vol << endl ;
			sound.setVolume(vol);
		}

	}



	w.draw(mutes);
	w.draw(maxvs);
	w.draw(dones);
	w.draw(g);
	w.draw(p);

}
void menu::nightmode(RenderWindow& w, int& n, int& prev,Clock& clock)
{
	Texture on, off;
	if (!off.loadFromFile(resourcePath() + "switchbutton.png", IntRect(0, 0, 500, 242.5)))
	{
		cout << "no";
	}
	if (!on.loadFromFile(resourcePath() + "switchbutton.png", IntRect(0, 242.5, 500, 242.5)))
	{
		cout << "no";
	}
	Sprite select;

	select.setPosition(350, 207.5 + 200);

	Mouse mouse;
	Vector2i Pmouse = mouse.getPosition(w);
	if (state == 0 && (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Pmouse.x > 350 && Pmouse.x < 350 + 214 && Pmouse.y > 207.5 + 200 && Pmouse.y < 207.5 + 242.5 + 200))
		state = 1;
	else
	if (state == 1 && (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Pmouse.x > 350 + 290 && Pmouse.x < 350 + 500 && Pmouse.y > 207.5 + 200 && Pmouse.y < 207.5 + 242.5 + 200))
		state = 0;

    if (state == 1){
		select.setTexture(off);
        nighty=false;
    }
	else
	{
		select.setTexture(on);
		select.setPosition(350, 185 + 200);
        nighty=true;
	}
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        n=1;
    
    
	//state1 =nightmode on
	//state0 = nightmode off
	w.draw(select);

}
void menu::selectlevel(RenderWindow& w, int& n, int& prev, int level, int& currentlevel, RectangleShape mouse, string& diff, Clock& clock)
{
	Font font;
	Text text;
	Texture locked, unlocked;
	Sprite levels[10];
	RectangleShape rect[10];
	int count = 0;
	if (!locked.loadFromFile(resourcePath() + "locked.png"))
	{
		cout << "no";
	}
	if (!unlocked.loadFromFile(resourcePath() + "unlocked.png"))
	{
		cout << "no";
	}
	if (!font.loadFromFile(resourcePath() + "kan.ttf"))
	{
		cout << "no";
	}


	text.setFont(font);
	while (count < 10)
	{
		text.setString("Level" + to_string(count + 1));
		text.setCharacterSize(60);
		if (count < level)
			levels[count].setTexture(unlocked);
		else
			levels[count].setTexture(locked);

		if (count < 5)
		{
			levels[count].setPosition(count * 207 + 70, 200);
			text.setPosition(count * 207 + 70 + 30, 205);
		}
		else
		{
			levels[count].setPosition((count - 5) * 207 + 70, 400);
			text.setPosition((count - 5) * 207 + 70 + 30, 405);
		}

		w.draw(levels[count]);
		w.draw(text);
		count++;
	}
	int c = 0;
	while (c < 10)
	{
		rect[c].setSize(Vector2f(203, 105));
		rect[c].setPosition(levels[c].getPosition());
		c++;
	}

	if (Mouse::isButtonPressed(sf::Mouse::Left)&&clock.getElapsedTime().asSeconds()>0.5)
	{
        clock.restart();
		int g = 0;
		while (g < level)
		{
			if (mouse.getGlobalBounds().intersects(rect[g].getGlobalBounds()))
			{
				//cout << diff;
				cout << g;
				if (diff == "easy")
					currentlevel = g + 1;
				else
				if (diff == "medium")
					currentlevel = g + 11;
				else
				if (diff == "hard")
					currentlevel = g + 21;

				n = 1;
				cout << currentlevel;
			}
			g++;
		}
	}
}
void menu::back1(RenderWindow& w, int& n, RectangleShape mouse, bool& back2)
{

	Texture button;
	if (!button.loadFromFile(resourcePath() + "backbutton.png"))
	{
		cout << "no";
	}
	Sprite back5;
	back5.setTexture(button);
	if (n != 2)
		back5.setPosition(10, 10);
	else back5.setPosition(10, 100);
	RectangleShape Rect;
	Rect.setSize(Vector2f(188, 141));
	Rect.setPosition(back5.getPosition());
	if (Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mouse.getGlobalBounds().intersects(Rect.getGlobalBounds())&&(n != 0 && n != 4 && n != 1&& n != 3))

		{
			if (n == 2)
				back2 = true;
			else

				n = 1;
		}
	}
	if (n != 0 && n != 4 && n != 1&& n != 3)
		w.draw(back5);
}
