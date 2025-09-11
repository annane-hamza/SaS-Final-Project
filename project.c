#include <stdio.h>

#define max 10

struct Avions
{
    int idavion;
    char modele[40];
    int capacite;
    char status[40];
};

struct aerport
{
    char nom[40];
    struct Avions avions[max];
    int nbAvions;
};

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

    scanf("%[^\n]%*c", name);

    stringcopy(airport.nom, name);

    airport.nbAvions = 0;
}
int main()
{
    int choice;

    ajouterAirport();

    do
    {

        printf("\n===== Menu Avions =====\n");
        printf("1. Ajouter un avion (ou plusieurs)\n");
        printf("2. Afficher la liste des avions\n");
        printf("3. Modifier un avion (modele, capacite, statut)\n");
        printf("4. Supprimer un avion\n");
        printf("5. Rechercher un avion (par id ou par modele)\n");
        printf("6. Trier les avions (par capacite, par modele alphabetique)\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            ajouterAirport();
            break;
        case 2:
            printf("%s \n", airport.nom); // for test
            break;
        case 3:
            printf("3. Modifier un avion (modele, capacite, statut)\n");
            break;
        case 4:
            printf("4. Supprimer un avion\n");
            break;
        case 5:
            printf("Rechercher un avion...\n");
            break;
        case 6:
            printf("Trier les avions...\n");
            break;
        case 0:
            printf("Quitter le programme...\n");
            break;
        default:
            printf("Choix invalide, reessayer.\n");
        }

    } while (choice != 0);

    return 0;
}
