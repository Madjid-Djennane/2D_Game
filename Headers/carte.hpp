#include <map>
#include "element.hpp"
#include "guerrier.hpp"
#ifndef CARTE_HPP
#define CARTE_HPP

class Carte{
    
    protected :

        int larg;
        int haut;
        std::map<std::string,Element *> map;
        void addElement(int, int ,char);
    
    public :
        Carte();
        Carte(std::string file); 
        std::string getCodePos(int x, int y);
        std::map<std::string,Element *> getMap();
        void displayMap(std::string file) const;
        bool moveGuerrier(Element *, char);
        void descCarte() const;
        //void setMap(std::string);
        ~Carte();

};


#endif