#include <iostream>
#include "magasin.h"
#include <sstream>
#include "client.h"
#include "product.h"
#include "order.h"
using namespace std;

static Client client;

/*!
 * \brief Magasin::Magasin constructeur vide de la classe Magasin
 */
std::vector<Order> Magasin::orders() const
{
    return _orders;
}

Magasin::Magasin()
{

}
/*!
 * \brief Magasin::Magasin constructeur de la classe Magasin reponse a la question
 * 1.a) Créer la classe Magasin avec ses variables membres, son constructeur
 * \param p parametre d'entree de type Produt pour etre sauvegarde dans le vecteur mombre de _products
 * \param c parametre d'entree de type Client pour etre sauvegarde dans le vecteur mombre de _clients
 * \param o parametre d'entree de type Order pour etre sauvegarde dans le vecteur mombre de _orders
 */

Magasin::Magasin( Product p,  Client  c,  Order  o )
{
  this->_products.push_back(p);
  this->_clients.push_back(c);
  this->_orders.push_back(o);
}

/*!
 * \brief Magasin::setOrders methode setter de variable membre de la class magasin
 * \param order est la variable membre de type Order
 */
void Magasin::setOrders(const  Order &order)
{
    _orders.push_back(order);
}

/*!
 * \brief Magasin::setOrders methode setter de variable membre de la class magasin
 * \param order est la variable membre de type Order
 */
void Magasin::updateOrders(unsigned int key, const  Order &order)
{
    _orders[key]=order;
}

/*!
 * \brief Magasin::productNumberInOrder methode permettant de chercher le nombre d'elements d'un article d'une commande
 * \param key est l'index de la commande
 */
unsigned int Magasin::productNumberInOrder(unsigned int key)
{
   return _orders[key].getProducts().size();

}


/*!
 * \brief Magasin::setClients methode setter de variable membre de la class magasin
 * \param order est la variable membre de type Client
 */
void Magasin::setClients(const Client &client)
{
    _clients.push_back(client) ;
}
/*!
 * \brief Magasin::setProducts methode setter de variable membre de la class magasin
 * \param product est la variable membre de type Product
 */
void Magasin::setProducts(const Product &product)
{
    _products.push_back(product);
}
/*!
 * \brief Magasin::products methode getter de retourner le tableau de _produits dans le magasin
 * \param product est un table de products
 */
std::vector<Product> Magasin::products() const
{
    return _products;
}

/*!
 * \brief Magasin::newClient cette fonction permet d'ajouter un nouveau client au magasin,
 * pour garentir l'unicite nous devons comparer l'identifiant
 * du client a celui de dernier client enregistre au magasin
 * \param c
 */
void Magasin::newClient(Client *c)
{
    //5.a) Ajouter à la classe Magasin une méthode ou une fonction helper permettant d'ajouter un nouveau client au magasin.

     if (!c->getClientId()){
         unsigned int id=nextClientKey();
         c->setClientId(id);
         _clients.push_back(*c);
     }
     else {
            _clients.push_back(*c);
     }

}

/*!
 * \brief Magasin::newOrder cette fonction permet d'ajouter une nouvelle commande au magasin,
 * pour garentir l'unicite nous devons comparer l'identifiant
 * du client a celui de dernier client enregistre au magasin
 * \param c
 */
void Magasin::newOrder(Order *o)
{
    //5.a) Ajouter à la classe Magasin une méthode ou une fonction helper permettant d'ajouter un nouveau client au magasin.

     if (!o->getOrderId()){
         unsigned int id=nextOrderKey();
         o->setOrderId(id);
         _orders.push_back(*o);
     }
     else {
            _orders.push_back(*o);
     }

}


/*!
   * \brief Magasin::AddProductToBasket cette methode permet d'ajouter un produit a un client
   * la fonction commence par chercher le client dans le magasin en utilisant une boucle for,
   * une fois trouve, elle cherche le produit dans une boucle imbriquee pour selection l'objet
   * produit. dans la derniere etape en ajoute le produit trouve dans le pannier du client par fonction
   * setBasket membre de la classe Client.
   * \param _clientId parametre de recherche contenant l'identifiant du client
   * \param _productId parametre de recherche contenant l'identifiant du client
   * \return la valeur de retour nous permet d'afficher un message a l'utilisateur
   */

  int Magasin::AddProductToBasket(unsigned int _clientId, unsigned int  _productId, unsigned int quantity)
{
      //5.d) Ecrire une méthode ou une fonction helper
      //permettant d'ajouter un produit au panier d'achat d'un client.
      int result=0;
      for(unsigned int i = 0; i < _clients.size(); i++)
      {
          if(_clients[i].getClientId()==_clientId)
          {
              for(unsigned int j = 0; j < _products.size(); j++)
              {
                  if(_products[j].getProductId()==_productId)
                  {

                      _clients[i].setBasket(_products[j]);
                      _clients[i].setQuantityForAProductInBasket(_productId,quantity);

                      result=1;
                      break;
                  }
              }

          }
      }


  return  result;
}
  /*!
   * \brief Magasin::modifyProductQuantityInBasket Cette méthode permet de modifier la quantite d'un produit existant dans le panier d'achat d'un client.
   * dans un premier temps la methode cherche le client dans le magasin par son identifiant, en suite elle
   * appelle une fonction membre de la classe client pour chercher le produit par son identifiant et modifier sa quantite
   * \param _clientId l'identifiant du client
   * \param _productId identifiant du produit
   * \param quantity la quantite de produit
   * \return  la valeur de retour nous permet d'afficher un message a l'utilisateur
   */

  int Magasin::modifyProductQuantityInBasket(unsigned int _clientId, unsigned int  _productId, unsigned int quantity)
{
  //5.f) Ecrire une méthode ou une fonction helper permettant de modifier la quantité d'un produit du panier d'achat d'un client.

      int result=0;
      for(unsigned int i = 0; i < _clients.size(); i++)
      {
          if(_clients[i].getClientId()==_clientId)
          {
             // for(unsigned int j = 0; j < _products.size(); j++)
            //  {
                //  if(_products[j].getProductId()==_productId)
                 // {

                    //  _clients[i].setBasket(_products[j]);
                      _clients[i].setQuantityForAProductInBasket(_productId,quantity);
                      result=1;
                      break;
                //  }
            //  }
                               // cout << _products[i].toString() << endl;
          }
      }


  return  result;
}


  /*!
   * \brief Magasin::clearBasket est une méthode helper permettant de vider le panier d'achat d'un client.
   * \param _clientId parametre de selection du client a qui nous allons vider son panier
   * \return la valeur de retour permet d'informer l'utilisateur sur l'etat de l'operation
   */
  int Magasin::clearBasket(unsigned int _clientId)
{
      int result=0;
      for(unsigned int i = 0; i < _clients.size(); i++)
      {
          if(_clients[i].getClientId()==_clientId)
          {

                  _clients[i].clearBasket();
                      result=1;
                      break;

          }
      }


  return  result;
}
  /*!
   * \brief Magasin::deleteProductFromBasket Cette méthode permet de supprimer un produit au panier d'achat d'un client.
   * dans un premier temps la methode cherche le client dans le magasin par son identifiant, en suite elle
   * appelle une fonction membre de la classe client pour chercher le produit par son identifiant pour le retirer
   * \param _clientId Identifiant du client
   * \param _productId Identifiant du produit a retirer du panier
   * \return  la methode retourne un entier pour la bonne gestion des messages de l'utilisateur
   */

  int Magasin::deleteProductFromBasket(unsigned int _clientId, unsigned int  _productId)
{
     // 5.e) Ecrire une méthode ou une fonction helper permettant de supprimer un produit au panier d'achat d'un client.
        int result=0;
        for(unsigned int i = 0; i < _clients.size(); i++)
        {
            if(_clients[i].getClientId()==_clientId)
            {
                _clients[i].deleteProductFromBasket(_productId);
                result=1;
                break;
            }
        }



         return  result;

}
  /*!
   * \brief Magasin::displayProductOfAClient affiche des information sur le client ainssi que
   * le contenu de son panier
   * \param _clientId Identifiant du client
   * \return retourne un entier permettant de savoir le reussite de l'operation
   */

  //7.d) Ajouter une méthode ou une fonction helper permettant d'afficher toutes les commandes d'un client donné.
  /*!
   * \brief Magasin::displayOrderOfAClient cette methode permet d'afficher toutes les commandes d'un client donné.
   * \param _clientId parametre d'entree permettant de selectionner tous les commandes d'un client
   */
  void Magasin::displayOrderOfAClient(unsigned int _clientId)
      {
        std::vector<Order> v=findOrdersByClientId(_clientId);
        for(unsigned int i = 0; i < v.size(); i++)
            cout<<v[i].toString()<<endl;
       }

  /*!
   * \brief Magasin::displayProductOfAClient cette methode permet d'afficher les produits selectionees dans le panier de client
   * \param _clientId identifiant du client
   * \return valeur de retour qui nous permet d'afficher un message a l'utilisateur
   */

  int Magasin::displayProductOfAClient(unsigned int _clientId)
{
        int result=0;
        for(unsigned int i = 0; i < _clients.size(); i++)
        {
            if(_clients[i].getClientId()==_clientId)
            {
             cout<<_clients[i].toStringWithBasket()<<endl;
                result=1;
                break;
            }
        }



         return  result;

}

/*!
 * \brief Magasin::newProduct cette fonction permet d'ajouter un nouveau Produit au magasin,
 * pour garentir l'unicite nous devons compare l'identifiant s'il est a zeor cela veut dire
 * que le produit est nouveau au magasin
 * \param p c'est un objet de type Product
 */
void Magasin::newProduct(Product *p)
{
      if (!p->getProductId())
      {
          unsigned int id=nextProductKey();
          p->setProductId(id);
          _products.push_back(*p);

      }
      else {
             _products.push_back(*p);
      }
}
/*!
 * \brief Magasin::diplayAllProducts: Reponse a la question 3.b) Ecrire une méthode ou une fonction helper permettant
 * d'afficher à l'écran tous les produits référencés dans le magasin.
 * cette fonction permet de parcourir le tableau produits et d'afficher son contenu.
 */
void Magasin::diplayAllProducts()
{

     for(unsigned int i = 0; i < _products.size(); i++) // D’ailleurs, i++ ou ++i ?
                               cout << _products[i].toString() << endl;


}
/*!
 * \brief Magasin::diplayAllOrders  cette  méthode permet  d'afficher toutes les commandes passées.
 */

void Magasin::diplayAllOrders()
{
    //7.c) Ajouter une méthode ou une fonction helper permettant d'afficher toutes les commandes passées.
//6.f) Surcharger l'opérateur << pour pouvoir afficher toutes les informations de la commande.
     for(unsigned int i = 0; i < _orders.size(); i++) // D’ailleurs, i++ ou ++i ?
                               cout << _orders[i].toString() << endl;

}
/*!
 * \brief Magasin::diplayAllOrdersByState  reponse a la question 7.c) Ajouter une méthode ou une fonction helper permettant d'afficher toutes les commandes passées.
 * \param state parametre specifiant l'etat des commandes a afficher
 */
void Magasin::diplayAllOrdersByState(string state)
{
    //7.c) Ajouter une méthode ou une fonction helper permettant d'afficher toutes les commandes passées.
      for(unsigned int i = 0; i < _orders.size(); i++) // D’ailleurs, i++ ou ++i ?
        {
          if (_orders[i].getStatus()==state)
          cout << _orders[i].toString() << endl;
          }
}

/*!
 * \brief Magasin::diplayAllClients Cette méthode permet d'afficher à l'écran tous les clients du magasin.
 */
void Magasin::diplayAllClients()
{
    //5.b) Ecrire une méthode ou une fonction helper permettant d'afficher à l'écran tous les clients du magasin.

     for(unsigned int i = 0; i < _clients.size(); i++) // D’ailleurs, i++ ou ++i ?
                               cout << _clients[i].toString() << endl;

}

/*!
 * \brief Magasin::diplayProductsByName: 3.c) Ecrire une méthode ou une fonction helper permettant d'afficher à l'écran un produit sélectionné par son nom.
 * \param ptitle: c'est le nom du produit qui servira comme critere de selection du produit a afficher s'il existe
 */
void Magasin::diplayProductsByName(string ptitle)
{

     for(unsigned int i = 0; i < _products.size(); i++)
     {
         if(_products[i].getTitre()==ptitle)
                               cout << _products[i].toString() << endl;
     }

}
/*!
 * \brief Magasin::updateProductsByQuantityByName: 4.c) Ecrire une méthode ou une fonction helper permettant de mettre
 * à jour la quantité d'un produit sélectionné par son nom.
 * \param ptitle: nom du produit
 * \param new_quantity: nouvelle quantite a mettre a jour dans le tableau de produits
 */

void Magasin::updateProductsByQuantityByName(string ptitle, unsigned int new_quantity)
{
     for(unsigned int i = 0; i < _products.size(); i++)
     {
         if(_products[i].getTitre()==ptitle){
             _products[i].setQuantiteDisponible(new_quantity);
             cout << _products[i].toString() << endl;
         }
     }

}


/*!
 * \brief Magasin::nextProductkey cette methode permet de generer un nouveau identifiant du Product
 * \return la valeur de retour est un entier garantissant l'unicite de l'identifiant du produit dans le tableau des produits
 */
unsigned int Magasin::nextProductKey() const
{
    return _products.size()+1;
}
/*!
 * \brief Magasin::nextClientKey cette methode permet de generer un nouveau identifiant du Client
 * \return la valeur de retour est un entier garantissant l'unicite de l'identifiant du Client dans le tableau des clients
 */
unsigned int Magasin::nextClientKey() const
{
    return _clients.size()+1;
}
/*!
 * \brief Magasin::nextOrderKey cette methode permet de generer un nouveau identifiant du Order
 * \return la valeur de retour est un entier garantissant l'unicite de l'identifiant du commande dans le tableau des orders
 */
unsigned int Magasin::nextOrderKey() const
{
    return _orders.size()+1;
}
/*!
 * \brief Magasin::clients cette methode est un getter de la classe permettant de retourner le tableau de clients
 * \return la valeur de retour est le tableau des clients dans le magasin
 */
std::vector<Client> Magasin::clients() const
{
    return _clients;
}
/*!
 * \brief Magasin::nextClientKey cette fonction permet de verifier si le client est deja enregistre au magasin ou non
 *si oui la fonction retourne son identifiant autrement la fonction genere un nouveau identifiant pour garantir l'unicite des clients
 * dans le magasin
 * \param fname premier critere de rechereche par le nom
 * \param lname premier critere de rechereche par le prenom
 * \return retourne l'identifiant du client s'il existe dans le magasin
 * ou zero s'il n'existe pas.
 */
unsigned int Magasin::findClientByName(string fname, string lname) const
{
    unsigned int key=0;
    for(unsigned int i = 0; i < _clients.size(); i++)
    {
        if(_clients[i].getFirstName()==fname && _clients[i].getLastName()==lname){
            key=_clients[i].getClientId();
          //  cout << _clients[i].toString() << endl;
        }

    }

    return key;
}
/*!
 * \brief Magasin::findClientById cette methode permet d'afficher à l'écran un client sélectionné par son identifiant.

 * \param id
 * \return un objet de type Client resultat de la recherche
 */
Client Magasin::findClientById(unsigned int id) const
{
    //5.c)  Ecrire une méthode ou une fonction helper permettant d'afficher à l'écran un client sélectionné par son nom ou son identifiant.

    Client *c=new Client();
    for(unsigned int i = 0; i < _clients.size(); i++)
    {
        if(_clients[i].getClientId()==id){
            *c=_clients[i];
           cout<< c->toString()<<endl;

        }

    }

    return *c;
}
/*!
 * \brief Magasin::findProductById cette methode permet d'afficher à l'écran un produit sélectionné par son identifiant.

 * \param id
 * \return un objet de type Product resultat de la recherche
 */
Product Magasin::findProductById(unsigned int id) const
{
    //5.c)  Ecrire une méthode ou une fonction helper permettant d'afficher à l'écran un client sélectionné par son nom ou son identifiant.

    Product *p=new Product();
    for(unsigned int i = 0; i < _products.size(); i++)
    {
        if(_products[i].getProductId()==id){
            *p=_products[i];
          // cout<< c->toString()<<endl;
break;
        }

    }

    return *p;
}




/*!
 * \brief Magasin::findOrderByCientIdAndOrderId cette methode permet d'afficher à l'écran une commande sélectionné par son identifiant.

 * \param orderId critere de recherche par identifiant de la commande
 * \param clientId critere de recherche par identifiant du client
 * \return la valeur de retour est objet de type Order resultat de la recherche
 */
Order Magasin::findOrderByCientIdAndOrderId(unsigned int orderId,unsigned int clientId ) const
{
    //5.c)  Ecrire une méthode ou une fonction helper permettant d'afficher à l'écran un client sélectionné par son nom ou son identifiant.

    Order *o=new Order();
    for(unsigned int i = 0; i < _orders.size(); i++)
    {
        if(_orders[i].getOrderId()==orderId && _orders[i].getCilent().getClientId()==clientId){
            *o=_orders[i];
         //  cout<< o->toString()<<endl;

        }

    }

    return *o;
}
/*!
 * \brief Magasin::findOrderByCientIdAndOrderId cette methode permet d'afficher à l'écran une commande sélectionné par son identifiant.

 * \param orderId critere de recherche par identifiant de la commande

 * \return la valeur de retour est objet de type Order resultat de la recherche
 */
Order Magasin::findOrderById(unsigned int orderId) const
{
    //5.c)  Ecrire une méthode ou une fonction helper permettant d'afficher à l'écran un client sélectionné par son nom ou son identifiant.

    Order *o=new Order();
    for(unsigned int i = 0; i < _orders.size(); i++)
    {
        if(_orders[i].getOrderId()==orderId){
            *o=_orders[i];
         //  cout<< o->toString()<<endl;
break;
        }

    }

    return *o;
}

/*!
 * \brief Magasin::findOrdersByCientId cette methode permet de chercher tous les commandes d'un client
 * \param clientId parametre d'entree permettant de selection le client a l'interieur du tableau des commandes
 * \return la valeur de retour est un tableau de commande verifiant le critere de selection ou 0
 */

std::vector<Order> Magasin::findOrdersByClientId(unsigned int clientId ) const
{
    //5.c)  Ecrire une méthode ou une fonction helper permettant d'afficher à l'écran un client sélectionné par son nom ou son identifiant.
std::vector<Order> clientOrders;
   //Order *o=new Order();
    for(unsigned int i = 0; i < _orders.size(); i++)
    {
        if(_orders[i].getCilent().getClientId()==clientId){
           // *o=_orders[i];
            clientOrders.push_back(_orders[i]);
         //  cout<< o->toString()<<endl;

        }

    }

    return clientOrders;
}
/*!
 * \brief Magasin::findProductKeyByName cette methode permet de chercher un produit dans le magasin
 * par son nom (title)
 * \param _title est un parametre d'entrer pour nom du produit
 * \return retourne l'identifiant du produit dans le magasin
 */

unsigned int Magasin::findProductKeyByName(string _title) const
{
    unsigned int key=0;
    for(unsigned int i = 0; i < _products.size(); i++)
    {
        if(_products[i].getTitre()==_title ){
            key=_products[i].getProductId();
          //  cout << _clients[i].toString() << endl;
        }

    }

    return key;
}




/*!
 * \brief Magasin::validateAnOrder 7.a) cette méthode permet de valider une commande et la sauvegrde de celle ci dans le tableau orders
 * apres la recherche du client par son identifiant elle copie le contenu dans son panier dans le tableau de produit de la commande
 * \param _clientId identifiant du client binificiaire de la commande.
 * \return la valeur de retour est entier perettant de gerer les message a le l'utilisateur
 */
int Magasin:: validateAnOrder(unsigned int _clientId){

    //7.a) Ajouter à la classe Magasin une méthode ou une fonction helper permettant de valider une commande
unsigned int  newOrderId=nextOrderKey(); //generation d'un nouveau identifiant unique
    int result=0;
    for(unsigned int i = 0; i < _clients.size(); i++)
    {
        if(_clients[i].getClientId()==_clientId)
        {

            Client _cilent=_clients[i];
            std::vector<Product> _products=_clients[i].getBasket();
            string _status="livrée ";
            Order *ord=new Order(newOrderId,_cilent,_products,_status);
            this->_orders.push_back(*ord) ;
            result=1;
            break;
        }
    }
   return  result;
}
/*!
 * \brief Magasin::updateAnOrderState nous permet de reponde a la question 7.b) Ajouter une méthode ou une fonction helper permettant de mettre
 * à jour le statut d'une commande

 * \param _clientId identifiant du client
 * \param _ordertId identifiant de la commande
 * \param newSatate nouvelle etat de la commande
 * \return  la valeur de retour est un entier permettant d'afficher a l'utiliseur d'etat de l'operation
 */

int Magasin:: updateAnOrderState(unsigned int _clientId,unsigned int _ordertId, string newSatate){

    //7.b) Ajouter une méthode ou une fonction helper permettant de mettre à jour le statut d'une commande

    int result=0;
    Order *ord=new Order();
    *ord=findOrderByCientIdAndOrderId(_ordertId,_clientId );
    ord->setStatus(newSatate);
    result=1;

   return  result;
}


