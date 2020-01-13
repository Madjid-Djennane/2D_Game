#include "../Headers/game.hpp"
#include "../Headers/carte.hpp"
#include <map>

    Game::Game(){


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

        
        // Initialise la carte
        carte = new Carte("../maps/niveau1.txt", playerTexture, objectTexture, obstacleTexture);

        std::map<std::string, Element *> map = carte->getMap();

        carte->descCarte();

        // le joueur principale
        Element * guerrier1 =  map["00000000"];
        mainPlayer = static_cast<Guerrier *> (guerrier1);

        for(auto& element: map) {
            if(element.second->getName() == 'h') {
                autoPlayer = static_cast<Guerrier *> (element.second);  
                autoPlayer->setSpeed(0.10, sf::milliseconds(80));      
                break;
            }
        }

        /* 
        Element * guerrier2 = map["02880544"];
        autoPlayer = static_cast<Guerrier *> (guerrier2);
        autoPlayer->setSpeed(0.10, sf::milliseconds(80)); // initialise la vitesse du joueur 'auto' */
    


    }

    // Les déplacement du joueur controlé par l'utilisateur

    void Game::mainPlayerMovement() {
                //PLAYER MOVEMENT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //Move Up

            if(carte->moveGuerrier(mainPlayer,0)){
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveUp();
                carte->updateMap(mainPlayer,initPos);
            }
                

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //Move Down

            if(carte->moveGuerrier(mainPlayer,2)){
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveDown();
                carte->updateMap(mainPlayer,initPos);
            }
        } 
            
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ //Move Right

            if(carte->moveGuerrier(mainPlayer,3)) {
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveRight();
                carte->updateMap(mainPlayer,initPos);
            }
                
        } 
        
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ //Move Left
            
            if(carte->moveGuerrier(mainPlayer,1)){
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveLeft();
                carte->updateMap(mainPlayer,initPos);
            }
        }
    }

    // les déplacement du joueur controlé par le programme

    bool Game::autoPlayerMovement(int direction) {
        
        switch(direction) {
            case 0 : //up
                if(carte->moveGuerrier(autoPlayer,0)){
                    Position initPos = autoPlayer->getPosition();
                    autoPlayer->moveUp();
                    carte->updateMap(autoPlayer,initPos); 
                    return false;
                }
                return true;
                break;

            case 1 : //left
                if(carte->moveGuerrier(autoPlayer,1)){
                    Position initPos = autoPlayer->getPosition();
                    autoPlayer->moveLeft();
                    carte->updateMap(autoPlayer,initPos);
                    return false;
                }
                return true;
                break;

            case 2 : //down
                if(carte->moveGuerrier(autoPlayer,2)){
                    Position initPos = autoPlayer->getPosition();
                    autoPlayer->moveDown();
                    carte->updateMap(autoPlayer,initPos);
                    return false;
                }
                return true;
                break;

            case 3 : //right
                if(carte->moveGuerrier(autoPlayer,3)){
                    Position initPos = autoPlayer->getPosition();
                    autoPlayer->moveRight();
                    carte->updateMap(autoPlayer,initPos);
                    return false;
                }
                return true;
                break;

            default :
                return 0;
                break;    
        }
        
    }

    std::map<std::string, Element *> Game::getMap() {
        return carte->getMap();
    }


    Game::~Game() {
        std::cout << "===============" << std::endl;
        carte->descCarte();
        delete(carte);
        carte = NULL;
    }
