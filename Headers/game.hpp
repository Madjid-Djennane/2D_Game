#include <SFML/Graphics.hpp>
#include<iostream>
#include "carte.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
        
    private :
        Carte * carte;
        Guerrier * mainPlayer;
        Guerrier * autoPlayer;

    public :
        Game();
        void mainPlayerMovement();
        bool autoPlayerMovement(int);
        std::map<std::string, Element *> getMap();
        ~Game();
        
        
};

#endif