#include "menu.h"
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

void Menu::menu(){
    int selection=0;
    // system("cls");
    do{

         cout<<"\n Menu (1,2,3 or 4, 0 pour sortir)"<<"\n";

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
/*!
 * \brief Menu::menu_gestion_du_magasin permet de tester les methodes suivantes:
 *  2.a) modifier la quantité disponible d'un produit.
 *  2.b) afficher un produit.
 *  3.a) ajouter un nouveau produit au magasin.
 *  3.b) afficher  tous les produits référencés dans le magasin.
 *  3.c) afficher  un produit sélectionné par son nom.
 *  3.c) Mettre à jour la quantité d'un produit sélectionné par son nom.
 */
void Menu::menu_gestion_du_magasin(){

    int selection=0;

    do{
        cout<<"\n Menu (1,2,3 or 4, 0 pour sortir)"<<"\n";

        cout<<"\n 0: pour revenir au menu principal";

        cout<<"\n 1: ajouter un nouveau produit au magasin";

        cout<<"\n 2: afficher tous les produits référencés dans le magasin";

        cout<<"\n 3: Afficher un produit sélectionné par son nom";

        cout<<"\n 4: Modifier la quantité disponible d'un produit";

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

            }
            break;

        case 2:
            {

            }
            break;

        case 3:
            {

            }
            break;

        case 4:
          {

          }
         break;




           }
     system("cls");
     }while((selection > 0) && (selection < 6));




};
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
void Menu::menu_gestion_des_utilisateurs(){
    int selection=0;



    do{

         cout<<"\n Menu (1,2,3 or 4, 0 pour sortir)"<<"\n";

        cout<<"\n 0: pour revenir au menu principal";

        cout<<"\n 1: Ajouter un client";

        cout<<"\n 2: Affichager les clients";

        cout<<"\n 3: Mise a jour des quantités d'un produit";

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

            }
            break;

        case 2:
            {
            }
            break;

        case 3:
            {
            }
            break;






           }
     system("cls");
     }while((selection > 0) && (selection < 6));





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
void Menu::menu_gestion_des_commandes(){
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

            }
            break;

        case 2:
            {
            }
            break;

        case 3:
            {
            }
            break;

        case 4:
           {
           }
           break;
     case 5:
           {
           }
           break;





           }
     system("cls");
     }while((selection > 0) && (selection < 6));





}

Menu::Menu()
{

}
