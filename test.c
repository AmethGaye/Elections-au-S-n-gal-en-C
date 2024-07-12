//******************************************************************************************

//==============================================================================
//FOnction permetant de calculer le nombre total de vote 

int nombre_total_Votant(candidat *c){

  candidat *tmp=NULL;
   int nombre_Total=0;
  if (c==NULL){
    printf("la liste des candidats est vide\n");
    exit(1);
  }
  tmp=c;
  while(tmp !=NULL)
    {

        nombre_Total += tmp->nbreVotant;
        tmp=tmp->suiv;
    }
   return nombre_Total;
      
  }

//Fonction qui permet de calculer le pourcentage et la position de chaque candidat

void Pourcentage_Et_Position(candidat *c){

    double pourcentage;
    candidat *tmp=NULL;
    candidat *suivant=NULL;
    int nombre_Total=0;
    int position=1;
    //Verification si la liste de candiat est vide 
    if (c==NULL)
    {
        printf("La liste de candidat est vide\n");
        return;
    }
    tmp=c;

    //cet appel de fonction  permettra de calculer le nombre d'electeur qui ont voté
     nombre_Total=nombre_total_Votant(c);

    

     c=Trier_Candidat_Par_Nbr_Voix(c);

    tmp=c;//Faire pointer tmp a la tete de liste des candidats deja triés
       
        printf("Position\tNom\tPrenom\tPourcentage\n");
        printf("-----------------------------------------\n");
     //Cette boucle va permettre d'afficher la position du candidat avec son pourcentage obtenu au vote
     while(tmp != NULL){

        pourcentage=(tmp->nbreVotant/nombre_Total)*100;
        printf("%d  %s %s  %.2f\n",position,tmp->nom,tmp->prenom,pourcentage );
        
        position++;
        tmp=tmp->suiv;
    }
}


//Fonction qui va afficher le vainqueur

void Vainqueur(candidat *c){

    candidat *tmp=NULL;
    double pourcentage;

    if (c ==NULL)
    {
       printf("Il n y'a pas eu de vote\n");
       return;
    }

    c=Trier_Candidat_Par_Nbr_Voix(c);
    tmp=c;
   pourcentage = ((tmp->nbreVotant * 100) / nombre_total_Votant(c));

//Veridier s'il ya eu de vote 
    if (nombre_total_Votant(c) == 0)
        {
           printf("Il n y'a pas eu de vote\n");
           return;
        }
 if (tmp == NULL || pourcentage <= 50)
     {
            printf("Aucun candidat n'a obtenu plus de 50 pourcent des voix.\n");
        }
        else{
            printf("Le vainqueur de l'election presidentielle est : %s %s \n", tmp->prenom, tmp->nom);
        }


}

//Fonction qui designe les candidats qui sont partie au second tour
void Second_Tour(candidat *c){

    candidat *tmp=NULL;
    double pourcentage;
    int nombre=1;

    if (c == NULL)
    {
       printf("Il n y'a pas eu de vote\n");
       return ;
    }

    

    //trier la liste des candidat par ordre decroissant de voix 
    c=Trier_Candidat_Par_Nbr_Voix(c);
    tmp=c;
    int total_Votant=nombre_total_Votant(c);
     //verifier s'il ya eu de vote ou pas
     if (total_Votant == 0)
        {
           printf("Il n y'a pas eu de vote\n");
           return;
        }
    pourcentage= (tmp->nbreVotant/total_Votant)*100;

    if (pourcentage > 50 )
        {
            printf(" Pas de second tour !!!! le Vainqueur a l'election presidentielle est : %s %s \n",tmp->prenom ,tmp->nom );
        }
    else
    {
          tmp=c;
            printf("Les candidats selectione au second tour :\n");
            while(tmp != NULL && nombre<=2)
            {

                //cette condition va saisir les candaìidat dont leur suffrage est superieur a 12,5%
                    if ((tmp->nbreVotant/total_Votant) >= 0.125)
                  {
                    pourcentage = ((tmp->nbreVotant*100)/total_Votant);
                     printf("%d  %s %s %.2f\n",nombre,tmp->prenom ,tmp->nom ,pourcentage);
                     nombre++;
                     tmp=tmp->suiv;

                  }
                  // si il ya pas dans la lliste des candidats qui ont des suffrages <12.5%
                  if (nombre == 1)
                        {
                            printf("Aucun candidat n'a assez de suffrages pour se qualifier pour le second tour.\n");
                        }


            }
    }

}

//=========================================================================================================================
