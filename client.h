#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "product.h"

using namespace std;

/*!
 * \brief The Client class cette classe nous permet de repondre a la question:
 * 4.a) Creer la classe Client avec ses variables membres (identifiant, prenom, nom, panier d'achat) et ses fonctions getters.

 */
class Client
{
private:
  unsigned int clientId; // identifiant unique
  string  FirstName;
  string  lastName ;
 std::vector<Product> basket;


public:
 //Constructeurs
    Client();
    Client(unsigned int _clientId,string  _FirstName,string  _lastName);

 //Setters

    void setClientId(unsigned int value);
    void setFirstName(const string &value);
    void setLastName(const string &value);
    void setBasket(const Product &value);

   //Getters

    std::vector<Product> getBasket() const;
    unsigned int getClientId() const;
    string getFirstName() const;
    string getLastName() const;

     //Fonction membres

    void clearBasket();
    void setQuantityForAProductInBasket(const unsigned int &_productId, const unsigned int &quantity);
    void deleteProductFromBasket(const unsigned int &_productId);
    string toStringWithBasket();
    string toString();

};

#endif // CLIENT_H
