#include "product.h"
#include <sstream>

unsigned int Product::getProductId() const
{
    return productId;
}

string Product::getTitre() const
{
    return _titre;
}

string Product::getDescription() const
{
    return _description;
}

unsigned int Product::getQuantiteDisponible() const
{
    return _quantiteDisponible;
}

double Product::getPrix() const
{
    return _prix;
}

void Product::setQuantiteDisponible(unsigned int quantiteDisponible)
{
    _quantiteDisponible = quantiteDisponible;
}

Product::Product()
{

}

Product::Product(unsigned int productId, string _titre, string _description, unsigned int _quantiteDisponible, double _prix)
{
    this->productId=productId;
    this->_titre=_titre;
    this->_description=_description;
    this->_quantiteDisponible=_quantiteDisponible;
    this->_prix=_prix;


}

void Product::setProductId(unsigned int value){
    this->productId=value;

}

string Product::toString()
{


           stringstream ss;

            ss<<productId;
            ss<<";";
           ss<<_titre;
            ss<<";";
            ss<<_description;
            ss<<";";
            ss<<_quantiteDisponible;
            ss<<";";
            ss<<_prix;
            return ss.str();

}
