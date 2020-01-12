#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Headers/game.hpp"
#include "../Headers/carte.hpp"
#include <map>

int main() {


    
    
    Game game = Game();
    std::map<std::string, Element *> map = game.getMap();


    int winWidth(15*64);
    int winHeigth(10*64);
    

    //Window
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeigth), "Testing");
    window.setKeyRepeatEnabled(false);

    bool bloque(false);
    int dir(0);

    //Game Loop
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); //Clear Window
        
        game.mainPlayerMovement();

        if(game.autoPlayerMovement(dir)){
            dir = (dir + 1) % 3;
        }

        for(auto& element : map){
            window.draw(element.second->getSprite());
        }
        

        window.display(); //Display Window
    }

    

    
    

    return 0;
}