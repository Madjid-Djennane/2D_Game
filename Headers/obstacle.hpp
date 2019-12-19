#include "element.hpp"

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

    class Obstacle : public Element{
        private :
            std::string type;
        public :
            Obstacle();
            Obstacle(Position,std::string);
            std::string getType() const;
            void desc();
    };

#endif