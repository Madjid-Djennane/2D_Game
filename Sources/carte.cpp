#include "../Headers/carte.hpp"

#include "../Headers/guerrier.hpp"
#include "../Headers/obstacle.hpp"
#include "../Headers/objet.hpp"
#include "../Headers/element.hpp"

#include<iostream>
#include<fstream>
#include<map>

using namespace std;


    Carte::Carte(std::string file){
        
        ifstream infile(file);

        if(!infile){
            cout << "unable to open file !";
            exit(1);
        }
        
        string line;

        getline(infile,line);
        larg = stoi(line);
        
        
        getline(infile,line);
        haut = stoi(line);
        
        for(int i = 0; i< haut; i++){
            getline(infile,line);
            for(int j = 0; j<larg; j++){
                Carte::addElement(i,j,line[j]);
            }
            
        }
   
    }


    // renvoie le code d'une postion '00x00y' 

    string Carte::getCodePos(int x, int y){
       
        std::string sx = std::to_string(x);
        std::string sy = std::to_string(y);

        while(sx.size() < 3){
            sx = "0"+sx;
        }
        while(sy.size() < 3){
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
        
        string codePos(Carte::getCodePos(x,y));

        if(c == 'g' || c =='G'){

            //Guerrier guerrier = Guerrier(Position(x,y),"guerrier",c,60,40,100); 
            
            map.insert(make_pair(codePos,
            new Guerrier(Position(x,y),"guerrier",c,60,40,100) 
            
            ));

        }else if(c == '*'){
            Obstacle obstacle = Obstacle(Position(x,y),"mur"); 
            map.insert(make_pair(codePos,
            new Obstacle(Position(x,y),"mur")
            
            ));

        }else if(c >= '0' && c <= '9'){

            Objet objet = Objet(Position(x,y),(int)c - 48);
            map.insert(make_pair(codePos,
            new Objet(Position(x,y),(int)c - 48)
            
            ));
        }
    }


    // Déplacer un Guerrier

    bool Carte::moveGuerrier(Element * guerrier, char direction){
        
        int x = guerrier->getPosition().getX();
        int y = guerrier->getPosition().getY();

        string init = Carte::getCodePos(x,y);


        switch (direction){
            case 'n':
                x-- ;
                break;
            case 's':
                x++;
                break;
            case 'e':
                y++;
                break;
            case 'o':
                y--;
                break;        
            default:
                break;
        }

        // la position sort de la carte

        if (x<0 || y<0) return false;

        if (x > haut-1 || y > larg-1) return false;

        
        
        // Code de la position après le déplacement
        string depl = Carte::getCodePos(x,y);
        

        // Vérifier si le code appartient à la Map 
        // (Si c'est le cas il y'a un élément a cet emplacement)
        if(map.count(depl)  > 0) return false;

        // Le déplacement est possible

        guerrier->setPos(x,y);
 
        map[depl] = map[init];

        map.erase(init);
 
        return true;
    }

    void Carte::descCarte() const{
        for(auto& element : map){
            cout << element.first << " ==>  ";
            element.second->desc();
            
        }
    }

    Carte::~Carte(){
        for(auto & element : map){
            delete(element.second);
            element.second = NULL;
        }
        cout << "map deleted" << endl;
    }