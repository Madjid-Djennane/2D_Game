#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Headers/game.hpp"
#include "../Headers/carte.hpp"
#include <map>
#include <typeinfo>


int main() {
    
    Game game = Game();
    std::map<std::string, Element *> map;

    
    int winWidth(game.winWidth*64);
    int winHeigth(game.winHeight*64);
    

    //Window
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeigth), "Testing");
    window.setKeyRepeatEnabled(false);

/*     sf::Texture back;
    if(!back.loadFromFile("../img/back.png")) {
        std::cout << "error" << std::endl;
    }

    sf::Sprite sprite(back);
 */
    int dir(0);

    sf::Font font;
    if(!font.loadFromFile("../img/leadcoat.ttf")){
        std::cout << "error on loading font" << std::endl;
    }

    sf::Text player1;
    player1.setFont(font);
    player1.setString("Player 1 ");
    player1.setCharacterSize(19); 
    player1.setPosition(sf::Vector2f(0,0));
    player1.setFillColor(sf::Color::Red);

    sf::Text vie1;
    vie1.setFont(font);
    vie1.setString("Player 1 ");
    vie1.setCharacterSize(18); 
    vie1.setPosition(sf::Vector2f(0,20));
    vie1.setFillColor(sf::Color::Blue);

    sf::Text player2;
    player2.setFont(font);
    player2.setString("Player 2 ");
    player2.setCharacterSize(19); 
    player2.setPosition(sf::Vector2f(0,45));
    player2.setFillColor(sf::Color::Red);


    sf::Text vie2;
    vie2.setFont(font);
    vie2.setString("Player 1 ");
    vie2.setCharacterSize(18); 
    vie2.setPosition(sf::Vector2f(0,65));
    vie2.setFillColor(sf::Color::Blue);

    

    //Game Loop
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); //Clear Window

        map = game.getMap();
        
        game.mainPlayerMovement();

        if(game.autoPlayerMovement(dir)){
            dir = std::rand() % 4;
        }

        for(auto& element : map){
            window.draw(element.second->getSprite());
        }

        vie1.setString(std::to_string(game.mainPlayer->getPointsVie()));
        vie2.setString(std::to_string(game.autoPlayer->getPointsVie()));

        window.draw(player1);
        window.draw(vie1);

        window.draw(player2);
        window.draw(vie2);
        
        

        window.display(); //Display Window
    }
    
    

    

    
    

    return 0;
}