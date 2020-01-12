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
            
            sf::Sprite _Sprite; //Declare Player Sprite
            sf::Vector2i _Source; //Declare Source (Sprite Sheet Crop)
            enum _Direction{ Up, Left, Down, Right }; //Declare Direction Enumeration

            //ANIMATION DATA
            float _Speed; //Player Speed
            sf::Clock _AnimClock; //Player Animation Clock
            sf::Time _AnimTime; //Player Animation Time

        public :
            Guerrier();
            Guerrier(Position,std::string,char,int,int,int,sf::Texture&);
            std::string getNom() const;
            char getEquipe() const;
            int getCapAtt() const;
            int getCapDef() const;
            int getPointsVie() const;
            //void deplacerGuerrier(char, Carte);
            void setPos(int,int);
            void desc();
            void completeDesc() const;
            bool estAdversaire(Guerrier *);
            

            //PLAYER MOVEMENT FUNCTIONS
            void moveUp();
            void moveDown();
            void moveRight();
            void moveLeft();
            void setSpeed(float, sf::Time);
    
            //ACCESSOR FUNCTIONS
            sf::Sprite getSprite() const;

            
            
    };

#endif