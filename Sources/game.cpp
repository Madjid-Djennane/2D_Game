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
        //Load Player fight Texture
        sf::Texture fightTexture;
        if(!fightTexture.loadFromFile("../img/skeletons2.png"))
            std::cout << "Texture Error" << std::endl;
        //Load Object Texture
        sf::Texture objectTexture;
        if(!objectTexture.loadFromFile("../img/objects.png"))    
            std::cout << "Texture Error" << std::endl;

        
        // Initialise la carte
        carte = new Carte("../maps/niveau1.txt", playerTexture, objectTexture, obstacleTexture);

        std::map<std::string, Element *> map = carte->getMap();

        winWidth = carte->getLarg();
        winHeight = carte->getHaut();

        for(auto& element: map) {
            if(element.second->getName() == 'h') {
                autoPlayer = static_cast<Guerrier *> (element.second);  
                autoPlayer->setSpeed(0.16, sf::milliseconds(80));                      
            }
        }
            
        mainPlayer = static_cast<Guerrier *> (map["00640000"]);
        mainPlayer->setSpeed(0.20,sf::milliseconds(80));

    }

    // Les déplacement du joueur controlé par l'utilisateur

    void Game::mainPlayerMovement() {
                //PLAYER MOVEMENT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //Move Up
            std::string res(carte->moveGuerrier(mainPlayer,0));
            if(res == "OK"){
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveUp();
                carte->updateMap(mainPlayer,initPos);
            }else if(res != "NULL"){
                if(carte->getMap()[res]->getName() == 'a'){
                    carte->takeObject(mainPlayer, res);
                }
            }
                

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //Move Down
            std::string res(carte->moveGuerrier(mainPlayer,2));
            if(res == "OK"){
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveDown();
                carte->updateMap(mainPlayer,initPos);
            }else if(res != "NULL"){
                if(carte->getMap()[res]->getName() == 'a'){
                    carte->takeObject(mainPlayer, res);
                }
            }
        } 
            
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ //Move Right
            std::string res(carte->moveGuerrier(mainPlayer,3));
            if(res == "OK") {
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveRight();
                carte->updateMap(mainPlayer,initPos);
            }else if(res != "NULL" ){
                if(carte->getMap()[res]->getName() == 'a'){
                    carte->takeObject(mainPlayer, res);
                }else{
                    
                }
            }
                
        } 
        
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ //Move Left
            std::string res(carte->moveGuerrier(mainPlayer,1));
            if(res == "OK"){
                Position initPos = mainPlayer->getPosition();
                mainPlayer->moveLeft();
                carte->updateMap(mainPlayer,initPos);
            }else if(res != "NULL"){
                if(carte->getMap()[res]->getName() == 'a'){
                    carte->takeObject(mainPlayer, res);
                }
            }
        }
    }

    // les déplacement du joueur controlé par le programme

    bool Game::autoPlayerMovement(int direction) {
             

            if(direction == 0){ //up
                
                std::string res(carte->moveGuerrier(autoPlayer,0));
                    if(res == "OK"){
                        Position initPos = autoPlayer->getPosition();
                        autoPlayer->moveUp();
                        carte->updateMap(autoPlayer,initPos); 
                        return false;
                    }else if(res != "NULL"){
                        if(carte->getMap()[res]->getName() == 'a'){
                            carte->takeObject(autoPlayer, res);
                            return false;
                        }
                    }
                    return true;

            }else if (direction == 1){ //left
                    std::string res(carte->moveGuerrier(autoPlayer,1));
                    if(res == "OK"){
                        Position initPos = autoPlayer->getPosition();
                        autoPlayer->moveLeft();
                        carte->updateMap(autoPlayer,initPos);
                        return false;
                    }else if(res != "NULL"){
                        if(carte->getMap()[res]->getName() == 'a'){
                            carte->takeObject(autoPlayer, res);
                            return false;
                        }
                    }
                    return true;

            }else if (direction == 2){ //down
                    std::string res(carte->moveGuerrier(autoPlayer,2));
                    if(carte->moveGuerrier(autoPlayer,2) == "OK"){
                        Position initPos = autoPlayer->getPosition();
                        autoPlayer->moveDown();
                        carte->updateMap(autoPlayer,initPos);
                        return false;
                    }else if(res != "NULL"){
                        if(carte->getMap()[res]->getName() == 'a'){
                            carte->takeObject(autoPlayer, res);
                            return false;
                        }
                    }
                    return true;

            }else if (direction == 3){ //right
                    std::string res(carte->moveGuerrier(autoPlayer,3));
                    if(carte->moveGuerrier(autoPlayer,3) == "OK"){
                        Position initPos = autoPlayer->getPosition();
                        autoPlayer->moveRight();
                        carte->updateMap(autoPlayer,initPos);
                        return false;
                    }else if(res != "NULL"){
                        if(carte->getMap()[res]->getName() == 'a'){
                            carte->takeObject(autoPlayer, res);
                            return false;
                        }
                    }
                    return true;
            }

    }





    std::map<std::string, Element *>& Game::getMap() {
        return carte->getMap();
    }


    Game::~Game() {
        delete(carte);
        carte = NULL;
    }
