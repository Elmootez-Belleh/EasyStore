#ifndef ORDER_H
#define ORDER_H
//#include "product.h"
#include "product.h"
#include <vector>
#include "client.h"

#include <string>

class Order
{
private:

    unsigned int orderId;
    Client cilent;
    std::vector<Product> products;
    string status;


public:
     //Constructeurs
    Order();
    Order(unsigned int orderId,Client _cilent, std::vector<Product> _products, string _status);


      //Setters
      void setOrderId(unsigned int value);
      void setCilent(const Client &value);
      void setStatus(const string &value);
      void setProducts(const std::vector<Product> &value);

     //Getters

     unsigned int getOrderId() const;
    Client getCilent() const;
    string getStatus() const;
    std::vector<Product> getProducts() const;


   //Fonction membres
    void addProduct(Product &p);

    std::string toString();
     unsigned int getProductOrderId(unsigned int key) ;
    string toFile();
};

#endif // ORDER_H
