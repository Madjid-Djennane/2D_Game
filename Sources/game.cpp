#include "../Headers/game.hpp"
#include "../Headers/carte.hpp"
#include <map>

    /**
     * Classe 'Game' qui implémente les méthode d'affichage et modification des mouvements 
     *  des guerriers
     * */
    
    
    // Constructeur
    Game::Game(){


        //Charger la texture des obstacles depuis une image
        sf::Texture obstacleTexture;
        if(!obstacleTexture.loadFromFile("../img/wall.png"))
            std::cout << "Texture Error" << std::endl;

        //Charger la texture des guerriers depuis une image
        sf::Texture playerTexture;
        if(!playerTexture.loadFromFile("../img/skeletons.png"))
            std::cout << "Texture Error" << std::endl;

        //Charger la texture des obstacles depuis une image
        sf::Texture objectTexture;
        if(!objectTexture.loadFromFile("../img/objects.png"))    
            std::cout << "Texture Error" << std::endl;

        
        // Initialise la carte avec un pointeur 
        carte = new Carte("../maps/niveau1.txt", playerTexture, objectTexture, obstacleTexture);
        // le conteneure 'map' de l'objet carte
        std::map<std::string, Element *> map = carte->getMap();

        // Initialisation de la largeure et hauteur du fichier pour calculer la taille de la fenêtre 
        winWidth = carte->getLarg();
        winHeight = carte->getHaut();

        // rechercher dans la 'map' le pointeur du guerrier dont l'équipe est 'h'
        // puis l'assigné à 'autoPlayer' (le guerrier gérer par le programme) 
        for(auto& element: map) {
            if(element.second->getName() == 'h') {
                autoPlayer = static_cast<Guerrier *> (element.second);  
                autoPlayer->setSpeed(0.16, sf::milliseconds(80));                      
            }
        }

        // initialiser le joueur contrôlé par l'utilisateur avec le guerrier de l'équipe 'g'
        // (sa position est prédéfinit dans le fichier)    
        mainPlayer = static_cast<Guerrier *> (map["00640000"]);
        mainPlayer->setSpeed(0.20,sf::milliseconds(80));

    }

    // Les déplacements du joueur controlé par l'utilisateur

    void Game::mainPlayerMovement() {

        //si l'utilisateur appuis sur (fléche haut)        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //Move Up
            // vérifie que l'utilisateur peux se deplacer dans cette direction
            std::string res(carte->moveGuerrier(mainPlayer,0)); 
            if(res == "OK"){ // si c'est ok
                Position initPos = mainPlayer->getPosition();
                // effectue le déplacement et met à jour l'objet lui-même (position dans guerrier)
                mainPlayer->moveUp();
                // Met à jour la 'map' 
                carte->updateMap(mainPlayer,initPos);
            }else if(res != "NULL"){ // sinon il y'a un (objet, obstacle, limite)
                if(carte->getMap()[res]->getName() == 'a'){ //vérifie si l'élément s'agit d'un objet  
                    carte->takeObject(mainPlayer, res); // l'utilisteur prend l'objet 'ramassable'
                }
            }
                
            // idem
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
            // idem
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
            // idem
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
             
            // le paramètre direction est à 0 (haut)
            if(direction == 0){ //up
                
                std::string res(carte->moveGuerrier(autoPlayer,0));
                    if(res == "OK"){// vérifie si le déplacement est faisable
                        Position initPos = autoPlayer->getPosition();
                        // effectue le deplacement et met à jour l'objet lui-même (position dans guerrier)
                        autoPlayer->moveUp();
                        // mise à jours du conteneur 'map'
                        carte->updateMap(autoPlayer,initPos); 
                        return false; //le guerrier à effectuer le déplacement 
                    }else if(res != "NULL"){ // si le deplacement est interdit
                        if(carte->getMap()[res]->getName() == 'a'){ // vérifie si ce n'est pas un objet 'ramassable'
                            carte->takeObject(autoPlayer, res); // ramasse l'objet
                            return false; //le guerrier à effectuer le déplacement 
                        }
                    }
                    return true; // si le déplacement n'a pas pu s'éffectuer

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




    // retourne une référnece vers le conteneur 'map' de l'objet carte
    std::map<std::string, Element *>& Game::getMap() {
        return carte->getMap();
    }

    // destruction du pointeur de carte
    Game::~Game() {
        delete(carte);
        carte = NULL;
    }
