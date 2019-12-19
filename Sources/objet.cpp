#include "../Headers/objet.hpp"
#include <iostream>
using namespace std;

    Objet::Objet(Position _position, int _points):
        Element(_position),
        points(_points){}

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


