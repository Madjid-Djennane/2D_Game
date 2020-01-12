#include "../Headers/carte.hpp"
//#include "../Headers/element.hpp"
/* 
#include "../Headers/guerrier.hpp"
#include "../Headers/obstacle.hpp"
#include "../Headers/objet.hpp"
 */

#include <map>


int main(int argc, char const *argv[]){
    
    Carte c = Carte("../maps/niveau1.txt");

   // c.descCarte();
    
    std::cout << "----------------------------------------------------" << std::endl;

    std::map<std::string, Element *> map = c.getMap();

    Element * g =  map["000000"];
    Guerrier * gg = static_cast<Guerrier *> (g); 
 
//    static_cast<Guerrier *> (g)->completeDesc

    gg->completeDesc();


/*     if (c.moveGuerrier(map["002003"],'o')) {
        c.descCarte();
    } else {
        std::cout << "déplacement interdit !" << std::endl; 
    }
 */

    
    
    std::cout << "----------------------------------------------------" << std::endl;


    /* std::cout << c.moveGuerrier((Guerrier *)c.getMap()["000000"],'e') << std::endl;
    
    c.descCarte();
 */
    c.~Carte();

    return 0;
}
