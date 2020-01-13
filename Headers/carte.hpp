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
        sf::Texture playerTexture;
        sf::Texture objectTexture;
        sf::Texture obstacleTexture; 
    
    public :
        Carte();
        Carte(std::string file, sf::Texture, sf::Texture, sf::Texture); 
        std::string getCodePos(int x, int y);
        std::map<std::string,Element *>& getMap();
        void displayMap(std::string file) const;
        std::string moveGuerrier(Element *, int);
        void takeObject(Guerrier *, std::string);
        void descCarte() const;
        int getLarg() const;
        int getHaut() const;
        void updateMap(Guerrier *,Position);
        //void setMap(std::string);
        ~Carte();

};


#endif