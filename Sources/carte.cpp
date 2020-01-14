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

    /**
     * Classe Carte responsable du chargement du fichier de la map dans un conteneur, 
     * l'ajout, la mise à jour et la modification des élément de la 'map'
     * 
     **/

    //constructeur
    // Pour chaque élément dans le fichier le constructeur appelle Carte::addElement()
    // pour l'ajouter à la map
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


    // renvoie le code d'une postion '00x00y' sous forme de chaîne de caractères

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

    std::map<std::string,Element *>& Carte::getMap(){
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

        // ajouter un guerrier
        if(c == 'g' || c =='h'){ 
            
            map.insert(make_pair(codePos,
            new Guerrier(Position(x,y),"guerrier",c,60,40,100,playerTexture) 
            ));
        // ajouter un obstacle
        }else if(c == '*'){
            
            map.insert(make_pair(codePos,
            new Obstacle(Position(x,y),"mur",obstacleTexture)
            
            ));
        // ajouter un objet
        }else if(c >= '0' && c <= '9'){

            map.insert(make_pair(codePos,
            new Objet(Position(x,y),(int)c - 48,objectTexture)
            
            ));
        }
    }


    // Déplacer un Guerrier

    std::string Carte::moveGuerrier(Element * guerrier, int direction){
        
        // la position du guerrier dans l'interface 
        int x = guerrier->getPosition().getX();
        int y = guerrier->getPosition().getY();


        switch (direction){
            // si la direction est 0 (haut)
            case 0: //up
                //deplace le 'y' vers le haut 
                y=y-16;   
                // vérifie si il y'a un objet 96px à gauche et à droite ! 
                 for(int i=0; i <= 48; i++) {  
                    if(map.count(Carte::getCodePos(x-i,y-32)) > 0){
                        return Carte::getCodePos(x-i,y-32); //si on trouve, on renvoie le code de cette objet
                    }
                       if(map.count(Carte::getCodePos(x+i,y-32)) > 0){
                        return Carte::getCodePos(x+i,y-32);
                    }
                }
                // si la position sort de la carte on retourne "NULL"
                if (x<0 || y<0) return "NULL";
                if (x > (larg)*64 || y > (haut)*64) return "NULL";  
                //Si il n'y a aucun élément 16px en haut (48 à gauche et 48 à droite)
                // on retourne "OK" (le déplacement pourra se faire)
                return "OK";         
                break;

            case 1: //left
                x=x-48;
                for(int i=0; i <= 48; i++) {
                    if(map.count(Carte::getCodePos(x,y+i))>0){
                        return Carte::getCodePos(x,y+i);
                    } 
                    if(map.count(Carte::getCodePos(x,y-i)) > 0){

                        return Carte::getCodePos(x,y-i);
                    }
                }
                for(int i=48; i <= 64; i++) {
                    if(map.count(Carte::getCodePos(x,y+i))>0){
                        return Carte::getCodePos(x,y+i);
                        break;
                    }
                }
                if (x<0 || y<0) return "NULL";
                if (x > (larg)*64 || y > (haut)*64) return "NULL";  
                return "OK";  
                break;

            case 2: //down
                y=y+64;
                for(int i=0; i <= 48; i++) {
                    if(map.count(Carte::getCodePos(x-i,y))>0){
                        return Carte::getCodePos(x-i,y);
                    }
                    if(map.count(Carte::getCodePos(x+i,y))>0){
                        return Carte::getCodePos(x+i,y);    
                    }
                }
                if (x<0 || y<0) return "NULL";
                if (x > (larg)*64 || y > (haut)*64) return "NULL";  
                return "OK";          
                break;

            case 3: //right
                x=x+48;
                for(int i=0; i <= 48; i++) {
                    if(map.count(Carte::getCodePos(x,y-i))>0) {
                        return Carte::getCodePos(x,y-i);
                    } 
                    if(map.count(Carte::getCodePos(x,y+i))>0 ){
                        return Carte::getCodePos(x,y+i);
                    }
                }    
                for(int i=48; i < 64; i++) {
                    if(map.count(Carte::getCodePos(x,y+i))>0){
                        return Carte::getCodePos(x,y+i);
                    }
                }
                if (x<0 || y<0) return "NULL";
                if (x > (larg)*64 || y > (haut)*64) return "NULL";  
                return "OK";          
                break;

            default:
                return "NULL";
                break;
        }

        return "NULL";
    }

    // l'utilisateur prends l'objet (guerrier)

    void Carte::takeObject(Guerrier * guerrier, std::string position) {
        
        // récupére l'objet de la map grace a son code position
        Objet * objet = static_cast<Objet *> (map[position]);
        // récupére le point de l'objet
        int points(objet->getPoints());
        
        // si le point sont pair
        if(points % 2 == 0){
            guerrier->setPointsVie(10,'p'); // on ajoute au guerrier des points de vie
        }else{ //sinon
            guerrier->setSpeed(0.35, sf::milliseconds(80)); // oon ajoute de la vitesse
        }

        map[position] = NULL;
        map.erase(position); // suppression de l'objet après avoir été ramassé

        
    }


    // mise à jour de la position d'un guerrier dans la map
    void Carte::updateMap(Guerrier * guerrier, Position initPos) {
        
        // code position avant le déplacement
        string init = Carte::getCodePos(initPos.getX(), initPos.getY());
        // code position après le déplacement
        string depl = Carte::getCodePos(guerrier->getPosition().getX(),
                                        guerrier->getPosition().getY());

        // suppression de la position initiale
        map.erase(init);
        // réinsertion du pointeur guerrier dans la map avec comme clé le code de la position après le déplacement
        map.insert(make_pair(depl,guerrier));                           
        
    }

    // description
    void Carte::descCarte() const {
        for(auto& element : map){
            cout << element.first << " ==>  ";
            element.second->desc();
            
        }
    }

    // retourne la largeure du fichier
    int Carte::getLarg() const {
        return larg;
    }
    // retourne la hauteur du fichier
    int Carte::getHaut() const {
        return haut;
    }

    // suppression des pointeur dans la map
    Carte::~Carte(){
        for(auto & element : map){
            delete(element.second);
            element.second = NULL;
        }
        cout << "map deleted" << endl;
    }