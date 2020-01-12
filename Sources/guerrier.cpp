#include <SFML/Graphics.hpp>
#include "../Headers/guerrier.hpp"
//#include "../Headers/element.hpp"


#include <iostream>
using namespace std;

    Guerrier::Guerrier(Position _position, string _nom, char _equipe,
                       int _capAtt, int _capDef, int _pointsVie, sf::Texture& TEMP_Texture):
        Element(_position),
        nom(_nom),
        equipe(_equipe),
        capAtt(_capAtt),
        capDef(_capDef),
        pointsVie(_pointsVie){

            //PLAYER SPRITE
            _Sprite.setTexture(TEMP_Texture); //Set Sprite Texture
            _Sprite.setPosition(_position.getX(), _position.getY()); //Set Sprite Position (Centre)
            //_Sprite.setScale(1.5f, 1.5f); //Sprite Scale
            sf::Vector2i _Source(1, Down); //Default Sprite Sheet Crop
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 64, _Source.y * 64, 64, 64)); //Crop Sprite Sheet (Default Crop)
            //_Sprite.setTextureRect(sf::IntRect(0,0,64,64));
            //PLAYER / ANIMATION SPEED
            _AnimTime = sf::milliseconds(80); //Animation Speed
            _Speed = 0.20; //Player Speed

            if(_equipe == 'g'){
                _Sprite.setColor(sf::Color::Red);
            } else {
                _Sprite.setColor(sf::Color::Blue);
            }
                
                
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


        //ACCESSOR FUNCTIONS
    sf::Sprite Guerrier::getSprite() const{  //Player Sprite
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
        position.setPosition(_Sprite.getPosition().x + 32,_Sprite.getPosition().y+ 32);

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
        position.setPosition(_Sprite.getPosition().x +32 ,_Sprite.getPosition().y +32);
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
        
        position.setPosition(_Sprite.getPosition().x +32,_Sprite.getPosition().y +32);
        
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
        position.setPosition(_Sprite.getPosition().x+32,_Sprite.getPosition().y+32);
    }   

    void Guerrier::setSpeed(float TEMP_Speed, sf::Time TEMP__AnimTime) { //Sprint Speed
        _Speed = TEMP_Speed;
        _AnimTime = TEMP__AnimTime;
    }

