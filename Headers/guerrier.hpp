#include "element.hpp"


#ifndef GUERRIER_HPP
#define GUERRIER_HPP

    class Guerrier : public Element{
        private :
            std::string nom;
            char equipe;
            int capAtt;
            int capDef;
            int pointsVie;

        public :
            Guerrier();
            Guerrier(Position,std::string,char,int,int,int);
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
            
    };

#endif