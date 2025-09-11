#ifndef LIBRARY_H
#define LIBRARY_H

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

extern struct aerport airport;

void stringcopy(char s1[], char s2[]);
void ajouterAirport();
void ajouterAvions();
void Afficher_avions();
void Modifier_avion();
void delete_avion();
void RechercherAvionParID();
void RechercherAvionParModele();
void sortbyCapacite();
void sortByModele();
void Statistiques();

#endif
