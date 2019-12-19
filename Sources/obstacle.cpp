#include "../Headers/obstacle.hpp"
#include <iostream>
using namespace std;

    Obstacle::Obstacle(Position _position, string _type):
        Element(_position),
        type(_type){}

    string Obstacle::getType() const{
        return type;
    }

    void Obstacle::desc(){
        cout << "Je suis un obstacle à la position " << position.getCodePos() << endl;
    }

