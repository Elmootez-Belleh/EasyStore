/*!
   \brief Client
   4.a) Creer la classe Client avec ses variables membres (identifiant, prenom, nom, panier d'achat) et ses fonctions getters.

  */

#include "client.h"
#include <sstream>

void Client::setClientId(unsigned int value)
{
    clientId = value;
}

void Client::setFirstName(const string &value)
{
    FirstName = value;
}

void Client::setLastName(const string &value)
{
    lastName = value;
}
/*!
 * \brief Client::setBasket permet de modifier le contenu du pannier d'achat
 *
 * \param value
 */
void Client::setBasket(const Product &value)
{
   this->basket.push_back(value)  ;
}
/*!
 * \brief Client::setQuantityForAProductInBasket  est une méthode permettant de modifier
 * la quantité d'un produit ajouté au panier d'achat
 * \param _productId identifiant du produit dans le magasin
 * \param quantity quantite a modifier dans le panier du client
 */
void Client::setQuantityForAProductInBasket(const unsigned int &_productId, const unsigned int &quantity)

{
    for(unsigned int i = 0; i < this->basket.size(); i++)
    {
         if(this->basket[i].getProductId()==_productId)
             this->basket[i].setQuantiteDisponible(quantity);

    }

}
/*!
 * \brief Client::deleteProductFromBasket cette methode permettant de supprimer un produit du panier d'achat.
 * \param _productId parametre d'entree permetant d'identifier le produit a effacer
 */

void Client::deleteProductFromBasket(const unsigned int &_productId)

{
    for(unsigned int i = 0; i < this->basket.size(); i++)
    {
         if(this->basket[i].getProductId()==_productId)
             this->basket.erase(basket.begin()+i);


    }



}

/*!
 * \brief Client::clearBasket est une méthode helper permettant de vider le panier d'achat.
 */
void Client::clearBasket(){

 this->basket.clear()  ;
}


std::vector<Product> Client::getBasket() const
{
    return basket;
}
/*!
 * \brief Client::Client :ce constructeur permet de creer une instance de la classe Client
 * \param _clientId :identifiant du client
 * \param _FirstName :nom du client
 * \param _lastName :prenom du client
 */
unsigned int Client::getClientId() const
{
    return clientId;
}

string Client::getFirstName() const
{
    return FirstName;
}

string Client::getLastName() const
{
    return lastName;
}

Client::Client(unsigned int _clientId,string  _FirstName,string  _lastName)
{
  this->clientId = _clientId;
    this->FirstName   = _FirstName;
    this->lastName   =_lastName ;
}

Client::Client()
{


}
/*!
 * \brief Client::toString permet de surcharger l'opérateur << pour pouvoir afficher toutes les informations du client (incluant les produits du panier d'achat.
 * \return retoune une chaine de caractere permettant de la sauvegrader dans un fichier externe.
 */
string Client::toStringWithBasket()
{
           stringstream ss;
            ss<<clientId;
            ss<<";";
           ss<<FirstName;

            ss<<";";
            ss<<lastName;
             ss<<";";
            for(unsigned int i = 0; i < basket.size(); i++)
            {
           ss<< basket[i].toString();
            }


            return ss.str();

}
string Client::toString()
{
           stringstream ss;
            ss<<clientId;
            ss<<";";
           ss<<FirstName;
            ss<<";";
            ss<<lastName;
            return ss.str();

}
