#include "element.hpp"


#ifndef OBJET_HPP
#define OBJET_HPP

    class Objet : public Element{
        private :
            int points;
            sf::Sprite _Sprite;
        public :
            Objet();
            Objet(Position,int,sf::Texture &);
            int getPoints() const;
            void setPoints(int);
            void desc();
            sf::Sprite getSprite() const;
            char getName() const;
            
    };

#endif