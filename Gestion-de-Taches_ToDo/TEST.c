printf("veullez entrer le titre : ");
        scanf("%s", &tch[taille].titre);

        printf("\nveullez entrer la description : ");
        scanf("%s", &tch[taille].description);

        printf("\nveullez entrer le statut : ");
        scanf("%s", &tch[taille].statut);

        printf("entrer le jour : ");
        scanf("%d", &tch[taille].deadline.jour);

        printf("entrer le mois : ");
        scanf("%d", &tch[taille].deadline.mois);

        printf("veullez entrer l annee : ");
        scanf("%d", &tch[taille].deadline.annee);

        taille++;

        printf("le titre : %s \n", tch[taille - 1].titre);

        printf("la description : %s \n", tch[taille - 1].description);

        printf("le statut : %s \n", tch[taille - 1].statut);

        printf("la date est %d/%d/%d \n", tch[taille - 1].deadline.jour, tch[taille - 1].deadline.mois, tch[taille - 1].deadline.annee);