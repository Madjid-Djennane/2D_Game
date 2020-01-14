#include <SFML/Graphics.hpp>
#include "../Headers/guerrier.hpp"
//#include "../Headers/element.hpp"


#include <iostream>
using namespace std;

    //constructeur
    Guerrier::Guerrier(Position _position, string _nom, char _equipe,
                       int _capAtt, int _capDef, int _pointsVie, sf::Texture& TEMP_Texture):
        Element(_position),
        nom(_nom),
        equipe(_equipe),
        capAtt(_capAtt),
        capDef(_capDef),
        pointsVie(_pointsVie){

            //Initialise le sprite avec la texture
            _Sprite.setTexture(TEMP_Texture); 
            //initialise la position du sprite dans l'interface
            _Sprite.setPosition(_position.getX(), _position.getY()); 
            // Source de la texture (image) qui composera le sprite (x,y)
            sf::Vector2i _Source(1, Down); 
            //Rectangle par defaut qui composera le sprite
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); 
            //vitesse d'animation
            _AnimTime = sf::milliseconds(80); 
            //vitesse du joueur
            _Speed = 0.20; 

            //couleur du sprite selon l'équipe
            if(_equipe == 'g'){
                _Sprite.setColor(sf::Color::Red);
            } else {
                _Sprite.setColor(sf::Color::Blue);
            }
                
                
        }

    // retourne le nom de l'équipe 'g' ou 'h' 
    char Guerrier::getEquipe() const {
        return equipe;
    }
    // retourne le nom du guerrier
    std::string Guerrier::getNom() const {
        return nom;
    }
    // retourne la capacité d'attaque du guerrier
    int Guerrier::getCapAtt() const {
        return capAtt;
    }
    // retourne la capacité de défense du guerrier
    int Guerrier::getCapDef() const {
        return capDef;
    }
    // retourne les points de vie du guerrier
    int Guerrier::getPointsVie() const {
        return pointsVie;
    }
    // Met à jours les points de vie du guerrier
    void Guerrier::setPointsVie(int _points,char a) {
        if(a == 'p')
            pointsVie = pointsVie + _points;
        else 
            pointsVie = pointsVie - _points;    
    }
    // description
    void Guerrier::desc(){
        cout << "Je suis un guerrier de l'equipe "<< equipe <<
         " et je suis à la position : " << position.getCodePos() << endl;
    }
    // description complète
    void Guerrier::completeDesc() const{
        cout << "Guerrier : " << nom << endl;
        cout << "Equipe : " << equipe << endl;
        cout << "Capacité attaque : " << capAtt << endl;
        cout << "Capacité defense : " << capDef << endl;
        cout << "Points de vie : " << pointsVie << endl;
        cout << "Position : " << position.getX()<<","<<position.getY() << endl; 
    }
    // Met à jour la position du guerrier
    void Guerrier::setPos(int x, int y){
        position.setPosition(x,y);
    }


    // retourne _Sprite
    sf::Sprite Guerrier::getSprite() const{  
        return _Sprite;
    }

    //Mouvements du guerrier
    void Guerrier::moveUp(){
        _Source.y = Up; //Met '_Source.y' à 'Up' (_Direction Enum)
        _Sprite.move(0, -_Speed); //deplace le sprite du guerrier

        
        if(_AnimClock.getElapsedTime() > _AnimTime){
            //Rectangle du sprite
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); 

            //Animation
            _Source.x++;
            if(_Source.x * 64 >= _Sprite.getTexture()->getSize().x)
            {
                _Source.x = 0;
            }
            _AnimClock.restart();

        }
        // Mise à jours de la position du guerrier (dans l'objet lui même) après que 
        // le deplacement ait eu lieu 
        position.setPosition(_Sprite.getPosition().x,_Sprite.getPosition().y);

    }

    void Guerrier::moveDown(){
        _Source.y = Down; //Met '_Source.y' à 'Down' (_Direction Enum)
        _Sprite.move(0, _Speed); 

        if(_AnimClock.getElapsedTime() > _AnimTime){
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); 

            _Source.x++;
            if(_Source.x * 64 >= _Sprite.getTexture()->getSize().x)
            {
                _Source.x = 0;
            }
            _AnimClock.restart();

        }
        position.setPosition(_Sprite.getPosition().x ,_Sprite.getPosition().y);
    }

    void Guerrier::moveRight(){
        _Source.y = Right; 
        _Sprite.move(_Speed, 0); 
        
        if(_AnimClock.getElapsedTime() > _AnimTime){
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); 

            _Source.x++;
            if(_Source.x * 64 >= _Sprite.getTexture()->getSize().x)
            {
                _Source.x = 0;
            }
            _AnimClock.restart();
        
        }
        
        position.setPosition(_Sprite.getPosition().x,_Sprite.getPosition().y);
        
    }


    void Guerrier::moveLeft(){
        _Source.y = Left; 
        _Sprite.move(-_Speed, 0); 

        if(_AnimClock.getElapsedTime() > _AnimTime){
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); 

            _Source.x++;
            if(_Source.x * 64 >= _Sprite.getTexture()->getSize().x){
                _Source.x = 0;
            }
            _AnimClock.restart();
        }
        position.setPosition(_Sprite.getPosition().x,_Sprite.getPosition().y);
    }   

    //Met à jour la vitesse du guerrier
    void Guerrier::setSpeed(float TEMP_Speed, sf::Time TEMP__AnimTime) { 
        _Speed = TEMP_Speed;
        _AnimTime = TEMP__AnimTime;
    }

    //retourne un caractère qui identifie l'élément parmis les autres types (objet, obstacle)
    char Guerrier::getName() const{
        return equipe;
    }

