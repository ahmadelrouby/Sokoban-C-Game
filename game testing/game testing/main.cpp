
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "Game.hpp"
#include <iostream>
#include "player.hpp"
#include "menu.hpp"
#include "users.hpp"
#include <fstream>
#include "hints.hpp"
#include "highscores.hpp"
#include "music.hpp"
#include <cmath>
int xWindow = 1200 ;
int yWindow = 900 ;

int currentTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%H", &tstruct);
    return stoi(buf);
}


int main(int, char const**)
{
    
    ofstream out;
    out.open("high.txt", ios::out | ios::trunc);
    if(! out.is_open())
        cout<<"failed"<<endl;
    else
        cout<<"did it"<<endl ;
    out<<"Hi"<<endl ;
    out.close();
    users myuser(xWindow,yWindow);
    menu myMenu(xWindow,yWindow);
    game myGame;
	hints k;
    player player1(myGame);
	bool gamediff = false, checkback = false;
    music myMusic ;
    myGame.intlGame();
    string x;
      float speed = -0.6 ;
    
    highScores highscore1(xWindow,yWindow);
    
    int xfactor =myGame.xfactor; // the factor by which the game shifts to the right
    int yfactor = myGame.yfactor; // the factor by which the game shifts downwards
    int xSize = myGame.xSize ; // the size of the Sprite Player and the tiles
    int ySize = myGame.ySize; // size of player sprite
    
    sf::Clock clock1; // clock to prevent multitple clicks
    sf::Clock clock2; // clock to prevent multitple clicks
    sf::Clock clock3; // clock to prevent multitple clicks
    sf::Clock clock4; // clock to prevent multitple clicks
    sf::Clock clock5; // clock to prevent multitple clicks
    sf::Clock clock6; // clock to prevent multitple clicks

    int count=myGame.getCount(); // counter for the number of moves
    
    int currentMenu = 4;
    int previousMenu ;
    int currentLevel = myGame.currentlvl ;
    
    int buttonsOption = 0 ;
    
    

    bool win = false ;
    
    
    int counter=0;
    int counter2=0;
    
    bool lost = false ;
    bool check =true ;
    
    int lvlReached ;
    string name;
    string difficulty = "easy";
    
     // Create the main window
    sf::RenderWindow window(sf::VideoMode(xWindow, yWindow), "SFML window");
    sf::Texture texture ;
    
    if (!texture.loadFromFile(resourcePath() + "sky.jpg")) {
        return EXIT_FAILURE;
    }
    
    sf::Sprite back(texture);
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture texture1;
    if (!texture1.loadFromFile(resourcePath() + "back2.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Sprite sprite(texture1);

    
    
    // The speech bubble
    sf::Texture speechTexture;
    if (!speechTexture.loadFromFile(resourcePath() + "sBubble.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Sprite speechBubble(speechTexture);
    speechBubble.setPosition(350, 580);
    // end of speech bubble
    
    //NIGHT
    sf::RectangleShape night;
    night.setFillColor(sf::Color(0,0,0,50));
    night.setSize(Vector2f(xWindow,yWindow));
    
    //END OF NIGHT
    
    sf::Texture birdyTexture;
    if(!birdyTexture.loadFromFile(resourcePath()+"cBird.png"))
        return EXIT_FAILURE;
    
    sf::Sprite  birdySprite(birdyTexture);
    birdySprite.setTextureRect(sf::IntRect(counter*182, counter2*170, 182, 167));

    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setColor(sf::Color::Black);
    
    sf::Text UserName("",font,40);
    UserName.setColor(sf::Color::Red);

    sf::Text levelText("",font,60);
    levelText.setColor(sf::Color::Black);
   
    
    
    sf::Font newfont;
    if (!newfont.loadFromFile(resourcePath() + "kan.ttf")) {
        return EXIT_FAILURE;
    }

    sf::Text words("Hi,I'm Birdy!", newfont, 90);
    words.setColor(sf::Color::Black);
    words.setPosition(430, 550);
    
    sf::RectangleShape background ;
    background.setFillColor(sf::Color::White);
    background.setSize(Vector2f(xWindow,yWindow));
    
    string theLevel ;
    
       
    
    sf::RectangleShape mouse;
    mouse.setSize(Vector2f(10,10));
    
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath()+"nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    // Play the music
//    music.play();

    myMusic.backgroundmusic();

    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        sf::Time elapsed1 = clock1.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        
        //to update mouse position
        localPosition = sf::Mouse::getPosition(window);
        mouse.setPosition(localPosition.x,localPosition.y);
      //  myMusic.backgroundmusic();
        


        
        // Clear screen
        window.clear();
        
        
        
        //Draws the Background
        window.draw(back);
        
        
       // Draws the motion
        window.draw(sprite);
        
        //Draws the night thingy
        
        //if(currentTime()>18&&myMenu.nighty)
        if(myMenu.nighty)
        window.draw(night);
        
        
       //cout << (sprite.getPosition().x) << " " << (sprite.getPosition().x)+3360 << " " << xWindow << endl ;
        // animated background
        if(sprite.getPosition().x>1)
            speed=-0.6 ;
        else   if((sprite.getPosition().x)+3360<xWindow)
            
        {
            cout <<"reached" << endl ;
            speed=0.6 ;
        }
        
        if(clock3.getElapsedTime().asSeconds()>=0.05){
            clock3.restart();
            sprite.move(speed, 0);
        } // end of background animation
        

        //animation for the bird character
        birdySprite.setTextureRect(sf::IntRect(counter*182, counter2*170, 182, 167));
        
        if(clock4.getElapsedTime().asSeconds()>0.15){
            clock4.restart();
            counter++;
            //cout << "counter in" << endl ;
            
            if (counter==5 && counter2 !=2){
                counter=0 ;
                counter2++;
                
            }
            
            if(counter2==2 && counter==4)
            {
                counter=0 ;
                counter2=0 ;
            }
            
            
            
        } //end of character Bird animation
        
        
		myMenu.back1(window, currentMenu, mouse, checkback);
		if (currentMenu == 5) // pickPlayer
        {
           // cout << "Inside 5" << endl ;
            player1.pickplayer(window, myGame, currentMenu, elapsed1, clock1, birdySprite);
            speechBubble.setPosition(300, 120);
            window.draw(speechBubble);
            
        }
		else if (currentMenu == 3) // Register Menu
			myuser.createAccount(event, currentMenu, window, elapsed1, clock1, mouse, previousMenu);

		else if (currentMenu == 0) //Login Menu
			//myMenu.getName(event,currentMenu,window,elapsed1,clock1);
			myuser.login(event, currentMenu, window, elapsed1, clock1, mouse, previousMenu);

		else if (currentMenu == 4) // Choosing login or Register
        {//myMenu.getName(event,currentMenu,window,elapsed1,clock1);
			myuser.loginMenu(currentMenu, mouse, window, previousMenu,birdySprite,words);// , birdySprite);
            window.draw(words);
            window.draw(speechBubble);
        }

		else if (currentMenu == 1) // Game main Menu
			myMenu.mainMenu(currentMenu, mouse, window, previousMenu, birdySprite,clock5,myMusic);
		else if (currentMenu == 8)
			myMenu.options(currentMenu, previousMenu, window, birdySprite,clock5);
		else if (currentMenu == 7)
		{
			myMenu.diffuculty(window, currentMenu, previousMenu, currentLevel,clock5,difficulty);
			//myGame.currentlvl = currentLevel;
			//gamediff = true;
		}
		else if (currentMenu == 9)
			myMenu.volume(window, currentMenu, previousMenu, myMusic,clock5);
		else if (currentMenu == 10)
			myMenu.nightmode(window, currentMenu, previousMenu,clock5);
		else if (currentMenu == 15)
		{

            name=myuser.returnName();
			myMenu.selectlevel(window, currentMenu, previousMenu, highscore1.search(name, difficulty), currentLevel, mouse, difficulty,clock6);
			myGame.currentlvl = currentLevel;
			gamediff = true;
		}
        else if(currentMenu==2 )// The GAME
        {
            
            if(win)
                cout << "You won the game" << endl ;
            
            if(difficulty=="easy"){
                theLevel= to_string(currentLevel) ;
                
            }
            else if (difficulty=="medium"){
                theLevel= to_string(currentLevel-10) ;

            }
            
            else if(difficulty == "hard"){
                theLevel= to_string(currentLevel-20) ;

                
            }
            
            levelText.setString("Level  " + theLevel);
            levelText.setPosition(xWindow-800, 10);
            name = myuser.returnName() ;

            lvlReached = highscore1.search(name, difficulty);
           // cout << lvlReached<<endl ;
            //cout <<"before  evrything" << endl ;

            //Updates the text
     
            text.setString("Moves: "+to_string(count));

            UserName.setString("Hello, "+myuser.returnName() + "\n HighScore: " + to_string(lvlReached));
            UserName.setPosition(xWindow-300, 10);
        

            if(buttonsOption==4){
                cout <<"Yes inside" ;
                if(myMusic.volume>0)
                    myMusic.volume=0;
                
                else
                    myMusic.volume=100;
                
                myMusic.setVolume(myMusic.volume);
                
                buttonsOption=0;
            }
        
        if(elapsed1.asSeconds()>=0.12){
            clock1.restart();
            
            
            if (myGame.checkLoss(count) == true){
				cout << "you losee";
             if(check)
                lost=true;
            }
			else
			if (myGame.checkwin() == false)
				player1.updateMovement(count, myGame,k,myMusic);//Updates the player Movement

            
            if(lost)
            {
                myMusic.lose();
                lost=false;
                check=false ;
            }
            
			if (gamediff == true)
			{
				myGame.updatelvl(currentLevel);
				myGame.intlGame();
				player1.updatelvlP(myGame);
				count = myGame.getCount();
				gamediff = false;
			}

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )//&& myGame.checkwin() == true)
            {
               // myMusic.levelUp();
                currentLevel++;
                myGame.updatelvl(currentLevel);
                myGame.intlGame();
                player1.updatelvlP(myGame);
                count=myGame.getCount();
                
            }

           
            
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && myGame.checkwin() == true)
            if(buttonsOption==5)
            {
                if(stoi(theLevel)<10){
                myMusic.levelUp();
                currentLevel++;
                myGame.updatelvl(currentLevel);
                myGame.intlGame();
                player1.updatelvlP(myGame);
                count=myGame.getCount();
                buttonsOption=0;
                k.hint=false ;
                }
                else
                    win=true;

            
                           }
           
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            if(buttonsOption==3)
            {
                highscore1.addUser(name, stoi(theLevel), difficulty);
                currentLevel=1;
                myGame.updatelvl(1);
                myGame.intlGame();
                player1.updatelvlP(myGame);
                count=myGame.getCount();
                k.hint=false ;

                buttonsOption=0;
            }
			
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			if (checkback == true)
			{
                highscore1.addUser(name,  stoi(theLevel), difficulty);
                currentLevel=1;
                myGame.updatelvl(1);
                myGame.intlGame();
                player1.updatelvlP(myGame);
                count=myGame.getCount();
                k.hint=false ;
                checkback=false;
                k.num=1;
                currentMenu=1;
            }

           // if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			if(buttonsOption==2)
            {

				myGame.updatelvl(currentLevel);
				myGame.intlGame();
				player1.updatelvlP(myGame);
				count = myGame.getCount();
                k.hint=false ;
                buttonsOption=0;
			}
			
        }
            
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)&& k.num <= 3)
            if (buttonsOption==1 && k.num <= 3)
                
            {
                cout << " inside " << endl ;
                
                k.generatehints(myGame.displaySolution(), myGame.getCount(), count);
                k.num++;
                k.hint = true;
                buttonsOption=0 ;
                
            }
            

		if (k.hint == true && k.x < k.numberofmoves(myGame.getCount()) && k.x < count)
		{

			//k.generatehints(myGame.displaySolution(), myGame.getCount(), count);
			
         
                k.printhint(k.x, window, count, myGame.getCount());

            

		}
		if (k.x >= k.numberofmoves(myGame.getCount()) || k.x >= count)
		{
			k.x = 0; k.hint = false; k.help.clear();

		}
            
            
        //Draw Game
        myGame.drawGame(window);
            
            birdySprite.setPosition(0, yWindow-230);
            

            window.draw(birdySprite);
            
        //Draws the player
        window.draw(player1.getPlayer());
            
            
            myGame.buttonsGame(window, clock5, xWindow, yWindow,buttonsOption,mouse,words,speechBubble,myMusic,count);
            
        //Draw the Number of Moves
       
            window.draw(text);
           
            window.draw(levelText);

            window.draw(UserName);
        }
        
        
        else if(currentMenu==6){
            highscore1.choose(currentMenu, mouse, window, previousMenu, birdySprite,clock5);
           
        }
        
        else if(currentMenu==11)
          highscore1.display(6, "easy",window);
       
        else if(currentMenu==12)
            highscore1.display(6, "medium",window);
        
        else if(currentMenu==13)
            highscore1.display(6, "hard",window);
        // Display the Window
        window.display();
        //cout << k.num << endl ;
    }

    return EXIT_SUCCESS;
}
