#include <SFML/Graphics.hpp>
#include<iostream>
#include "carte.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
        
    public :
        Carte * carte;
        Guerrier * mainPlayer;
        Guerrier * autoPlayer;
        

    public :
        int winWidth;
        int winHeight;
        Game();
        void mainPlayerMovement();
        bool autoPlayerMovement(int);
        void takeElement();
        std::map<std::string, Element *>& getMap();
        ~Game();
        
        
};

#endif