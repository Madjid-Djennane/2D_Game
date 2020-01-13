#include <SFML/Graphics.hpp>
#include "../Headers/obstacle.hpp"
#include <iostream>
using namespace std;

    Obstacle::Obstacle(Position _position, string _type, sf::Texture& TEMP_Texture):
        Element(_position),
        type(_type){
            _Sprite.setTexture(TEMP_Texture); 
            _Sprite.setPosition(_position.getX(), _position.getY());
            _Sprite.setTextureRect(sf::IntRect(0, 30, 64, 64)); 
            //_Sprite.setColor(sf::Color::Red);
        }

    string Obstacle::getType() const{
        return type;
    }

    void Obstacle::desc(){
        cout << "Je suis un obstacle à la position " << position.getCodePos() << endl;
    }

    sf::Sprite Obstacle::getSprite() const {
        return _Sprite;
    }

    char Obstacle::getName() const {
        return 'o';
    }

