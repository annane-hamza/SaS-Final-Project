#include <stdio.h>
#include <string.h>
#include "header.h"

struct aerport airport;

void stringcopy(char s1[], char s2[])
{
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void ajouterAirport()
{
    char name[50];
    printf("Entrez le nom de l'aeroport: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    stringcopy(airport.nom, name);
    airport.nbAvions = 0;
}

void ajouterAvions()
{
    int NumberOfAvionsToadd;
    printf("Combien d'avions faut-il ajouter?: ");
    scanf("%d", &NumberOfAvionsToadd);

    if (airport.nbAvions + NumberOfAvionsToadd > max)
    {
        printf("L'aeroport est plein!\n");
        return;
    }

    for (int i = 0; i < NumberOfAvionsToadd; i++)
    {
        printf("\n--- Avion %d ---\n", i + 1);

        airport.avions[airport.nbAvions].idavion = airport.nbAvions + 7 * 32;
        printf("ID: %d\n", airport.avions[airport.nbAvions].idavion);

        printf("Modele : ");
        scanf(" %[^\n]%*c", airport.avions[airport.nbAvions].modele);

        printf("Capacite: ");
        scanf("%d", &airport.avions[airport.nbAvions].capacite);

        printf("Statut : ");
        scanf(" %[^\n]%*c", airport.avions[airport.nbAvions].status);

        airport.nbAvions++;
    }
    printf("%d avion(s) ajoute(s)!\n", NumberOfAvionsToadd);
}

void Afficher_avions()
{
    if (airport.nbAvions == 0)
    {
        printf("il n'y a pas d'avions disponibles dans %s .\n", airport.nom);
        return;
    }

    printf("\n===== Liste des avions =====\n");
    for (int i = 0; i < airport.nbAvions; i++)
    {
        printf("\nAvion %d\n", i + 1);
        printf("ID: %d\n", airport.avions[i].idavion);
        printf("Modele: %s\n", airport.avions[i].modele);
        printf("Capacite: %d\n", airport.avions[i].capacite);
        printf("Statut: %s\n", airport.avions[i].status);
    }
    printf("\n---------------------------\n");
}

void Modifier_avion()
{
    if (airport.nbAvions == 0)
    {
        printf("Makayn hta avion f l'aéroport\n");
        return;
    }

    int id, found = 0;
    printf("Entrez ID dyal avion li bghiti tmodifi: ");
    scanf("%d", &id);

    for (int i = 0; i < airport.nbAvions; i++)
    {
        if (airport.avions[i].idavion == id)
        {
            found = 1;

            printf("Modele (actuel: %s): ", airport.avions[i].modele);
            scanf(" %[^\n]%*c", airport.avions[i].modele);

            printf("Capacite (actuel: %d): ", airport.avions[i].capacite);
            scanf("%d", &airport.avions[i].capacite);

            printf("Statut (actuel: %s): ", airport.avions[i].status);
            scanf(" %[^\n]%*c", airport.avions[i].status);

            printf("Avion modifie!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Avion avec ID %d ma kaynach.\n", id);
    }
}

void delete_avion()
{
    if (airport.nbAvions == 0)
    {
        printf("Makayna hta chi avion daba!\n");
        return;
    }

    int idtosearch;
    int found = 0;

    printf("Dakhal id Dyal Avions Li bi Tmsa7: ");
    scanf("%d", &idtosearch);

    for (int i = 0; i < airport.nbAvions; i++)
    {
        if (airport.avions[i].idavion == idtosearch)
        {
            for (int j = i; j < airport.nbAvions - 1; j++)
            {
                airport.avions[j] = airport.avions[j + 1];
            }
            airport.nbAvions--;
            found = 1;
            printf("Avion b id %d tmsa7!\n", idtosearch);
            break;
        }
    }

    if (!found)
        printf("id Not Found!\n");
}

void RechercherAvionParID()
{
    if (airport.nbAvions == 0)
    {
        printf("Aucun avion disponible.\n");
        return;
    }

    int id;
    int found = 0;
    printf("Entrez l'ID de l'avion que vous voulez chercher: ");
    scanf("%d", &id);

    for (int i = 0; i < airport.nbAvions; i++)
    {
        if (airport.avions[i].idavion == id)
        {
            printf("\n--- Avion trouvé ---\n");
            printf("ID: %d\n", airport.avions[i].idavion);
            printf("Modele: %s\n", airport.avions[i].modele);
            printf("Capacite: %d\n", airport.avions[i].capacite);
            printf("Statut: %s\n", airport.avions[i].status);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Aucun avion avec l'ID %d trouve.\n", id);
    }
}

void RechercherAvionParModele()
{
    if (airport.nbAvions == 0)
    {
        printf("Aucun avion disponible.\n");
        return;
    }

    char ModeleToSearch[40];
    int found = 0;

    printf("Entrez Modele de l'avion que vous voulez chercher: ");
    scanf("%s", ModeleToSearch);

    for (int i = 0; i < airport.nbAvions; i++)
    {
        if (strcmp(airport.avions[i].modele, ModeleToSearch) == 0)
        {
            printf("\n--- Avion trouve ---\n");
            printf("ID: %d\n", airport.avions[i].idavion);
            printf("Modele: %s\n", airport.avions[i].modele);
            printf("Capacite: %d\n", airport.avions[i].capacite);
            printf("Statut: %s\n", airport.avions[i].status);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Aucun avion avec Modele %s no trouve.\n", ModeleToSearch);
    }
}

void sortbyCapacite()
{
    if (airport.nbAvions == 0)
    {
        printf("Makayn hta avion!\n");
        return;
    }

    for (int i = 0; i < airport.nbAvions - 1; i++)
    {
        for (int j = i + 1; j < airport.nbAvions; j++)
        {
            if (airport.avions[i].capacite > airport.avions[j].capacite)
            {
                struct Avions temp = airport.avions[i];
                airport.avions[i] = airport.avions[j];
                airport.avions[j] = temp;
            }
        }
    }

    printf("\nAvions mratbin 3la 7sab capacite!\n");
    Afficher_avions();
}

void sortByModele()
{
    if (airport.nbAvions == 0)
    {
        printf("Makayn hta avion!\n");
        return;
    }

    for (int i = 0; i < airport.nbAvions - 1; i++)
    {
        for (int j = i + 1; j < airport.nbAvions; j++)
        {
            if (strcmp(airport.avions[i].modele, airport.avions[j].modele) > 0)
            {
                struct Avions temp = airport.avions[i];
                airport.avions[i] = airport.avions[j];
                airport.avions[j] = temp;
            }
        }
    }

    printf("\nAvions mratbin 3la 7sab modele (alphabetique)!\n");
    Afficher_avions();
}

void    Statistiques()
{
    int totalofAvions = airport.nbAvions;

    int nomber_of_disponible;
    int nomber_of_maintence;
    int nombeer_of_envol;

    

    printf("nombre of avions dans le parc %d \n",totalofAvions);


}
