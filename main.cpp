#include <iostream>

//#include <conio.h>
#include <stdlib.h>


#include <fstream>

#include <iostream>
#include <stdlib.h>
#include <iostream>

#include <sstream>
#include <vector>
#include <cstdio>

#include <cstdlib>

#include "magasin.h"
#include "client.h"
//#include "main.h"


using namespace std;
Magasin *magasin;


/*!
 * \brief readFromFiles Cette methode nous permet de repondre a la question:
 *  8.b) Ecrire le code nécessaire à la lecture des données (produits, clients et commandes) dans des fichiers.
 * \param _fichier
 * \return
 */
int  readFromFiles(std::string _fichier)
{

    std::stringstream ss;
    ss <<"C:/temp/mootez/tp_3easystore/" << _fichier <<".txt";



    std::string s = ss.str();
     cout << s << endl;
      ifstream  fichier(s, ios::in);  // on ouvre le fichier en lecture

        if(fichier)  // si l'ouverture a réussi
        {

            string line;


            while (getline(fichier, line))
            {
               vector<string> fields;
               istringstream ss(line);
               string word;

              while (getline(ss, word,';'))
                    fields.push_back(word);

                if(_fichier=="produits"){
                    unsigned int productId=0;

                 try {
                    productId=stoi(fields[0]);
                    string _titre=fields[1];
                    string _description=fields[2];
                    unsigned int _quantiteDisponible=stoi(fields[3]);
                    double _prix=stod(fields[4]);

                    Product *p1=new Product(productId,_titre, _description, _quantiteDisponible, _prix);
                    magasin->newProduct(p1);


                    }

                    catch(string const& e) //On rattrape les strings lancés
                    {

                        cout << "Exception occurred while reading line # "<< productId<< endl;
                        cerr << e << endl;
                    }



                    }
                else if(_fichier=="clients"){

                    unsigned int clientId=0;

                 try {
                    clientId=stoi(fields[0]);
                    string fname=fields[1];
                    string lname=fields[2];

                    Client *c1=new Client(clientId,fname, lname);
                    magasin->newClient(c1);
                    }

                    catch(string const& e) //On rattrape les strings lancés
                    {

                        cout << "Exception occurred while reading line # "<< clientId<< endl;
                        cerr << e << endl;
                    }


                }
                else if(_fichier=="orders"){
                    unsigned int orderId;
                 try {
                           orderId=stoi(fields[0]);
                        unsigned int clientId=stoi(fields[1]);

                      string status=fields[2];
                       Order *o=new Order();
                       o->setOrderId(orderId);

                       o->setCilent( magasin->findClientById(clientId));
                        o->setStatus(status);
                       magasin->newOrder(o);


                    }

                    catch(string const& e) //On rattrape les strings lancés
                    {

                        cout << "Exception occurred while reading line # "<< orderId<< endl;
                        cerr << e << endl;
                    }


                }
                else if(_fichier=="orderDetails"){


                    unsigned int orderId;


                    try {
                          orderId=stoi(fields[0]);
                           unsigned int productId=stoi(fields[1]);
                           unsigned int quantity=stoi(fields[2]);

                          Product *p=new Product();
                          Order *o=new Order();
                          *p=magasin->findProductById(productId);
                          *o=magasin->findOrderById(orderId);
                          p->setQuantiteDisponible(quantity);
                          o->addProduct(*p);


                          for(unsigned int i = 0; i <magasin->orders().size(); i++)
                          {
                              if(magasin->orders()[i].getOrderId()==orderId){
                               magasin->updateOrders(i,*o);

                               break;
                              }

                       }
                    }

                       catch(string const& e) //On rattrape les strings lancés
                       {

                           cout << "Exception occurred while reading line # "<< orderId<< endl;
                           cerr << e << endl;
                       }

                }

                 }
            fichier.close();  // on ferme le fichier
           }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;

        return 0;
}
/*!
  * \brief writeToFiles  Cette methode nous permet de repondre a la question:
  * 8.b) Ecrire le code nécessaire à l'enregistrement des données (produits, clients et commandes) dans des fichiers.
  * \param filename
  */
 void writeToFiles( std::string filename)
{

    std::stringstream ss;
    ss <<"C:/temp/mootez/tp_3easystore/" << filename <<".txt";
    std::string s = ss.str();
    cout << s << endl;


        ofstream fichier(s, ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

        if(fichier)  // si l'ouverture a réussi
        {

         if(filename=="produits"){

            for(unsigned int i = 0; i < magasin->products().size(); i++)
                                   {
                                     std::string    line=magasin->products()[i].toString();
                                     fichier << line  <<endl;
                                     }

                              }
            else if(filename=="clients")
                    {
             for(unsigned int i = 0; i < magasin->clients().size(); i++)
                                    {
                                      std::string    line=magasin->clients()[i].toString();
                                      fichier << line  <<endl;
                                      }

                        }

         else if(filename=="orders")
                 {
                    for(unsigned int i = 0; i < magasin->orders().size(); i++)
                                    {
                                      std::string    line=magasin->orders()[i].toFile();
                                      fichier << line  <<endl;
                                      }
                     }

         else if(filename=="orderDetails")
                 {
                for(unsigned int i = 0; i < magasin->orders().size(); i++){
                    for(unsigned int j = 0; j < magasin->productNumberInOrder(i); j++){
                        stringstream ss;
                        ss<<magasin->orders()[i].getOrderId() ;
                        ss<<";";
                        ss<<magasin->orders()[i].getProductOrderId(j) ;
                        ss<<";";
                        ss<<magasin->orders()[i].getProducts()[j].getQuantiteDisponible() ;
                        std::string    line=ss.str();
                        fichier << line  <<endl;
                    }

                }
            }

                fichier.close();  // on referme le fichier
        }
        else  // sinon
                cerr << "Erreur à l'ouverture !" << endl;

       // r

}

 /*!
  * \brief Menu::menu_gestion_des_commandes permet de tester les methodes suivantes:
  * 6.a) Créer la classe Commande avec ses variables membres (client, produits achetés, statut).
  * 6.f) afficher toutes les informations de la commande.
  * 7.a) valider une commande
  * 7.b) mettre à jour le statut d'une commande
  * 7.c) afficher toutes les commandes passées.
  * 7.d) afficher toutes les commandes d'un client donné.
  */
 void  menu_gestion_des_commandes(){
     int selection=0;

     do{
          cout<<"\n Menu (1,2,3 or 4, 0 pour sortir)"<<"\n";

         cout<<"\n 0: pour revenir au menu principal";

         cout<<"\n 1: afficher toutes les informations de la commande";

         cout<<"\n 2: valider une commande";

         cout<<"\n 3: mettre à jour le statut d'une commande";

         cout<<"\n 4: afficher toutes les commandes passées";

         cout<<"\n 5: afficher toutes les commandes d'un client donné";

         cout<<"\n\n Enter selection: ";

         cin>>selection;




     switch(selection)
             {
         case 0:
             {
                 //exit(0);
         break;
             }
         case 1:
             {
              //6.f) Surcharger l'opérateur << pour pouvoir afficher toutes les informations de la commande.
                magasin->diplayAllOrders();
             }
             break;

         case 2:
             {
         //7.a) Ajouter à la classe Magasin une méthode ou une fonction helper permettant de valider une commande
         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;
       unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);

         if(magasin->validateAnOrder(_clientId))
                {
                     cout<<"La commande a ete bien validee"<<endl;
                }
             }
             break;

         case 3:
             {
         //7.b) Ajouter une méthode ou une fonction helper permettant de mettre à jour le statut d'une commande

         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;

         unsigned int _ordertId;
         cout<<"\n 1: Entrer le numero de la commande." <<endl;
         cin >> _ordertId;

         string newSatate;
         cout<<"\n 1: Entrer le nouveau etat de la commande." <<endl;
         cin >> newSatate;
         unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);

         if(magasin->updateAnOrderState(_clientId,_ordertId,newSatate))
                      {
                       cout<<"La commande a ete bien mise a jour"<<endl;
                     }

             }
             break;

         case 4:
            {
       //  7.c) afficher toutes les commandes passées.
         string state;
         cout<<"\n 1: Entrer l'etat des commandes a afficher." <<endl;
         cin >> state;

         magasin->diplayAllOrdersByState(state);

            }
            break;
      case 5:
            {
         //7.d) Ajouter une méthode ou une fonction helper permettant d'afficher toutes les commandes d'un client donné.
         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;
       unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);

        magasin->displayOrderOfAClient(_clientId);

            }
            break;





            }
      system("cls");
      }while((selection > 0) && (selection < 6));
 }
  //////////////////////+++++++++++++++++++++++++++++++++////////////////////////


 /*!
  * \brief Menu::menu_gestion_des_utilisateurs permet de tester les methodes suivantes:
  * 4.a) Créer la classe Client avec ses variables membres (identifiant, prenom, nom, panier d'achat) et ses fonctions getters.
  * 4.b) ajouter un produit au panier d'achat.
  * 4.c) vider le panier d'achat.
  * 4.d) modifier la quantité d'un produit ajouté au panier d'achat
  * 4.e) supprimer un produit du panier d'achat.
  * 4.f) afficher toutes les informations du client (incluant les produits du panier d'achat.
  * 5.a) ajouter un nouveau client au magasin.
  * 5.b) afficher à l'écran tous les clients du magasin.
  * 5.c) afficher à l'écran un client sélectionné par son nom ou son identifiant.
  * 5.d) ajouter un produit au panier d'achat d'un client.
  * 5.e) supprimer un produit au panier d'achat d'un client.
  * 5.f) modifier la quantité d'un produit du panier d'achat d'un client.
   */
 void menu_gestion_des_utilisateurs(){
     int flag4=0;
 // system("cls");
     do{

         cout<<"\n Menu (1,2,3,4,5 or 6, 0 pour revenir au menu pricipal)"<<"\n";

         cout<<"\n 0: pour revenir au menu principal";

         cout<<"\n 1: Tester la classe Client avec ses variables membres";

         cout<<"\n 2: Ajouter un produit au panier d'achat";

         cout<<"\n 3: Vider le panier d'achat";

         cout<<"\n 4: Modifier la quantité d'un produit ajouté au panier d'achat";

         cout<<"\n 5: supprimer un produit du panier d'achat";

         cout<<"\n 6: afficher toutes les informations du client (incluant les produits du panier d'achat)";

         cout<<"\n\n Enter selection: ";

         cin>>flag4;




     switch(flag4)
             {
         case 0:
             {
         system("cls");
                break;
            }
         case 1:
             {
       //  4.a) Créer la classe Client avec ses variables membres (identifiant, prenom, nom, panier d'achat) et ses fonctions getters.
         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;
       unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);

       Client *cl=new Client(_clientId,_firstName,_lastName);
        magasin->newClient(cl);
        }
             break;

         case 2:
             {
//4.b) Ajouter une méthode ou une fonction helper permettant
         //d'ajouter un produit au panier d'achat.
         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;
       string _titre;
       cout<<"\n 1: Entrer le titre du produit." <<endl;
       cin >>_titre;

       unsigned int quantity;
       cout<<"\n 1: Entrer la quantite du produit." <<endl;
       cin >>quantity;

       unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);
       unsigned int _productId=magasin->findProductKeyByName(_titre);
       magasin->AddProductToBasket(_clientId,_productId,quantity) ;
               }
             break;

         case 3:
             {
         //4.c) Ajouter une méthode ou une fonction helper permettant de vider le panier d'achat.
         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;

       unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);

       magasin->clearBasket(_clientId);


              }
             break;

         case 4:
             {
         //4.d) Ajouter une méthode ou une fonction helper permettant
         //de modifier la quantité d'un produit ajouté au panier d'achat

         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;

         string _titre;
         cout<<"\n 1: Entrer le titre du produit." <<endl;
         cin >>_titre;

         unsigned int new_quantity;
         cout<<"\n 1: Entrer la nouvelle quantite du produit(nombre)" <<endl;
         cin >> new_quantity;
         unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);
         unsigned int _productId=magasin->findProductKeyByName(_titre);
        magasin->modifyProductQuantityInBasket(_clientId, _productId, new_quantity);
        }
             break;

//4.e) Ajouter une méthode ou une fonction helper permettant de supprimer un produit
//du panier d'achat.
     case 5:
         {
         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;

         string _titre;
         cout<<"\n 1: Entrer le titre du produit." <<endl;
         cin >>_titre;

         unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);
         unsigned int _productId=magasin->findProductKeyByName(_titre);
        magasin->deleteProductFromBasket(_clientId, _productId);
        }
         break;
      //4.f) Surcharger l'opérateur << pour pouvoir afficher toutes les
      //informations du client (incluant les produits du panier d'achat.
     case 6:
         {
         string _firstName;
         cout<<"\n 1: Entrer le Nom  du client." <<endl;
         cin >> _firstName;
         string _lastName;
         cout<<"\n 1: Entrer le Prenom du client." <<endl;
         cin >> _lastName;
           unsigned int _clientId=magasin->findClientByName(_firstName,_lastName);
         magasin->displayProductOfAClient(_clientId);
        }
         break;
            }
       system("cls");
      }while((flag4 > 0) && (flag4 < 7));


 }

 ////////////////////++++++++++++++++++++++++++++++++++++++++///////////////////

 /*!
  * \brief Menu::menu_gestion_du_magasin permet de tester les methodes suivantes:
  *  2.a) modifier la quantité disponible d'un produit.
  *  2.b) afficher un produit.
  *  3.a) ajouter un nouveau produit au magasin.
  *  3.b) afficher  tous les produits référencés dans le magasin.
  *  3.c) afficher  un produit sélectionné par son nom.
  *  3.c) Mettre à jour la quantité d'un produit sélectionné par son nom.
  */
  void menu_gestion_du_magasin(){
     int flag=0;

     do{

         cout<<"\n Menu (1,2,3 or 4, 0 pour revenir au menu pricipal)"<<"\n";

         cout<<"\n 0: pour revenir au menu principal";

         cout<<"\n 1: ajouter un nouveau produit au magasin.";

         cout<<"\n 2: afficher tous les produits reférences dans le magasin.";

         cout<<"\n 3: afficher un produit selectionne par son nom";

         cout<<"\n 4:  mettre à jour la quantite d'un produit selectionne par son nom";



         cout<<"\n\n Enter selection: ";

         cin>>flag;




     switch(flag)
             {
         case 0:
             {
         system("cls");
                break;
            }
         case 1:
             {

         string _titre;
         cout<<"\n 1: Entrer le titre du produit." <<endl;
         cin >>_titre;
         string _description;
         cout<<"\n 1: Entrer une description du produit." <<endl;
         cin >>_description;
         unsigned int _quantiteDisponible;
         cout<<"\n 1: Entrer _quantite disponible du produit(nombre)" <<endl;
         cin >> _quantiteDisponible;
         double _prix;
         cout<<"\n 1: Entrer le prix du produit(double)" <<endl;
         cin >>_prix;

         unsigned int _productId=magasin->findProductKeyByName(_titre);

         Product *p1=new Product(_productId,_titre, _description, _quantiteDisponible, _prix);

         magasin->newProduct(p1);



             }
             break;

         case 2:
             {


          magasin->diplayAllProducts();
               }
             break;

         case 3:
             {
         string ptitle;
         cout<<"\n 1: Entrer le titre du produit." <<endl;
         cin >> ptitle;
 magasin->diplayProductsByName(ptitle);

              }
             break;

         case 4:
             {
         string ptitle;
         cout<<"\n 1: Entrer le titre du produit." <<endl;
         cin >> ptitle;
         unsigned int new_quantity;
         cout<<"\n 1: Entrer _quantite disponible du produit(nombre)" <<endl;
         cin >> new_quantity;

         magasin->updateProductsByQuantityByName(ptitle, new_quantity);
              }
             break;



            }
     system("cls");
      }while((flag > 0) && (flag < 5));


 }
  /*!
  * \brief menu_principal ce menu permet de repondre a la question:
  * 8.a) créer un menu permettant de sélectionner l'action à faire :
  * gestion du magasin, gestion des utilisateurs, gestion des commandes.
  */
 void menu_principal(){
     int selection=0;
  system("cls");
     do{

      cout<<"\n Menu (1,2 ou 3; 0 pour sortir)"<<"\n";

     cout<<"\n 0: pour sortir";

     cout<<"\n 1: Gestion du Magasin";

     cout<<"\n 2: Gestion des utilisateurs";

     cout<<"\n 3: Gestion des commandes";

     cout<<"\n\n Enter selection: ";

     cin>>selection;

     switch(selection)
             {
         case 0:
             {
         cout<<"sauvegarde des donnees du Magasin dans les fichiers suivants:"<<endl<<endl;
         writeToFiles("produits");
         writeToFiles("clients");
         writeToFiles("orders");
         writeToFiles("orderDetails");
        exit(0);
             }
         case 1:
             {
             menu_gestion_du_magasin();
             }
             break;

         case 2:
             {
              menu_gestion_des_utilisateurs();
               }
             break;

         case 3:
             {
              menu_gestion_des_commandes();
              }
             break;

            }
      system("cls");
      }while((selection > 0) && (selection < 6));


 }





int main(){
//1.b) Ecrire un programme principal permettant de créer un objet (vide) de type magasin.
magasin = new Magasin();

//8.b) Ecrire le code nécessaire à l'enregistrement et à la lecture des données (produits, clients et commandes) dans des fichiers.
readFromFiles("produits");
readFromFiles("clients");
readFromFiles("orders");
readFromFiles("orderDetails");
readFromFiles("oorderDetails");



menu_principal();

return 0;
}
