#include <SFML/Graphics.hpp>
#include "../Headers/element.hpp"

/**
 * Classe mère de Guerrier, Objet et Obstacle 
 * 
 * */

    // Constructeur
    Element::Element(Position p) : position(p){
    }

    // Retourne la position de l'élément
    Position Element::getPosition(){
        return position;
    }

    // Décris l'élément sur la sortie standard
    void Element::desc(){
        std::cout << "Je suis un element"; 
    }

    // Met à jours la postion de l'élément
    void Element::setPos(int x, int y){}

    

