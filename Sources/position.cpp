#include "../Headers/position.hpp"
#include <string>

    //constructeur
    Position::Position(int _x, int _y) : x(_x), y(_y){}

    // retourne x
    int Position::getX() const{
        return x;
    }
    // retourne y
    int Position::getY() const{
        return y;
    }

    // Met à jour la position
    int Position::setPosition(int _x, int _y) {
        if(_x>=0 && _y>=0){
            x = _x;
            y =_y;
            return 1;
        }else{
            return -1;
        }
        
    }

    // retourne un code 'string' pour une position donné
    // le 'string' est construit sur 8 positions. 4 positions pour chaque élément 
    std::string Position::getCodePos() const {
       
        std::string sx = std::to_string(x);
        std::string sy = std::to_string(y);

        while(sx.size() < 4){
            sx = "0"+sx;
        }
        while(sy.size() < 4){
            sy = "0"+sy;
        }

        return sx+sy;
    }

    //description
    void Position::displayPosition() const{
        std::cout << "X = " << x << ", Y = " << y ;
    }
