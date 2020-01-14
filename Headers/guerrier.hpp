#include "element.hpp"
//#include "SFML"

#ifndef GUERRIER_HPP
#define GUERRIER_HPP

    class Guerrier : public Element{
        private :
            std::string nom;
            char equipe;
            int capAtt;
            int capDef;
            int pointsVie;
            
            sf::Sprite _Sprite; 
            sf::Vector2i _Source; 
            enum _Direction{ Up, Left, Down, Right }; 

            
            float _Speed; 
            sf::Clock _AnimClock; 
            sf::Time _AnimTime; 

        public :
            Guerrier();
            Guerrier(Position,std::string,char,int,int,int,sf::Texture&);
            std::string getNom() const;
            char getEquipe() const;
            int getCapAtt() const;
            int getCapDef() const;
            int getPointsVie() const;
            void setPointsVie(int,char);
            void setPos(int,int);
            void desc();
            void completeDesc() const;
            bool estAdversaire(Guerrier *);
            char getName() const;
            void updateSprite(int);
            void fight(int);
            void moveUp();
            void moveDown();
            void moveRight();
            void moveLeft();
            void setSpeed(float, sf::Time);
    
            
            sf::Sprite getSprite() const;

            
            
    };

#endif