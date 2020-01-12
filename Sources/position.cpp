#include "../Headers/position.hpp"
#include <string>

    Position::Position(int _x, int _y) : x(_x), y(_y){}

    int Position::getX() const{
        return x;
    }

    int Position::getY() const{
        return y;
    }

    int Position::setPosition(int _x, int _y) {
        if(_x>=0 && _y>=0){
            x = _x;
            y =_y;
            return 1;
        }else{
            return -1;
        }
        
    }

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

    void Position::displayPosition() const{
        std::cout << "X = " << x << ", Y = " << y ;
    }
