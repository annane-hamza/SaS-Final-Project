#include <stdio.h>
#include "header.h"

int main()
{
    int choix;

    ajouterAirport();

    do
    {
        printf("-------------------------------------------------------\n");
        printf("          Welcome To %s                                \n",airport.nom);
        printf("--------------------------------------------------------\n");
        
        printf("\n====== MENU ======\n");
        printf("1. Ajouter avion(s)\n");
        printf("2. Afficher avions\n");
        printf("3. Modifier avion\n");
        printf("4. Supprimer avion\n");
        printf("5. Rechercher avion par ID\n");
        printf("6. Rechercher avion par modele\n");
        printf("7. Trier avions par capacite\n");
        printf("8. Trier avions par modele (alphabetique)\n");
        printf("0. Quitter\n");
        printf("==================\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterAvions();
            break;
        case 2:
            Afficher_avions();
            break;
        case 3:
            Modifier_avion();
            break;
        case 4:
            delete_avion();
            break;
        case 5:
            RechercherAvionParID();
            break;
        case 6:
            RechercherAvionParModele();
            break;
        case 7:
            sortbyCapacite();
            break;
        case 8:
            sortByModele();
            break;
        case 9:
            Statistiques();
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix invalide!\n");
        }

    } while (choix != 0);

    return 0;
}
