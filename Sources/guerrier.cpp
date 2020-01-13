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
            sf::Vector2i _Source(1, Down); //Default Sprite Sheet Crop
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); //Crop Sprite Sheet (Default Crop)
            _AnimTime = sf::milliseconds(80); //Animation Speed
            _Speed = 0.20; //Player Speed

            if(_equipe == 'g'){
                _Sprite.setColor(sf::Color::Red);
            } else {
                _Sprite.setColor(sf::Color::Blue);
            }
                
                
        }

    void Guerrier::fight(int direction) {

    }

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

    void Guerrier::setPointsVie(int _points,char a) {
        if(a == 'p')
            pointsVie = pointsVie + _points;
        else 
            pointsVie = pointsVie - _points;    
    }

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


    // retourne _Sprite
    sf::Sprite Guerrier::getSprite() const{  
        return _Sprite;
    }

    //PLAYER MOVEMENT
    void Guerrier::moveUp(){
        _Source.y = Up; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
        _Sprite.move(0, -_Speed); //Move Player Sprite

        if(_AnimClock.getElapsedTime() > _AnimTime)
        {
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); //Crop Sprite Sheet

            //Animation
            _Source.x++;
            if(_Source.x * 64 >= _Sprite.getTexture()->getSize().x)
            {
                _Source.x = 0;
            }
            _AnimClock.restart();

        }
        position.setPosition(_Sprite.getPosition().x,_Sprite.getPosition().y);

    }

    void Guerrier::moveDown(){
        _Source.y = Down; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
        _Sprite.move(0, _Speed); //Move Player Sprite

        if(_AnimClock.getElapsedTime() > _AnimTime)
        {
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); //Crop Sprite Sheet

            //Animation
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
        _Source.y = Right; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
        _Sprite.move(_Speed, 0); //Move Player Sprite
        
        if(_AnimClock.getElapsedTime() > _AnimTime)
        {
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); //Crop Sprite Sheet

            //Animation
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
        _Source.y = Left; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
        _Sprite.move(-_Speed, 0); //Move Player Sprite

        if(_AnimClock.getElapsedTime() > _AnimTime){
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); //Crop Sprite Sheet

            //Animation
            _Source.x++;
            if(_Source.x * 64 >= _Sprite.getTexture()->getSize().x){
                _Source.x = 0;
            }
            _AnimClock.restart();
        }
        position.setPosition(_Sprite.getPosition().x,_Sprite.getPosition().y);
    }   

    void Guerrier::setSpeed(float TEMP_Speed, sf::Time TEMP__AnimTime) { 
        _Speed = TEMP_Speed;
        _AnimTime = TEMP__AnimTime;
    }

    void Guerrier::updateSprite(int){

    }
    char Guerrier::getName() const{
        return equipe;
    }

