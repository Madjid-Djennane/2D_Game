#include <SFML/Graphics.hpp>
#include "../Headers/objet.hpp"
#include <iostream>
using namespace std;

    Objet::Objet(Position _position, int _points, sf::Texture& TEMP_Texture):
        Element(_position),
        points(_points){
            _Sprite.setTexture(TEMP_Texture); 
            _Sprite.setPosition(_position.getX(), _position.getY());
            _Sprite.setTextureRect(sf::IntRect(0, 30, 64, 64)); 
            _Sprite.setColor(sf::Color::Red);
        }

    void Objet::setPoints(int _points){
        points = _points;
    }

    int Objet::getPoints() const {
        return points;
    }

    void Objet::desc(){
        cout << "Je suis un objet ramassable à "<< points << 
        " points et je suis à la position " << position.getCodePos() << endl;
    }

    sf::Sprite Objet::getSprite() const {
        return _Sprite;
    }

    char Objet::getName() const {
        return 'a';
    }



