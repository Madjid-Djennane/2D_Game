#include <SFML/Graphics.hpp>
#include "../Headers/objet.hpp"
#include <iostream>
using namespace std;

    // Constructeur
    Objet::Objet(Position _position, int _points, sf::Texture& TEMP_Texture):
        Element(_position),
        points(_points){
            // Initialisation du sprite avec la texture passé en paramètre
            _Sprite.setTexture(TEMP_Texture); 
            //position du sprite dans l'interface
            _Sprite.setPosition(_position.getX(), _position.getY());
            //Choix de la texture (image) selon les points de l'objet
            if(_points % 2 == 0) {
                _Sprite.setTextureRect(sf::IntRect(653, 5, 64, 64)); 
            }else{
                _Sprite.setTextureRect(sf::IntRect(333, 259, 64, 64)); 
            }

        }

    // Met à jours les points de l'objet
    void Objet::setPoints(int _points){
        points = _points;
    }
    
    //getter
    int Objet::getPoints() const {
        return points;
    }
    // description de l'objet
    void Objet::desc(){
        cout << "Je suis un objet ramassable à "<< points << 
        " points et je suis à la position " << position.getCodePos() << endl;
    }

    //retourne le sprite de l'objet
    sf::Sprite Objet::getSprite() const {
        return _Sprite;
    }

    //retourne un caractère qui identifie l'élément parmis les autres types (guerrier, obstacle)
    char Objet::getName() const {
        return 'a';
    }



