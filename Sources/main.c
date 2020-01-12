#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Headers/carte.hpp"
#include <map>

int main() {

        //Load obstacle Texture
    sf::Texture obstacleTexture;
    if(!obstacleTexture.loadFromFile("../img/wall.png"))
        std::cout << "Texture Error" << std::endl;
    //Load Player Texture
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("../img/skeletons.png"))
        std::cout << "Texture Error" << std::endl;
    //Load Object Texture
    sf::Texture objectTexture;
    if(!objectTexture.loadFromFile("../img/wall.png"))    
        std::cout << "Texture Error" << std::endl;

    

    Carte c = Carte("../maps/niveau1.txt", playerTexture, objectTexture, obstacleTexture);
    std::map<std::string, Element *> map = c.getMap();

    int winWidth(c.getLarg()*64);
    int winHeigth(c.getHaut()*64);
    


    Element * g =  map["00320032"];
    Guerrier * player = static_cast<Guerrier *> (g);

    //c.descCarte();

    //Window
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeigth), "Testing");
    window.setKeyRepeatEnabled(false);

    //Game Loop
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); //Clear Window
        
        //PLAYER MOVEMENT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //Move Up

            if(c.moveGuerrier(g,0)){
                Position initPos = player->getPosition();
                player->moveUp();
                c.updateMap(player,initPos);
            }
                

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //Move Down

            if(c.moveGuerrier(g,2)){
                Position initPos = player->getPosition();
                player->moveDown();
                c.updateMap(player,initPos);
            }
        } 
            
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ //Move Right

            if(c.moveGuerrier(g,3)) {
                Position initPos = player->getPosition();
                player->moveRight();
                c.updateMap(player,initPos);
            }
                
        } 
        
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ //Move Left
            
            if(c.moveGuerrier(g,1)){
                Position initPos = player->getPosition();
                player->moveLeft();
                c.updateMap(player,initPos);
            }
        } 


        for(auto& element : map){
            window.draw(element.second->getSprite());
        }
        

        window.display(); //Display Window
    }

    return 0;
}