#include "../Headers/guerrier.hpp"
#include "../Headers/carte.hpp"

#include <iostream>
using namespace std;

    Guerrier::Guerrier(Position _position, string _nom, char _equipe,
                       int _capAtt, int _capDef, int _pointsVie):
        Element(_position),
        nom(_nom),
        equipe(_equipe),
        capAtt(_capAtt),
        capDef(_capDef),
        pointsVie(_pointsVie){}

    char Guerrier::getEquipe() const {
        return equipe;
    }

    std::string Guerrier::getNom() const {
        return nom;
    }

    int Guerrier::getCapAtt() const {
        return capAtt;
    }

    int Guerrier::getCapDef() const {
        return capDef;
    }

    int Guerrier::getPointsVie() const {
        return pointsVie;
    }

    
/*     void Guerrier::deplacerGuerrier(char c, Carte carte){
        if(carte.moveGuerrier(this,c)){
            int x = position.getX();
            int y = position.getY();
            
            switch (c){
                case 'n':
                    position.setPosition(x--,y) ;
                    break;
                case 's':
                    position.setPosition(x++,y);
                    break;
                case 'e':
                    position.setPosition(x,y++);
                    break;
                case 'o':
                    position.setPosition(x,y--);
                    break;        
                default:
                    break;
            }

            // Code de la position après le déplacement
            string depl = carte.getCodePos(x,y);

            // carte.setMap()
            // [depl] = map[init];
            // map.erase(init); 
        }
    }
 */
    void Guerrier::desc(){
        cout << "Je suis un guerrier de l'equipe "<< equipe <<
         " et je suis à la position : " << position.getCodePos() << endl;
    }

    void Guerrier::completeDesc() const{
        cout << "Guerrier : " << nom << endl;
        cout << "Equipe : " << equipe << endl;
        cout << "Capacité attaque : " << capAtt << endl;
        cout << "Capacité defense : " << capDef << endl;
        cout << "Points de vie : " << pointsVie << endl;
        cout << "Position : " << position.getX()<<","<<position.getY() << endl; 
    }

    void Guerrier::setPos(int x, int y){
        position.setPosition(x,y);
    }


