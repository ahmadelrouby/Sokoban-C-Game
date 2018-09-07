//
//  tiles.cpp
//  game testing
//
//  Created by Ahmad Refaat on 4/21/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#include "tiles.hpp"
tiles::tiles(){
    
    
    if (!back.loadFromFile(resourcePath() + "blueB.png")) {
        return EXIT_FAILURE;
    }
    
    
    if (!wall.loadFromFile(resourcePath() + "ice.png")) {
        return EXIT_FAILURE;
    }
    
    
    if (!box.loadFromFile(resourcePath() + "metalBox.png")) {
        return EXIT_FAILURE;
    }
    
    if (!white.loadFromFile(resourcePath() + "white.jpg")) {
        return EXIT_FAILURE;
    }
   
    
}

void tiles::setTheme(int level){
   
    switch(level){
            
        case 1:
            
            if (!back.loadFromFile(resourcePath() + "yello.jpg")) {
            return EXIT_FAILURE;
        }
            
            
            if (!wall.loadFromFile(resourcePath() + "brickwall.jpg")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG.png")) {
                return EXIT_FAILURE;
            }
            
			if (!goal.loadFromFile(resourcePath() + "yello++.jpg")) {
				cout << "no";
			}
            
            break;

        case 2:
            
            if (!back.loadFromFile(resourcePath() + "grass2.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall2.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box2.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG2.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal2.png")) {
                cout << "no";
            }
            
            break;

        case 3:
            
            if (!back.loadFromFile(resourcePath() + "grass3.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall3.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box3.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG2.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal3.png")) {
                cout << "no";
            }
            
            break;

        case 4:
            
            if (!back.loadFromFile(resourcePath() + "grass4.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall4.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box4.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG4.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal4.png")) {
                cout << "no";
            }
            
            break;
            

        case 5:
            
            if (!back.loadFromFile(resourcePath() + "grass5.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall5.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box5.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG5.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal5.png")) {
                cout << "no";
            }
            
            break;
            

        case 6:
            
            if (!back.loadFromFile(resourcePath() + "grass6.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall6.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box6.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG6.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal6.png")) {
                cout << "no";
            }
            
            break;
       
        case 7:
            
            if (!back.loadFromFile(resourcePath() + "grass7.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall7.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box7.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG7.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal7.png")) {
                cout << "no";
            }
            
            break;

        case 8:
            
            if (!back.loadFromFile(resourcePath() + "grass8.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall8.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box8.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG8.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal8.png")) {
                cout << "no";
            }
            
            break;

        case 9:
            
            if (!back.loadFromFile(resourcePath() + "grass9.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "wall9.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "box9.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "boxG9.png")) {
                return EXIT_FAILURE;
            }
            
            if (!goal.loadFromFile(resourcePath() + "goal9.png")) {
                cout << "no";
            }
            
            break;


            
            
        default:
            
            if (!back.loadFromFile(resourcePath() + "blueB.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!wall.loadFromFile(resourcePath() + "ice.png")) {
                return EXIT_FAILURE;
            }
            
            
            if (!box.loadFromFile(resourcePath() + "metalBox.png")) {
                return EXIT_FAILURE;
            }
            
            if (!boxG.loadFromFile(resourcePath() + "metalBoxG.png")) {
                return EXIT_FAILURE;
            }
			if (!goal.loadFromFile(resourcePath() + "blueB++.png")) {
				cout << "no";
			}

            
            break;
            
            
            
    }
    
}


void tiles::setType(int n,int level){
    
    setTheme(level%10);
    
    switch(n){
            
        case 0:
        case 9:
            mySprite.setColor(Color::White);
            mySprite.setTexture(back);
            break;
		case 7:
			mySprite.setColor(Color::White);
			mySprite.setTexture(goal);
			break;
        case 1:
            mySprite.setColor(Color::White);
            mySprite.setTexture(wall);

            break;
        case 2:
            
            mySprite.setColor(Color::White);
            mySprite.setTexture(box);
            break ;
        case 5:
            
            mySprite.setColor(Color::White);
            mySprite.setTexture(boxG);
            break;
        case 3:
            mySprite.setColor(Color::Transparent);
            
            break;

    }
    
    mySprite.setTextureRect(IntRect(0,0,xSize,ySize));
    
    
    
    
    
}

void tiles::setPos(int i,int j,int xfactor,int yfactor){
    mySprite.setPosition(i*xSize+xfactor, j*ySize+yfactor);
}


Sprite  tiles::getSprite(){
    return mySprite;
    
    
    
    
}

