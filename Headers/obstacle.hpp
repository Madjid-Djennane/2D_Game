#include "element.hpp"

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

    class Obstacle : public Element{
        private :
            std::string type;
            sf::Sprite _Sprite;
        public :
            Obstacle();
            Obstacle(Position,std::string, sf::Texture &);
            std::string getType() const;
            void desc();
            
            sf::Sprite getSprite() const;
    };

#endif