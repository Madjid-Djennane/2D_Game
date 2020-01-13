#include<iostream>
#include "position.hpp"

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Element{
    protected :
        Position position;

    public : 
        Element();    
        Element(Position p);
        Position getPosition();
        virtual void desc();
        virtual void setPos(int,int);
        virtual sf::Sprite getSprite() const = 0;
        virtual char getName() const = 0; 
        
        
};


#endif