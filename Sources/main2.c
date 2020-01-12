#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char const *argv[]){
    ifstream infile("../maps/niveau1.txt");

    if(!infile){
        cout << "unable to open file !";
        exit(1);
    }
    
    string line;

    getline(infile,line);
    int larg(stoi(line));
    
    getline(infile,line);
    int haut(stoi(line));
    
    for(int i = 0; i< haut; i++){
        getline(infile,line);

        for(int j = 0; j<larg; j++){
            cout<<"position ("<< i <<","<<j<<")"<<":"<<line[j]<<endl; 
        }
        
        cout<<endl;
        //cout << "ligne " << i<< " :" << line << endl;
    }


   // cout<<larg << "  " << haut << endl << larg + haut << endl;

    return 0;
}
