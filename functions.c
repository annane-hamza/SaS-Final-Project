#include <stdio.h>
#include <string.h>
#include "header.h"

struct aerport airport;

void ajouterAirport()
{
    char name[50];
    printf("Entrez le nom de l'aeroport: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    strcpy(airport.nom, name);
    airport.nbAvions = 0;
}

void ajouterAvions()
{
    int NumberOfAvionsToadd;
    int status;

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

        airport.avions[airport.nbAvions].idavion = airport.nbAvions + 1;
        printf("ID: %d\n", airport.avions[airport.nbAvions].idavion);

        printf("Modele : ");
        scanf(" %[^\n]%*c", airport.avions[airport.nbAvions].modele);

        printf("Capacite: ");
        scanf("%d", &airport.avions[airport.nbAvions].capacite);

        printf("Statut: \n");
        printf("entree 1 pour disponible\nentree 2 pour en maintenete\nentree 3 pour en vole\n");
        scanf("%d", &status);

        switch (status)
        {
        case 1:
            strcpy(airport.avions[i].status,"disponible");
            break;
        case 2:
            strcpy(airport.avions[i].status,"en maintenance");
            break;
        case 3:
            strcpy(airport.avions[i].status,"en vol");
            break;
        
        default:
             printf("le choix n'est pas disponible\n");
            break;
        }

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
        printf("Il n'y a pas d'avions disponibles pour le moment.\n");
        return;
    }

    int id, found = 0;
    printf("Entrez l ID de l avion que vous souhaitez modifier:");
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
        printf("L avion avec l ID %d n existe pas\n", id);
    }
}

void delete_avion()
{
    if (airport.nbAvions == 0)
    {
        printf("Il n y a aucun avion pour l instant !\n");
        return;
    }

    int idtosearch;
    int found = 0;

    printf("Entrez l ID de l avion que vous voulez supprimer: ");
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
            printf("L avion avec l ID %d a ete supprime !\n", idtosearch);
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
        printf("Aucun avion disponible.\n");
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

    printf("\n Les avions sont tries selon la capacite !\n");
    Afficher_avions();
}

void sortByModele()
{
    if (airport.nbAvions == 0)
    {
        printf("Aucun avion disponible!\n");
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

    printf("\n Les avions sont triés par modele (ordre alphabetique)\n");
    Afficher_avions();
}

void Statistiques()
{
    int totalOfAvions = airport.nbAvions;
    int available = 0;
    int maintenance = 0;
    int inFlight = 0;

    if (totalOfAvions == 0)
    {
        printf("Aucun avion n'est enregistre dans l'aeroport.\n");
        return;
    }

    int indexMax = 0;
    int indexMin = 0;

    for (int i = 0; i < airport.nbAvions; i++)
    {
        if (strcmp(airport.avions[i].status, "disponible") == 0)
        {
            available++;
        }
        else if (strcmp(airport.avions[i].status, "en maintenance") == 0)
        {
            maintenance++;
        }
        else if (strcmp(airport.avions[i].status, "en vol") == 0)
        {
            inFlight++;
        }

        if (airport.avions[i].capacite > airport.avions[indexMax].capacite)
        {
            indexMax = i;
        }

        if (airport.avions[i].capacite < airport.avions[indexMin].capacite)
        {
            indexMin = i;
        }
    }

    printf("\n===== Statistiques =====\n");
    printf("Nombre total d'avions : %d\n", totalOfAvions);
    printf("Avions disponibles    : %d\n", available);
    printf("Avions en maintenance : %d\n", maintenance);
    printf("Avions en vol         : %d\n", inFlight);

    printf("Avion avec la plus grande capacite : ID %d (%d places)\n",
           airport.avions[indexMax].idavion, airport.avions[indexMax].capacite);

    printf("Avion avec la plus petite capacite : ID %d (%d places)\n",
           airport.avions[indexMin].idavion, airport.avions[indexMin].capacite);
    printf("=========================\n");
}