#include<iostream>
#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
    private :
        int x;
        int y;

    public :
        Position();
        Position(int x, int y);
        int getX() const;
        int getY() const;
        int setPosition(int x, int y);
        std::string getCodePos() const;
        void displayPosition() const;
        
};


#endif