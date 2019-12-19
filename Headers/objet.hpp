#include "element.hpp"


#ifndef OBJET_HPP
#define OBJET_HPP

    class Objet : public Element{
        private :
            int points;
        public :
            Objet();
            Objet(Position,int);
            int getPoints() const;
            void setPoints(int);
            void desc();
            
    };

#endif