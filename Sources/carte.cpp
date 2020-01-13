#include <SFML/Graphics.hpp>
#include "../Headers/carte.hpp"

#include "../Headers/guerrier.hpp"
#include "../Headers/obstacle.hpp"
#include "../Headers/objet.hpp"
#include "../Headers/element.hpp"

#include<iostream>
#include<fstream>
#include<map>

using namespace std;


    Carte::Carte(std::string file, sf::Texture _player, sf::Texture _object,sf::Texture _obstacle):
        playerTexture(_player),
        objectTexture(_object),
        obstacleTexture(_obstacle){   

        ifstream infile(file);

        if(!infile){
            cout << "unable to open file !";
            exit(1);
        }
        
        string line;

        getline(infile,line);
        larg = stoi(line);

        std::cout << larg << std::endl;
        
        getline(infile,line);
        haut = stoi(line);

        std::cout << haut << std::endl;
        
        for(int i = 0; i< haut; i++){
            getline(infile,line);
            for(int j = 0; j<larg; j++){
                Carte::addElement(j,i,line[j]);
            }
            
        }
   
    }


    // renvoie le code d'une postion '00x00y' 

    string Carte::getCodePos(int x, int y){
       
        std::string sx = std::to_string(x);
        std::string sy = std::to_string(y);

        while(sx.size() < 4){
            sx = "0"+sx;
        }
        while(sy.size() < 4){
            sy = "0"+sy;
        }

        return sx+sy;
    }

    // retourne la map

    std::map<std::string,Element *> Carte::getMap(){
        return map;
    }

    // affiche la carte selon le fichier
    void Carte::displayMap(string file) const {

        ifstream infile(file);

        if(!infile){
            cout << "unable to open file !";
            exit(1);
        }
        
        string line;

        getline(infile,line);
        int larg = stoi(line);
        
        getline(infile,line);
        int haut = stoi(line);

        while(getline(infile,line,'\0')){
            cout << line << endl;
        }

    }

    // ajouter un l'element à la position (x,y) dans le fichier décrit par le caractère 'c'
    void Carte::addElement(int x, int y, char c){
        
        x = x*64;
        y = y*64;
        
        string codePos(Carte::getCodePos(x,y));


        if(c == 'g' || c =='h'){ 
            
            map.insert(make_pair(codePos,
            new Guerrier(Position(x,y),"guerrier",c,60,40,100,playerTexture) 
            ));

        }else if(c == '*'){
            
            map.insert(make_pair(codePos,
            new Obstacle(Position(x,y),"mur",obstacleTexture)
            
            ));

        }else if(c >= '0' && c <= '9'){

            map.insert(make_pair(codePos,
            new Objet(Position(x,y),(int)c - 48,objectTexture)
            
            ));
        }
    }


    // Déplacer un Guerrier

    bool Carte::moveGuerrier(Element * guerrier, int direction){
        
        // la position du guerrier dans l'interface
        int x = guerrier->getPosition().getX();
        int y = guerrier->getPosition().getY();


        switch (direction){
            case 0: //up
                y=y-16;   
                 for(int i=0; i <= 48; i++) {  
                    if(map.count(Carte::getCodePos(x-i,y-32)) > 0 ||
                       map.count(Carte::getCodePos(x+i,y-32)) > 0){
                        return false;
                        break;
                    }
                }        
                break;

            case 1: //left
                x=x-48;
                for(int i=0; i <= 48; i++) {
                    if(map.count(Carte::getCodePos(x,y+i))>0 || 
                        map.count(Carte::getCodePos(x,y-i)) > 0){

                        return false;
                        break;
                    }
                }
                for(int i=48; i <= 64; i++) {
                    if(map.count(Carte::getCodePos(x,y+i))>0){
                        return false;
                        break;
                    }
                }
                break;

            case 2: //down
                y=y+64;
                for(int i=0; i <= 48; i++) {
                    
                    if(map.count(Carte::getCodePos(x-i,y))>0 ||
                       map.count(Carte::getCodePos(x+i,y))>0){
                        return false;
                        break;
                    }
                }
                break;

            case 3: //right
                x=x+48;
                for(int i=0; i <= 48; i++) {
                    if(map.count(Carte::getCodePos(x,y-i))>0 ||
                       map.count(Carte::getCodePos(x,y+i))>0 ){
                        return false;
                        break;
                    }
                }    
                for(int i=48; i < 64; i++) {
                    if(map.count(Carte::getCodePos(x,y+i))>0){
                        return false;
                        break;
                    }
                }            
                break;

            default:
                return false;
                break;
        }



        // la position du guerrier sort de la carte : retourne false
        //std::cout << x << std::endl;
        if (x<0 || y<0) return false;
        if (x > (larg)*64 || y > (haut)*64) return false;

        return true;
    }

    // mise à jour de la position d'un guerrier dans la map

    void Carte::updateMap(Guerrier * guerrier, Position initPos) {
        
        string init = Carte::getCodePos(initPos.getX(), initPos.getY());
        string depl = Carte::getCodePos(guerrier->getPosition().getX(),
                                        guerrier->getPosition().getY());

        map.erase(init);
        map.insert(make_pair(depl,guerrier));                           
        
    }

    void Carte::descCarte() const {
        for(auto& element : map){
            cout << element.first << " ==>  ";
            element.second->desc();
            
        }
    }

    int Carte::getLarg() const {
        return larg;
    }

    int Carte::getHaut() const {
        return haut;
    }

    Carte::~Carte(){
        for(auto & element : map){
            delete(element.second);
            element.second = NULL;
        }
        cout << "map deleted" << endl;
    }