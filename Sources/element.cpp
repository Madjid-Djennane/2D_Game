#include <SFML/Graphics.hpp>
#include "../Headers/element.hpp"

    Element::Element(Position p) : position(p){
    }

    Position Element::getPosition(){
        return position;
    }

    void Element::desc(){
        std::cout << "Je suis un element"; 
    }

    void Element::setPos(int x, int y){}

    

