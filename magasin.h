#ifndef MAGASIN_H
#define MAGASIN_H

#include "product.h"
#include "order.h"
#include "client.h"


#include <vector>
/*!
 * \brief The Magasin class : reponse a la question 1.a)
 * Créer la classe Magasin avec ses variables membres, son constructeur
 */
class Magasin
{

private:

    std::vector<Product> _products;
    std::vector<Client> _clients;
    std::vector<Order> _orders;


public:

    //Constructeurs

     Magasin();
     Magasin(Product p,  Client c,  Order o );

 //Setters
     void setOrders(const Order &order);
     void setClients(const Client &client);
     void setProducts(const Product &product);


     //Getters
     std::vector<Product> products() const;
     std::vector<Client> clients() const;
     std::vector<Order> orders() const;
     //Fonction membres

    void newClient(Client *c);
    int AddProductToBasket(unsigned int _clientId, unsigned int  _productId,unsigned int quantity);
    int  clearBasket(unsigned int _clientId);
   void diplayAllProducts();
    void diplayProductsByName(string pname);
    void updateProductsByQuantityByName(string ptitle, unsigned int new_quantity);

     unsigned int nextProductKey() const;
     unsigned int  nextClientKey() const;

      unsigned int findClientByName(string fname, string lname) const;
      unsigned int findProductKeyByName(string _title)const;
      void newProduct(Product *p);
      int modifyProductQuantityInBasket(unsigned int _clientId, unsigned int _productId, unsigned int quantity);
      int deleteProductFromBasket(unsigned int _clientId, unsigned int _productId);
      int displayProductOfAClient(unsigned int _clientId);
      void diplayAllClients();
      Client findClientById(unsigned int id) const;
      int validateAnOrder(unsigned int _clientId);
      unsigned int nextOrderKey() const;
      Order findOrderByCientIdAndOrderId(unsigned int orderId,unsigned int clientId) const;
      int updateAnOrderState(unsigned int _clientId, unsigned int _ordertId,string newSatate);
      void diplayAllOrders();
      std::vector<Order> findOrdersByClientId(unsigned int clientId) const;
      void displayOrderOfAClient(unsigned int _clientId);
      void diplayAllOrdersByState(string state);
      void newOrder(Order *o);
      Product findProductById(unsigned int id) const;
      Order findOrderById(unsigned int orderId) const;
      void updateOrders(unsigned int key, const Order &order);
      unsigned int productNumberInOrder(unsigned int key);
};

#endif // MAGASIN_H
