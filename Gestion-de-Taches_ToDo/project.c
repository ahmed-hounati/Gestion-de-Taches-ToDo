#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int taille = 0;

typedef struct date
{
    int jour;
    int mois;
    int annee;
} date;

typedef struct tache
{
    int id;
    char titre[100];
    char description[500];
    date deadline;
    char statut[100];
} tache;

void ajouter(tache tch[])
{
    if (taille == 0)
    {
        tch[taille].id = 1;
    }
    else
    {
        tch[taille].id = tch[taille - 1].id + 1;
    }

    printf("\n\t\t\t\t\tVeuillez entrer le titre : ");
    scanf(" %[^\n]", tch[taille].titre);

    printf("\n\t\t\t\t\tVeuillez entrer la description : ");
    scanf(" %[^\n]", tch[taille].description);

    int choix;
    printf("\n\t\t\t\t\t1 - Si votre tach est a realiser \n");
    printf("\n\t\t\t\t\t2 - Si votre tache est a en cours de realisation \n");
    printf("\n\t\t\t\t\t3 - Si votre tache est a en finalisee \n");
    printf("\n\t\t\t\t\tVotre choix est : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        strcpy(tch[taille].statut, "a realiser \n");
        break;
    case 2:
        strcpy(tch[taille].statut, "en cours de realisation \n");
        break;
    case 3:
        strcpy(tch[taille].statut, " a finalisee \n");
        break;
    default:
        printf("\n\t\t\t\t\tChoix invalide \n");
        break;
    }

    printf("\n\t\t\t\t\tEntrer le jour de deadline: ");
    scanf("%d", &tch[taille].deadline.jour);

    printf("\n\t\t\t\t\tEntrer le mois de deadline : ");
    scanf("%d", &tch[taille].deadline.mois);

    printf("\n\t\t\t\t\tVeuillez entrer l'annee de deadline : ");
    scanf("%d", &tch[taille].deadline.annee);

    taille++;
}

void ajouterTaches(tache tch[], int nombreTaches)
{
    for (int i = 0; i < nombreTaches; i++)
    {
        ajouter(tch);
    }
}

void affichages(tache tch[])
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("\n\t\t\t\t\t------Tache %d---- \n", tch[i].id);
        printf("\t\t\t\t\tId : %d \n", tch[i].id);
        printf("\t\t\t\t\tTitre : %s \n", tch[i].titre);
        printf("\t\t\t\t\tDescription : %s \n", tch[i].description);
        printf("\t\t\t\t\tStatut : %s ", tch[i].statut);
        printf("\t\t\t\t\tLe deadline  %d/%d/%d \n\n", tch[i].deadline.jour, tch[i].deadline.mois, tch[i].deadline.annee);
    }
}

void trie(tache tch[])
{
    int cmp;
    do
    {
        cmp = 0;
        for (int i = 0; i < taille - 1; i++)
        {
            if (strcmp(tch[i].titre, tch[i + 1].titre) > 0)
            {
                tache temp = tch[i];
                tch[i] = tch[i + 1];
                tch[i + 1] = temp;
                cmp = 1;
            }
        }
    } while (cmp);
}

int compareDates(date date1, date date2)
{
    if (date1.annee != date2.annee)
    {
        return date1.annee - date2.annee;
    }
    else if (date1.mois != date2.mois)
    {
        return date1.mois - date2.mois;
    }
    else
    {
        return date1.jour - date2.jour;
    }
}

void triedead(tache tch[])
{
    tache tmp;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = 0; j < taille - i - 1; j++)
        {
            if (compareDates(tch[j].deadline, tch[j + 1].deadline) > 0)
            {
                tmp = tch[j];
                tch[j] = tch[j + 1];
                tch[j + 1] = tmp;
            }
        }
    }
}

void dead_line(tache tch[])
{
    int i;
    int delai_jour;
    int jours;
    int tab[taille];
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (i = 0; i < taille; i++)
    {
        jours = tch[i].deadline.annee * 365 + tch[i].deadline.mois * 30 + tch[i].deadline.jour;
        delai_jour = jours - (currentYear * 365 + currentMonth * 30 + currentDay);
        tab[i] = delai_jour;
    }
    for (int i = 0; i < taille; i++)
    {
        if (tab[i] == 0)
        {
            printf("\n\t\t\t\t\tId : %d | Titre : %s | Deadline en : Aujourdui\n", tch[i].id, tch[i].titre);
        }
        else if (tab[i] <= 3)
        {
            printf("\n\t\t\t\t\tId : %d | Titre : %s | Deadline en : %d jours\n", tch[i].id, tch[i].titre, tab[i]);
        }
    }
}

void modifierDesc(tache tch[])
{
    int id;
    printf("\n\t\t\t\t\tVeuller entrer l Id que vous voulez modifier : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (tch[i].id == id)
        {
            printf("\n\t\t\t\t\tTaper la nouvelle description de la tache :");
            scanf(" %[^\n]", tch[i].description);
        }
    }
}

void modifierStatut(tache tch[])
{
    int id, choix;
    printf("\n\t\t\t\t\tVeuller entrer l Id que vous voulez modifier : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (tch[i].id == id)
        {
            printf("\n\t\t\t\t\t Taper la nouvelle statut de la tache : \n");
            printf("\n\t\t\t\t\t1 - Si votre tach est a realiser \n");
            printf("\n\t\t\t\t\t2 - Si votre tache est a en cours de realisation \n");
            printf("\n\t\t\t\t\t3 - Si votre tache est a en finalisee \n");
            printf("\n\t\t\t\t\tvotre choix est : ");
            scanf("%d", &choix);
            switch (choix)
            {
            case 1:
                strcpy(tch[i].statut, "a realiser \n");
                break;
            case 2:
                strcpy(tch[i].statut, "en cours de realisation \n");
                break;
            case 3:
                strcpy(tch[i].statut, " a finalisee \n");
                break;
            default:
                printf("\n\t\t\t\t\tchoix invalid.\n");
                break;
            }
        }
    }
}

void modifierdead(tache tch[])
{
    int id;
    printf("\n\t\t\t\t\tVeuller entrer l Id que vous voulez modifier : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (tch[i].id == id)
        {
            printf("\n\t\t\t\t\tTaper la nouvelle jour de deadline : ");
            scanf("%d", &tch[i].deadline.jour);
            printf("\n\t\t\t\t\tTaper la nouvelle mois de deadline : ");
            scanf("%d", &tch[i].deadline.mois);
            printf("\n\t\t\t\t\tTaper la nouvelle annee de deadline : ");
            scanf("%d", &tch[i].deadline.annee);
        }
    }
}

void rechercheId(tache tch[])
{
    int id;
    int found = 0;
    printf("\n\t\t\t\t\tVeuillez entrer l'ID que vous voulez rechercher : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (tch[i].id == id)
        {
            printf("\n\t\t\t\t\t------Tache %d---- \n", tch[i].id);
            printf("\t\t\t\t\tId : %d \n", tch[i].id);
            printf("\t\t\t\t\tTitre : %s \n", tch[i].titre);
            printf("\t\t\t\t\tDescription : %s \n", tch[i].description);
            printf("\t\t\t\t\tStatut : %s ", tch[i].statut);
            printf("\t\t\t\t\tLe deadline %d/%d/%d \n\n", tch[i].deadline.jour, tch[i].deadline.mois, tch[i].deadline.annee);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n\t\t\t\t\tIl n'y a aucune tache avec cet ID\n\n");
    }
}

void recherchetitre(tache tch[])
{
    int found = 0;
    char titre[100];
    printf("\n\t\t\t\t\tVeuller entrer le titre que vous voulez rechercher : ");
    scanf("%s", &titre);
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(tch[i].titre, titre) == 0)
        {
            printf("\n\t\t\t\t\t------Tache %d---- \n", tch[i].id);
            printf("\t\t\t\t\tId : %d \n", tch[i].id);
            printf("\t\t\t\t\tTitre : %s \n", tch[i].titre);
            printf("\t\t\t\t\tDescription : %s \n", tch[i].description);
            printf("\t\t\t\t\tStatut : %s ", tch[i].statut);
            printf("\t\t\t\t\tLe deadline %d/%d/%d \n\n", tch[i].deadline.jour, tch[i].deadline.mois, tch[i].deadline.annee);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n\t\t\t\t\tIl n'y a aucune tache avec cet titre\n\n");
    }
}

void supprimerTahe(tache tch[])
{
    int id;
    printf("\n\t\t\t\t\tVeuller entrer l Id que vous voulez supprimer : ");
    scanf("%d", &id);
    int i, found = 0;

    for (i = 0; i < taille; i++)
    {
        if (tch[i].id == id)
        {
            found = 1;

            for (int j = i; j < taille; j++)
            {
                tch[j] = tch[j + 1];
            }

            (taille)--;
            printf("\t\t\t\t\tLa tache avec l identifiant %d a ete supprimee.\n\n", id);
            break;
        }
    }

    if (!found)
    {
        printf("\t\t\t\t\tAucune tache avec l identifiant %d n a ete trouvee.\n\n", id);
    }
}

void NombreTotal(int taille)
{
    printf("\n\t\t\t\t\tLe nombre total de taches est : %d\n\n", taille);
}

void complet(tache tch[])
{
    int complete = 0;
    int incomplete = 0;

    for (int i = 0; i < taille; i++)
    {
        if ((strcmp(tch[i].statut, " a finalisee \n") == 0))
        {
            complete++;
        }
        else
        {
            incomplete++;
        }
    }

    printf("\n\t\t\t\t\tNombre de taches completes : %d\n", complete);
    printf("\n\t\t\t\t\tNombre de taches incompletes : %d\n\n", incomplete);
}

void statiDead(tache tch[])
{
    int i;
    int delai_jour;
    int jours;
    int tab[taille];
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (i = 0; i < taille; i++)
    {
        jours = tch[i].deadline.annee * 365 + tch[i].deadline.mois * 30 + tch[i].deadline.jour;
        delai_jour = jours - (currentYear * 365 + currentMonth * 30 + currentDay);
        tab[i] = delai_jour;
    }
    for (int i = 0; i < taille; i++)
    {
        printf("\n\t\t\t\t\tid : %d | Titre : %s | Deadline en : %d jours\n\n", tch[i].id, tch[i].titre, tab[i]);
    }
}
int main()
{
    int choix, affi, modifier, recherche, statistiques;
    int day, month, year;
    tache tch[100];
    int nombreTaches;

    do
    {
        printf("\n\t\t\t\t\t-------Menu-------\n\n");
        printf("\n\t\t\t\t\t1 - Ajouter une nouvelle tache.\n");
        printf("\n\t\t\t\t\t2 - Ajouter plusieurs nouvelles taches.\n");
        printf("\n\t\t\t\t\t3 - Afficher la liste de toutes les taches.\n");
        printf("\n\t\t\t\t\t4 - Modidier une tache.\n");
        printf("\n\t\t\t\t\t5 - Supprimer une tache par identifiant.\n");
        printf("\n\t\t\t\t\t6 - Rechercher les taches.\n");
        printf("\n\t\t\t\t\t7 - Statistiques.\n");
        printf("\n\t\t\t\t\t8 - Quitter.\n");

        printf("\n\t\t\t\t\tVotre choix est : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("\n\t\t\t\t\tAjouter une nouvelle tache.\n");
            ajouter(tch);
            affichages(tch);
            break;
        case 2:
            printf("\n\t\t\t\t\tAjouter plusieurs nouvelles taches.\n");
            printf("\n\t\t\t\t\tCombien de taches voulez vous ajouter : ");
            scanf("%d", &nombreTaches);
            ajouterTaches(tch, nombreTaches);
            affichages(tch);
            break;
        case 3:
            printf("\n\t\t\t\t\tAfficher la liste de toutes les taches.\n\n");
            do
            {
                printf("\t\t\t\t\t1 - Trier la tache par ordre alphabetique.\n");
                printf("\t\t\t\t\t2 - Trier la tache par deadline.\n");
                printf("\t\t\t\t\t3 - Afficher les taches dont le deadline est 3 jours ou moins.\n");
                printf("\t\t\t\t\t4 - Quitter.\n");
                printf("\t\t\t\t\tChoisi le tri que vous voulez : \n");
                scanf("%d", &affi);
                switch (affi)
                {
                case 1:
                    printf("\n\t\t\t\t\tTrier les tache par ordre alphabetique.\n\n");
                    trie(tch);
                    printf("\t\t\t\t\tLe trie par ordre alphabitique est : \n");
                    affichages(tch);
                    break;
                case 2:
                    printf("\t\t\t\t\tTrier les tache par deadline.\n");
                    triedead(tch);
                    printf("\t\t\t\t\tLe trie par deadline est : \n");
                    affichages(tch);
                    break;
                case 3:
                    printf("\t\t\t\t\tAfficher les taches dont le deadline est dans 3 jours ou moins.\n");
                    dead_line(tch);
                    break;
                case 4:
                    printf("\t\t\t\t\tQuitter.\n");
                    break;
                default:
                    printf("\n\t\t\t\t\tchoix invalid.\n");
                    break;
                }

                break;
            } while (affi != 4);
            break;
        case 4:
            printf("\n\t\t\t\t\tModidier une tache \n\n");
            do
            {
                printf("\n\t\t\t\t\t1 - Modifier la description d une tache.\n");
                printf("\n\t\t\t\t\t2 - Modifier la statut d une tache.\n");
                printf("\n\t\t\t\t\t3 - Modifier la deadline d une tache.\n");
                printf("\n\t\t\t\t\t4 - Quitter \n");
                printf("\n\t\t\t\t\tChoisi le modifier que vous voulez : ");
                scanf("%d", &modifier);
                switch (modifier)
                {
                case 1:
                    printf("\n\t\t\t\t\tModifier la description d une tache.\n");
                    modifierDesc(tch);
                    affichages(tch);
                    break;
                case 2:
                    printf("\n\t\t\t\t\tModifier le statut d une tache.\n");
                    modifierStatut(tch);
                    affichages(tch);
                    break;
                case 3:
                    printf("\n\t\t\t\t\tModifier la deadline d une tache.\n");
                    modifierdead(tch);
                    affichages(tch);
                    break;
                case 4:
                    printf("\n\t\t\t\t\tQuitter \n");
                default:
                    printf("\n\t\t\t\t\tChoix invalide");
                    break;
                }
            } while (modifier != 4);

            break;
        case 5:
            printf("\n\t\t\t\t\tSupprimer une tache par identifiant \n\n");
            supprimerTahe(tch);
            break;
        case 6:
            printf("\n\t\t\t\t\tRechercher les taches \n\n");
            do
            {
                printf("\t\t\t\t\t1 - Rechercher une tache par son identifiant.\n\n");
                printf("\t\t\t\t\t2 - Rechercher une tache par son titre.\n\n");
                printf("\t\t\t\t\t3 - Quitter.\n");
                printf("\n\t\t\t\t\tChoisi le recherche que vous voulez : ");
                scanf("%d", &recherche);
                switch (recherche)
                {
                case 1:
                    printf("\n\t\t\t\t\tRechercher une tache par son identifiant.\n");
                    rechercheId(tch);
                    break;
                case 2:
                    printf("\n\t\t\t\t\tRechercher une tache par son titre.\n");
                    recherchetitre(tch);
                    break;
                case 3:
                    printf("\n\t\t\t\t\tQuitter.\n");
                    break;
                default:
                    printf("\n\t\t\t\t\tchoix invalid \n");
                    break;
                }
            } while (recherche != 3);

            break;
        case 7:
            printf("\n\t\t\t\t\tStatistiques \n\n");
            do
            {
                printf("\t\t\t\t\t1 - Afficher le nombre total des taches.\n");
                printf("\t\t\t\t\t2 - Afficher le nombre de taches comletes et incompletes.\n");
                printf("\t\t\t\t\t3 - afficher le nombre dejours restants jusqu au delai de chaque tache.\n");
                printf("\t\t\t\t\t4 - Quitter.\n");
                printf("\n\t\t\t\t\tchoisi le statistique que vous voulez : ");
                scanf("%d", &statistiques);
                switch (statistiques)
                {
                case 1:
                    printf("\n\t\t\t\t\tAfficher le nombre total des taches.\n");
                    NombreTotal(taille);
                    break;
                case 2:
                    printf("\n\t\t\t\t\tAfficher le nombre de taches comletes et incompletes.\n");
                    complet(tch);
                    break;
                case 3:
                    printf("\n\t\t\t\t\tAfficher le nombre dejours restants jusqu au delai de chaque tache.\n");
                    statiDead(tch);
                    break;
                case 4:
                    printf("\n\t\t\t\t\tQuitter.\n");
                    break;
                default:
                    printf("\n\t\t\t\t\tChoix invalide \n");
                    break;
                }
            } while (statistiques != 4);

            break;
        case 8:
            printf("\t\t\t\t\tQuitter \n");
            break;
        default:
            printf("\n\t\t\t\t\tChoix invalide \n");
            break;
        }
    } while (choix != 8);
    return 0;
}
