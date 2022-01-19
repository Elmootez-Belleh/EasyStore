#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

using namespace std;

class Produit
{
private:
    string _titre;
    string _description;
    string _ID;
    int _quantiteDisponible;
    double _prix;
public:
    Produit();
    //Setters
    void setTitre();
    void setDescription();
    void setID();
    void setQuantiteDisponible();
    void setPrix();
    //Getters
    string getTitre();
    string getDescription();
    string getID();
    int getQuantiteDisponible();
    double getPrix();
    //Tostring
    std::string toString();


};

#endif // PRODUIT_H
