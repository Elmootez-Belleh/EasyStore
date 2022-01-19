#include "order.h"
#include <sstream>

unsigned int Order::getOrderId() const
{
    return orderId;
}

void Order::setOrderId(unsigned int value)
{
    orderId = value;
}

Client Order::getCilent() const
{
    return cilent;
}

void Order::setCilent(const Client &value)
{
    cilent = value;
}

string Order::getStatus() const
{
    return status;
}

void Order::setStatus(const string &value)
{
    status = value;
}

std::vector<Product> Order::getProducts() const
{
    return products;
}

void Order::addProduct(Product &p)
{
    this->products.push_back(p);
}

void Order::setProducts(const std::vector<Product> &value)
{
    products = value;
}
/*!
 * \brief Order::toString  cette fonction permet de surcharger l'opérateur << pour pouvoir afficher toutes les informations de la commande.
 * \return
 */
string Order::toString()
{
//6.f) Surcharger l'opérateur << pour pouvoir afficher toutes les informations de la commande.
    stringstream ss;

     ss<<orderId;
     ss<<";";
    ss<<cilent.toString();
     ss<<";";
     ss<<";";
    for(unsigned int i = 0; i < products.size(); i++)
    {
   ss<< products[i].toString();
    }
     ss<<";";
     ss<<status;
     return ss.str();

}
/*!
 * \brief Order::getProductOrderId cette methode permet de chercher l'idententiant d'un produit dans une commande
 * \param key l'index de l'article dans la commande
 * \return l'identifiant du produit dans le magasin
 */

unsigned int Order::getProductOrderId(unsigned int key)
{
    return this->products[key].getProductId();

}


/*!
 * \brief Order::toString  cette fonction permet de surcharger l'opérateur << pour pouvoir le sauvegarder toutes les informations de la commande dans un fichier.
 * \return
 */
string Order::toFile()
{
//8.b) Ecrire le code nécessaire à l'enregistrement et à la lecture des données (produits, clients et commandes) dans des fichiers.
    stringstream ss;

     ss<<orderId;
     ss<<";";
    ss<<cilent.getClientId();
     ss<<";";
    ss<<status;

     return ss.str();

}


Order::Order()
{

}
/*!
 * \brief Order::Oder c'est un constructeur permettant de creer une commande
 * \param _orderId Identifiant de la commande
 * \param _cilent l'objet client de la commande
 * \param _products un tableau de produits achetes par le client
 * \param _status l'etat de la commande pour voir si la commande (Ex : livrée / pas livrée).
 */
Order::Order( unsigned int orderId,Client _cilent, std::vector<Product> _products, string _status)
{
    this->orderId=orderId;
    this->cilent=_cilent;
    this->products=_products;
    this->status=_status;

}
