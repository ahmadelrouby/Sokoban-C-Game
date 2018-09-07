//
//  users.cpp
//  game testing
//
//  Created by Ahmad Refaat on 4/22/16.
//  Copyright © 2016 Ahmad Refaat. All rights reserved.
//

#include "users.hpp"

users::users(int x,int y){
    
    myX=x; myY=y;
  userName=""; Password=""; user=""; pass="";
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    if(!backgroundTexture.loadFromFile(resourcePath()+"sky.jpg"))
        return EXIT_FAILURE;
    backgroundSprite.setTexture(backgroundTexture);

    
    
    if(!loginTexture.loadFromFile(resourcePath()+"loginbutton.png"))
        return EXIT_FAILURE;
    
    if(!registerTexture.loadFromFile(resourcePath()+"registerbutton.png"))
        return EXIT_FAILURE;
    
    if(!createTexture.loadFromFile(resourcePath()+"createaccountbutton.png"))
        return EXIT_FAILURE;
    
    
    loginButton.setTexture(loginTexture);
    registerButton.setTexture(registerTexture);
    createButton.setTexture(createTexture);



    loginR.setFillColor(Color::Black);
    loginR.setPosition(x/2-240, y/2+280);
    loginR.setSize(Vector2f(436,148));
    
    loginWord.setString("Login");
    loginWord.setCharacterSize(100);
    loginWord.setFont(font);
    loginWord.setColor(Color::White);
    loginWord.setPosition(x/2-170, y/2+260);

    enter.setString("Enter Your Name");
    enter.setColor(Color::Black);
    name1.setColor(Color::Blue);
    
    createAcc.setPosition(Vector2f(x/2-255,y/2-100));
    enter.setFont(font);
    name1.setFont(font);
    enter.setCharacterSize(50);
    enter.setPosition(Vector2f(x/2-220,y/2-100));
    name1.setCharacterSize(40);
    name1.setPosition(Vector2f(x/2-100,y/2));
   
    
    passwordEnter.setString("Enter Password");
    passwordEnter.setColor(Color::Black);
    passwordText.setColor(Color::Blue);
    
    
    passwordEnter.setFont(font);
    passwordText.setFont(font);
    passwordEnter.setCharacterSize(50);
    passwordEnter.setPosition(Vector2f(x/2-220,y/2+100));
    passwordText.setCharacterSize(40);
    passwordText.setPosition(Vector2f(x/2-100,y/2+200));



}

string users::encryptDecrypt(string toEncrypt) {
    char key = 'P' ; //Any chars will work
    string output = toEncrypt;
    
    //cout << sizeof(key) << endl ;
    //cout << sizeof(char) << endl ;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key ;
    
    return output;
}


void users::login(Event& event,int& n,RenderWindow& window,Time elapsed1,Clock& clock2,RectangleShape mouse, int& prev){
    
    loginWord.setString("Login");
    loginWord.setCharacterSize(100);
    loginWord.setPosition(myX/2-170, myY/2+260);

    ifstream input;
    input.open(resourcePath()+"user.txt");
    if(input.fail())
        cout<<"Can't open file"<< endl;
        
    if(logged){
        cout <<"Logged in!"<<endl ;
        prev=n;
        n=1;
        type=0;
        name=userName;
        userName="";
        Password="";
    }
    //cout <<userName << endl ;
    //cout <<Password<< endl ;
    loginButton.setPosition(loginR.getPosition());
    
   // window.draw(backgroundSprite);
    window.draw(enter);
    window.draw(name1);
    
   // window.draw(loginR);
    //window.draw(loginWord);
    window.draw(loginButton);
    if(elapsed1.asSeconds()>=0.15&&type==0){
        clock2.restart();
        if (event.type == sf::Event::TextEntered)
        {
            // Handle ASCII characters only
            if (event.text.unicode < 128)
            {  cout << event.text.unicode << endl ;
                if(event.text.unicode!=8)
                    userName += static_cast<char>(event.text.unicode);
                else
                    userName=userName.substr(0,userName.length()-1);
            }
        }
        
        
        name1.setString(userName);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
            userName=userName.substr(0,userName.length()-1);
            while(!input.eof()){
                input>>user;
                if(userName== encryptDecrypt(user)){
                    input>>pass;
                    flag=true;
                }
            }

            if(flag){type=1; newLine=true;} else {cout <<"User not found"<<endl;userName=""; }
            clock2.restart();
            //cout <<"success";
        }
        
        
        
    }

    if(type==1){
        window.draw(passwordEnter);
        window.draw(passwordText);
        
    }
    if(elapsed1.asSeconds()>=0.12&&type==1){
   // cout <<"entered";
        clock2.restart();
        if (event.type == sf::Event::TextEntered)
        {
            // Handle ASCII characters only
            if (event.text.unicode < 128)
            {  cout << event.text.unicode << endl ;
                if(event.text.unicode!=8)
                    Password += static_cast<char>(event.text.unicode);
                else
                    Password=Password.substr(0,Password.length()-1);
            }
        }
        
        if(newLine){
            Password=Password.substr(1,Password.length());
            newLine=false ;
        }
        temp="";
        for(int i=0;i<Password.length();i++)
            temp+="*";
        
        passwordText.setString(temp);
        
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&mouse.getGlobalBounds().intersects(loginR.getGlobalBounds()))
        
    {
       
            if(encryptDecrypt(pass)==Password){
            cout <<"Password Matches"<<endl ;
                logged=true;
            }else{
            cout <<"Sorry"<<endl;
            Password="";
                //temp="";
            }
        
        input.close();
        flag=false ;
        

    }
        
    }

    
    
    
}
string users::returnName(){
    return name;
}

void users::createAccount(Event& event,int& n,RenderWindow& window,Time elapsed1,Clock& clock2,RectangleShape mouse,int& prev){
    
    //window.draw(backgroundSprite);
    
    ifstream input;
    input.open(resourcePath()+"user.txt");
    if(input.fail())
        cout<<"Can't open file"<< endl;

   
    
    
    if(logged){
       
        addAccount(userName, Password);
        cout <<"Logged in!"<<endl ;
        prev=n;
        n=1;type=0;
        name=userName;
        userName="";
        Password="";
    }

    else {
    
    createAcc.setString("Choose a username");
    createAcc.setFont(font);
    createAcc.setCharacterSize(50);
    createAcc.setColor(Color::Black);
    
   
        
        registerButton.setPosition(loginR.getPosition());
        window.draw(registerButton);
        
        
    window.draw(createAcc);
    window.draw(name1);
    if(elapsed1.asSeconds()>=0.15&&type==0){
        clock2.restart();
        if (event.type == sf::Event::TextEntered)
        {
            // Handle ASCII characters only
            if (event.text.unicode < 128)
            {  cout << event.text.unicode << endl ;
                if(event.text.unicode!=8)
                    userName += static_cast<char>(event.text.unicode);
                else
                    userName=userName.substr(0,userName.length()-1);
            }
        }
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
            userName=userName.substr(0,userName.length()-1);
            
            while(!input.eof()){
                input>>user;
                if(userName== encryptDecrypt(user)){
                    flag=true;
                    
                    
                }
            }
            
            if(!flag) {
                type=1;
                newLine=true;
            }


        }
        
    }
    
    name1.setString(userName);

        if(flag) {cout<<"username exists"<<endl ; flag=false ;userName="";}
   

    
    if(elapsed1.asSeconds()>=0.12&&type==1){
        // cout <<"entered";
        clock2.restart();
        if (event.type == sf::Event::TextEntered)
        {
            // Handle ASCII characters only
            if (event.text.unicode < 128)
            {  cout << event.text.unicode << endl ;
                if(event.text.unicode!=8)
                    Password += static_cast<char>(event.text.unicode);
                else
                    Password=Password.substr(0,Password.length()-1);
            }
        }
    
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&mouse.getGlobalBounds().intersects(loginR.getGlobalBounds()))
            
        {
           
            logged=true ;
        }
    }
    
    if(newLine){
        Password=Password.substr(1,Password.length());
        newLine=false ;
    }
    passwordText.setString(Password);
    
    if(type==1)
    {window.draw(passwordEnter);
        window.draw(passwordText);
    }
    
    
    }

}

void users::addAccount(string name, string passW){
    ofstream output ;
   // output.open("/Users/ahmadrefaat/Desktop/game testing/game testing/user.txt",  ios::out | ios::app);
    output.open("user.txt", ios::out | ios::app);
    if(output.fail())
        cout<<"failed to open a file";
    else
        output<<endl<< encryptDecrypt(name)  <<" " << encryptDecrypt(passW) <<endl   ;
    
    output.close();
}

void users::loginMenu(int& n, RectangleShape mouse, RenderWindow& window,int& prev, Sprite& birdySprite,Text& words){
    
    signMenu.setString("Login");
    RegisterMenu.setString("Create Account");
    signMenu.setFont(font);
    RegisterMenu.setFont(font);
    signMenu.setCharacterSize(50);
    RegisterMenu.setCharacterSize(50);
  
    signMenu.setColor(Color::White);
    RegisterMenu.setColor(Color::White);
    
    signMenu.setPosition(myX/2-65, myY/2-185);
    RegisterMenu.setPosition(myX/2-170, myY/2+15);

    signRectangle.setPosition(myX/2-220, myY/2-300);
    registerRectangle.setPosition(myX/2-220, myY/2-100);
    signRectangle.setSize(Vector2f(436,148));
    registerRectangle.setSize(Vector2f(436,148));
    signRectangle.setFillColor(Color::Black);
    registerRectangle.setFillColor(Color::Black);
    

    loginButton.setPosition(signRectangle.getPosition());
    createButton.setPosition(registerRectangle.getPosition());
    
    
    
    birdySprite.setPosition(myX/2-430, myY-350);

   // window.draw(backgroundSprite);
    
    window.draw(loginButton);
    window.draw(createButton);
    window.draw(birdySprite);
    
    if(mouse.getGlobalBounds().intersects(signRectangle.getGlobalBounds())){
        words.setString("Already a User?");
        words.setCharacterSize(80);
        words.setPosition(400, 600);

    }
    
    else if(mouse.getGlobalBounds().intersects(registerRectangle.getGlobalBounds())){
        words.setString("No Account?");
        words.setCharacterSize(90);
        words.setPosition(430, 590);

    }
    
    else{
        words.setString("Hi I'm Birdy! ");
        words.setCharacterSize(90);
        words.setPosition(430, 590);


    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        
        if(mouse.getGlobalBounds().intersects(signRectangle.getGlobalBounds())){
            prev=n;
            n=0;
            
        }
        
        
        if(mouse.getGlobalBounds().intersects(registerRectangle.getGlobalBounds())){
            prev=n;
            n=3;
        }
        
    }

    
}

