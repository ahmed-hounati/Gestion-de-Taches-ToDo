#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main()
{
    char menu[50];
    int choix, second, modifier, recherche, statistiques;

    do
    {

        printf("1 - Ajouter une nouvelle tache \n");
        printf("2 - Ajouter plusieurs nouvelles taches \n");
        printf("3 - Ajouter la liste de toutes les taches \n");
        printf("4 - Modidier une tache \n");
        printf("5 - Supprimer une tache par identifiant \n");
        printf("6 - Rechercher les taches \n");
        printf("7 - Statistiques \n");
        printf("8 - Quitter \n");

        printf("Votre choix est : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("Ajouter une nouvelle tache \n");
            break;
        case 2:
            printf("Ajouter plusieurs nouvelles taches \n");
            break;
        case 3:
            printf("Ajouter la liste de toutes les taches \n");
            do
            {
                printf("1 - Trier la tache par ordre alphabetique : \n");
                printf("2 - Trier la tache par deadline : \n");
                printf("3 - Afficher les taches dont le deadline est 3 jours ou moins : \n");
                printf("4 - Quitter \n");
                printf("Choisi le tri que vous voulez : ");
                scanf("%d", &second);
                switch (second)
                {
                case 1:
                    printf("Trier les tache par ordre alphabetique \n");
                    break;
                case 2:
                    printf("Trier les tache par deadline \n");
                case 3:
                    printf("Afficher les taches dont le deadline est dans 3 jours ou moins \n");
                case 4:
                    printf("Quitter \n");
                default:
                    printf("choix invalid \n");
                    break;
                }

                break;
            } while (second != 4);
        case 4:
            printf("Modidier une tache \n");
            do
            {
                printf("1 - Modifier la description d une tache.\n");
                printf("2 - Modifier la statut d une tache.\n");
                printf("3 - Modifier la deadline d une tache.\n");
                printf("4 - Quitter \n");
                printf("Choisi le modifier que vous voulez : ");
                scanf("%d", &modifier);
                switch (modifier)
                {
                case 1:
                    printf("Modifier la description d une tache.\n");
                    break;
                case 2:
                    printf("Modifier la description d une tache.\n");
                    break;
                case 3:
                    printf("Modifier la description d une tache.\n");
                    break;
                case 4:
                    printf("Quitter \n");
                default:
                    printf("Choix invalide");
                    break;
                }
            } while (modifier != 4);

            break;
        case 5:
            printf("Supprimer une tache par identifiant \n");
            break;
        case 6:
            printf("Rechercher les taches \n");
            do
            {
                printf("1 - Rechercher une tache par son identifiant.\n");
                printf("2 - Rechercher une tache par son titre.\n");
                printf("3 - Quitter.\n");
                printf("Choisi le modifier que vous voulez : ");
                scanf("%d", &recherche);
                switch (recherche)
                {
                case 1:
                    printf("Rechercher une tache par son identifiant.\n");
                    break;
                case 2:
                    printf("Rechercher une tache par son titre.\n");
                    break;
                case 3:
                    printf("Quitter.\n");
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            } while (recherche != 3);

            break;
        case 7:
            printf("Statistiques \n");
            do
            {
                printf("1 - Afficher le nombre total des taches.\n");
                printf("2 - Afficher le nombre de taches comletes et incompletes.\n");
                printf("3 - afficher le nombre dejours restants jusqu au delai de chaque tache.\n");
                printf("4 - Quitter.\n");
                printf("choisi le statistique que vous voulez : ");
                scanf("%d", &statistiques);
                switch (statistiques)
                {
                case 1:
                    printf("Afficher le nombre total des taches.\n");
                    break;
                case 2:
                    printf("Afficher le nombre de taches comletes et incompletes.\n");
                    break;
                case 3:
                    printf("Afficher le nombre dejours restants jusqu au delai de chaque tache.\n");
                    break;
                case 4:
                    printf("Quitter.\n");
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            } while (statistiques != 4);

            break;
        case 8:
            printf("Quitter \n");

        default:
            printf("Choix invalide \n");
            break;
        }
    } while (choix != 8);
    return 0;
}
