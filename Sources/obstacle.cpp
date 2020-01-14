#include <SFML/Graphics.hpp>
#include "../Headers/obstacle.hpp"
#include <iostream>
using namespace std;

    //constructeur
    Obstacle::Obstacle(Position _position, string _type, sf::Texture& TEMP_Texture):
        Element(_position),
        type(_type){
            _Sprite.setTexture(TEMP_Texture); 
            _Sprite.setPosition(_position.getX(), _position.getY());
            _Sprite.setTextureRect(sf::IntRect(0, 30, 64, 64)); 
            //_Sprite.setColor(sf::Color::Red);
        }

    // retourne le type de l'obstacle
    string Obstacle::getType() const{
        return type;
    }
    //description
    void Obstacle::desc(){
        cout << "Je suis un obstacle à la position " << position.getCodePos() << endl;
    }
    //retourn le sprite de l'obstacle
    sf::Sprite Obstacle::getSprite() const {
        return _Sprite;
    }
    //retourne un caractère qui identifie l'élément parmis les autres types (guerrier, objet)
    char Obstacle::getName() const {
        return 'o';
    }

