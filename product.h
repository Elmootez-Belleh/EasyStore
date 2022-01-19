#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;
/*!
 * \brief The Product class permet de repondre a la question:
 *  2.a) Créer la classe Produit avec ses variables membres, son constructeur et ses fonctions getters.
 */

class Product
{
 private:
  unsigned int productId; // identifiant unique
    string _titre;
    string _description;
    unsigned int _quantiteDisponible;
    double _prix;

public:
   //Constructeurs
    Product();
    Product(unsigned int productId,string _titre,string _description,
     unsigned int _quantiteDisponible, double _prix );

    //Setters

    void setQuantiteDisponible(unsigned int quantiteDisponible);
    void setProductId(unsigned int value);

    //Getters

    unsigned int getProductId() const;
    string getTitre() const;
    string getDescription() const;
   unsigned int getQuantiteDisponible() const;
    double getPrix() const;

    //Fonction membres

    string toString();


};

#endif // PRODUCT_H
