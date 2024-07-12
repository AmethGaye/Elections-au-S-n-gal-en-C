#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// --------------------------------------------------


// STRUCTUTRE DES CANDIDATS 
typedef struct candidat candidat;
struct candidat {
    int id_C;
    char nom[30];
    char prenom[30];
    char sexe;
    char date_naiss[11];
    char parti[30];
    int nbreVotant ;
    candidat *suiv;  
} ;
// STRUCTUTRE DES ELECTEURS 
typedef struct electeur electeur;
struct electeur
{
    int id_E;
    char prenom[20];
    char nom[20];
    char sexe;
    char date_naiss[11];
    char lieux_de_vote[20];
    char bureau_vote[20];
    int dejaVote ; 
    electeur * suiv;
};






// #==================================GESTION DES ELECTEURS=====================================#


// CREER UN NOUVEAU MAILLON (NOUVEAU ELECTEUR)
electeur * creer_electeur(int id,char *n,char *p,char s, char *dn, char *lv, char *bv,int djv){
    electeur *new_elec = (electeur*)malloc(sizeof(electeur));
    system("cls");
    new_elec->id_E = id;
    strcpy(new_elec->nom,n);
    strcpy(new_elec->prenom,p);
    strcpy(new_elec->date_naiss,dn);
    strcpy(new_elec->lieux_de_vote,lv);
    strcpy(new_elec->bureau_vote,bv);
    new_elec->sexe = s;
    new_elec->dejaVote = djv;
    new_elec->suiv = NULL;
    return new_elec;
}

// AJOUTER UN ELECTEUR A LA FIN LISTE DES ELECTEURS 
electeur * ajouter_electeur(electeur * l_electeur,electeur *new_elec)
{
    electeur* tmp = l_electeur;
    if(l_electeur == NULL)
    {
        l_electeur = new_elec; /* inserer le premier element de la listte */
    }
    else
    {
        while(tmp->suiv!=NULL){ /* parcourir jusqu'a atteindre le dernier element electeur pour le */
            tmp = tmp->suiv;    /* pour le lier avec l'electeur nouvellement cree*/
        }
        tmp->suiv = new_elec;
    }
    return l_electeur;
}

//MODIFIER UN ELECTEUR
electeur * modifier_electeur(electeur *l_electeur, int id){
    electeur * tmp = l_electeur;

    while(tmp->id_E != id && tmp->suiv !=NULL){ // chercher l'electeur dont l'id_E = id passe en parametre
        tmp = tmp->suiv;
    }

    if(tmp == NULL){
        printf("cette electeur n'existe pas !"); // si on ne trouve pas l'id
    }
    // sinon on procede a la modification : nom, prenom, sexe...tous les champs qu'il desire modifier
    else{
        printf("nouveau nom : ");
        scanf("%s",&tmp->nom);
        printf("nouveau prenom : ");
        scanf("%s",&tmp->prenom);
        printf("date_naissance (format : jj-mm-aaaa ou jj/mm/aaaa) : ");
        scanf("%s",&tmp->date_naiss);
        printf("lieux de vote : ");
        scanf("%s",&tmp->lieux_de_vote);
        fflush(stdin);
        printf("bureau de vote : ");
        scanf("%s",&tmp->bureau_vote);
        fflush(stdin);
        printf("nouveau sexe (F/M): ");
        scanf("%c",&tmp->sexe);
        printf("Mise a jour reussie\n");


    }
    return l_electeur;

}

//SUPPRIMER UN ELECTEUR
electeur * supprimer_electeur(electeur *l,int id){
    electeur * p1;
    electeur * tmp = l;
    
    while(tmp->id_E != id && tmp !=NULL){ // on recherche l'electeur a supprimer grace a tmp
        p1 = tmp;
        tmp = tmp->suiv;
    }
    if(tmp == NULL){
        printf("cette electeur n'existe pas !"); // le cas ou on trouve pas id
    }
    // si l'electeur se trouve au debut de la liste -> supprimer au debut
    else if(tmp == l){
        l = l->suiv;
        free(tmp);
    }
    //si l'electeur se trouve au milieu ou fin de la liste_electeur -> suppression au milieu ou a la fin
    else{
        
            p1->suiv = tmp->suiv;
            free(tmp);
    }
        printf("Le electeur a ete supprime avec succes !!!\n");
    return l;
}

// LISTER DES ELECTEURS 
void lister_electeur(electeur * l){
    if(l == NULL)
    {
        printf("list est vide\n");
        return;
    }
    electeur *tmp = l;
    system("cls");
    printf("\t\t\t\t+========================+\n");
    printf("\t\t\t\t| La liste Des electeurs |\n");
    printf("\t\t\t\t+========================+\n\n");
    printf("+----------------------------------------------+\n");
    while(tmp!=NULL){
        printf("id : %d\nprenom : %s\nnom : %s\nsexe : %c\ndate de naiss : %s\nlieux de vote : %s\nbureau de vote : %s\n",
                    tmp->id_E,tmp->prenom,tmp->nom,tmp->sexe,tmp->date_naiss,tmp->lieux_de_vote,tmp->bureau_vote);
        printf("+----------------------------------------------+\n");
        tmp = tmp->suiv;
    }
}


// RECHERCHER PAR ID ELECTEUR
void rechercher_electeur(electeur *l, int id){
    electeur * tmp = l;
    while(tmp->id_E != id && tmp->suiv !=NULL){
        tmp = tmp->suiv;
    }
    if(tmp == NULL){
        printf("cette electeur n'existe pas !");
    }
    else{ 
        printf("Identifiant : %d\n",tmp->id_E);
        printf("Nom : %s\n", tmp->nom);
        printf("Prenom : %s\n", tmp->prenom);
        printf("Sexe : %c\n", tmp->sexe);
        printf("Date de Naissance : %s\n", tmp->date_naiss);
        printf("Parti : %s\n", tmp->lieux_de_vote);
        printf("Parti : %s\n", tmp->bureau_vote);       
    }
}








// #==================================GESTION DES CANDIDATS=====================================#

// CREER UN NOUVEAU MAILLON (NOUVEAU CANDIDAT)
candidat* creer_candidat(int id, char * n, char *pr, char s, char *dn, char *p, int v) {
    candidat *new_cand = (candidat*)malloc(sizeof(candidat));
    system("cls");
    new_cand->id_C = id;
    strcpy(new_cand->nom,n);
    strcpy(new_cand->prenom,pr);
    strcpy(new_cand->date_naiss,dn);
    strcpy(new_cand->parti,p);
    new_cand->sexe = s;
    new_cand->nbreVotant = v;
    new_cand->suiv = NULL;
    return new_cand;
}
// AJOUTER UN CANDIDAT
candidat * ajouter_candidat(candidat * l_candidat,candidat *new_cand){
    candidat* tmp = l_candidat;
    if(l_candidat == NULL)
    {
        l_candidat = new_cand; /* inserer le premier element de la listte */
    }
    else
    {
        while(tmp->suiv!=NULL){  /* parcourir jusqu'a atteindre le dernier element candidat */
            tmp = tmp->suiv;     /* pour le relier avec l'electeur nouvellement cree*/
        }
        tmp->suiv = new_cand;
    }
    return l_candidat;
}

// MODIFIER UN CANDIDAT
candidat * modifier_candidat(candidat *c,int identifiant){
 
    candidat *tmp=c;
    // Vérification si l'identifiant existe dans la liste
    while(tmp != NULL && tmp->id_C != identifiant){
        tmp=tmp->suiv;
    }
    // Vérification si la liste est vide ou identifiant existe
    if(tmp == NULL){
        printf("La liste est vide ou le candidat avec l'identifiant n'existe pas !\n", identifiant);
        return c;
    }
    else{
        printf("MODIFICATION D'UN CANDIDAT :\n");
        printf("Identifiant : ");
        scanf("%d", &tmp->id_C);
        printf("Nom : ");
        scanf("%s",&tmp->nom);
        printf("Prenom : ");
        scanf("%s", &tmp->prenom);
        printf("Sexe (M/F) : ");
        scanf(" %c", &tmp->sexe);
        printf("Date de Naissance (jour/mois/annee) : ");
        scanf("%s", &tmp->date_naiss);
        printf("Parti : ");
        scanf("%s",&tmp->parti);


        printf("Le candidat est modifie avec succes !!!\n");
    }
    return c;
}     

//SUPPRIMER UN CANDIDAT
candidat * supprimer_candidat(candidat *c,int identifiant){
    candidat * p1;
    candidat * tmp = c;
    // RECHERCHER LE CANDIDAT A SUPPRIMER
    while(tmp->id_C != identifiant && tmp != NULL){
        p1 = tmp;
        tmp = tmp->suiv;
    }
    if(tmp == NULL){
        printf("cette electeur n'existe pas !");
        return c;
    }
    // supprimer au debut
    if(tmp == c){
        c = c->suiv;
        free(tmp);
        
    }else{// suppression au milieu ou a la fin
            p1->suiv = tmp->suiv;
            free(tmp);
    }
    printf("Le Candidat a ete supprime avec succes !!!\n");
    return c;
}
//RECHERCHER UN CANDIDAT
void rechercher_candidat(candidat *c, int id){
    candidat * tmp = c;
    while(tmp->id_C != id && tmp->suiv !=NULL){
        tmp = tmp->suiv;
    }
    if(tmp == NULL){
        printf("cette candidat n'existe pas !");
    }
    else{
        printf("---------+ LE CANDIDAT TROUVE ! +---------------\n");
        printf("Identifiant : %d\n",tmp->id_C);
        printf("Nom : %s\n", tmp->nom);
        printf("Prenom : %s\n", tmp->prenom);
        printf("Sexe : %c\n", tmp->sexe);
        printf("Date de Naissance : %s\n", tmp->date_naiss);
        printf("Parti : %s\n", tmp->parti);      
    }
}

// ORDONNER LA LISTE DES CANDIDATS PAR NOMBRE DE VOTE
candidat * Trier_Candidat_Par_Nbr_Voix(candidat * c1){
    candidat * tmp = c1;
    candidat * tmp2;
    int x;
    char c;
    char y[20];

    while(tmp != NULL){
        tmp2 = tmp->suiv;
        while(tmp2 != NULL){
            if(tmp->nbreVotant < tmp2->nbreVotant){
               x = tmp->id_C;
               tmp->id_C = tmp2->id_C;
               tmp2->id_C = x;

               c = tmp->sexe;
               tmp->sexe = tmp2->sexe;
               tmp2->sexe = c;

               x = tmp->nbreVotant;
               tmp->nbreVotant = tmp2->nbreVotant;
               tmp2->nbreVotant = x;

               strcpy(y,tmp->nom);
               strcpy(tmp->nom,tmp2->nom);
               strcpy(tmp2->nom,y);

               strcpy(y,tmp->prenom);
               strcpy(tmp->prenom,tmp2->prenom);
               strcpy(tmp2->prenom,y);

               strcpy(y,tmp->date_naiss);
               strcpy(tmp->date_naiss,tmp2->date_naiss);
               strcpy(tmp2->date_naiss,y);

               strcpy(y,tmp->parti);
               strcpy(tmp->parti,tmp2->parti);
               strcpy(tmp2->parti,y);
            }
            tmp2 = tmp2->suiv;
        }
        tmp = tmp->suiv;
    }
    return c1;
}



// LISTER TOUS LES CANDIDATS
void lister_candidat(candidat * c){
    if(c == NULL)
    {
        printf("list est vide\n");
        return;
    }
    candidat *tmp = c;
    system("cls");
    printf("LA LISTE DES CANDIDATS : \n\n");
    printf("+---------------------------------------+\n");
    while(tmp!=NULL){
        printf("id : %d\nprenom : %s\nnom : %s\nsexe : %c\ndate de naiss : %s\nPartie : %s\n",
                    tmp->id_C,tmp->prenom,tmp->nom,tmp->sexe,tmp->date_naiss,tmp->parti);
        printf("+-----------------------------------+\n");
        tmp = tmp->suiv;
    }
}



// #==================================CHARGER/ENREGISTRER LES FICHERS=====================================#

// LES ELECTEURS
electeur * charger_ficherElectoral(){
    electeur * l = NULL;
    int id;
    char p[20];
    char n[20];
    char s;
    char dn[11];
    char lv[20];
    char bv[20];
    int djv;
    FILE * f = fopen("ficher_electoral.txt","a+");
    if(f == NULL){
        printf("le ficher ne peut pas etre ouvert\n");
        exit(1);
    }
    while(!feof(f)){
        fscanf(f,"%d\n%s\n%s\n%c\n%s\n%s\n%s\n%d\n\n",&id,p,n,&s,dn,lv,bv,&djv);
        l =  ajouter_electeur(l,creer_electeur(id,n,p,s,dn,lv,bv,djv));
    }
    fclose(f);
    return l;
    
}
void sauvegarder_ficherElectoral(electeur *l){
    electeur * tmp = l;
    FILE * f = fopen("ficher_electoral.txt","w");
    if(f == NULL){
        printf("le ficher ne peut pas etre ouvert\n");
        exit(1);
    }
    if(tmp == NULL){
        printf("aucun ficher n'est sauvegarde !\n");
    }
    else{
        while(tmp!=NULL){
            fprintf(f,"%d\n%s\n%s\n%c\n%s\n%s\n%s\n%d\n\n",tmp->id_E,tmp->prenom,tmp->nom,tmp->sexe,tmp->date_naiss,tmp->lieux_de_vote,tmp->bureau_vote,tmp->dejaVote);
            tmp = tmp->suiv;
        }
    }
    fclose(f);

}
// LES CANDIDATS
candidat * charger_listeCandidats(){
    candidat * l = NULL;
    int id;
    char p[20];
    char n[20];
    char s;
    char dn[11];
    char pt[20];
    int v;
    FILE * f = fopen("candidats.txt","r");
    if(f == NULL){
        printf("le ficher ne peut pas etre ouvert\n");
        exit(1);
    }
    while(!feof(f)){
        fscanf(f,"%d\n%s\n%s\n%c\n%s\n%s\n%d\n\n",&id,p,n,&s,dn,pt,&v);
        l =  ajouter_candidat(l,creer_candidat(id,n,p,s,dn,pt,v));
    }
    fclose(f);
    return l;
}
void sauvegarder_listeCandidats(candidat *l){
    candidat * tmp = l;
    FILE * f = fopen("candidats.txt","w");
    if(f == NULL){
        printf("le ficher ne peut pas etre ouvert\n");
        exit(1);
    }
    if(tmp == NULL){
        printf("aucun ficher n'est sauvegarde !\n");
    }
    else{
        while(tmp!=NULL){
            fprintf(f,"%d\n%s\n%s\n%c\n%s\n%s\n%d\n\n",tmp->id_C,tmp->prenom,tmp->nom,tmp->sexe,tmp->date_naiss,tmp->parti,tmp->nbreVotant);
            tmp = tmp->suiv;
        }
    }
    fclose(f);
}
// LES VOTES
electeur * charger_Votes(electeur *l){

}
electeur * sauvegarder_votes(){

}


// #================================== GESTION DES VOTES =====================================#

void Voter(electeur *l, candidat *c){
    int id_E;
    int id_C;
    electeur * tmp1 = l;
    candidat * tmp2 = c;
    // CHARGER LES DONNEES 

    // AFFICHER TOUS LES CANDIDATS
    system("cls");
    while(tmp2!=NULL){
        printf("%d : %s %s\n",tmp2->id_C,tmp2->prenom,tmp2->nom);
        tmp2 = tmp2->suiv;
    }
    printf("\n+-----------------------+\n\n");
    printf("Choisissez ID du candidat : ");
    scanf("%d",&id_C);
    printf("ID de l'electeur : ");
    scanf("%d",&id_E);
    
    // Verifier si l'electeur est dans le ficher electoral
    while(tmp1 != NULL && tmp1->id_E != id_E){
        tmp1 = tmp1->suiv;
    }
    if(tmp1 == NULL){
        printf("id electeur invalide !\n");
        return;
    }
    if(tmp1 != NULL && tmp1->dejaVote == 0){
        tmp1->dejaVote = 1;
    }
    else if(tmp1 != NULL && tmp1->dejaVote == 1){
        printf("l'electeur a deja vote !\n");
        return;
    }
    // valider l'electeur pour le candidat dont l'id = id_C
    tmp2 = c;
    while(tmp2 != NULL && tmp2->id_C != id_C){
        tmp2 = tmp2->suiv;
    }
    if(tmp2 == NULL){
        printf("id candidat invalide !\n");
        return;
    }
    else{
        tmp2->nbreVotant++;
        printf("vote reussi !\n");
    }
    // SAUVEGARDER LES DONNEES 
    sauvegarder_ficherElectoral(l);
    sauvegarder_listeCandidats(c);

}

void votantParCandidat(candidat *c){
    candidat *tmp = c;
    system("cls");

    printf("\t\t\t+-----------+ LISTE DES VOTANTS PAR CANDIDAT : +-----------+\n\n");
    while(tmp!=NULL){
        printf("\t\t\t# %s %s : %d\n\n",tmp->prenom,tmp->nom,tmp->nbreVotant);
        tmp = tmp->suiv;
    }

}

// Fonction permetant de calculer le nombre total de vote 
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

void Pourcentage_Et_Position(candidat *c){

    float pourcentage;
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

    //cet appel de fonction  permettra de calculer le nombre d'electeur qui ont voté
     nombre_Total=nombre_total_Votant(c);

    

     c = Trier_Candidat_Par_Nbr_Voix(c);

    tmp=c;//Faire pointer tmp a la tete de liste des candidats deja triés
    system("cls"); 
    printf("\t\t\t+-----------+ Position et pourcentage obtenu par chaque candidat : +-----------+\n\n");
     //Cette boucle va permettre d'afficher la position du candidat avec son pourcentage obtenu au vote
     while(tmp != NULL){

        pourcentage=(float)(tmp->nbreVotant)/(float)(nombre_Total) * 100;
        printf("\t\t\t+ %d %s %s : %.2f%%\n\n",position,tmp->nom,tmp->prenom,pourcentage );
        
        position++;
        tmp=tmp->suiv;
    }
}

//Fonction qui va afficher le vainqueur

void Vainqueur(candidat *c){

    candidat *tmp=NULL;
    float pourcentage;

    if (c ==NULL)
    {
       printf("Il n y'a pas eu de vote\n");
       return;
    }

    c=Trier_Candidat_Par_Nbr_Voix(c);
    tmp=c;
   pourcentage = (float)(tmp->nbreVotant * 100) / (float)nombre_total_Votant(c);
    system("cls");
    //Veridier s'il ya eu de vote 
    if (nombre_total_Votant(c) == 0)
        {
            printf("Il n y'a pas eu de vote\n");
            return;
        }
    if (tmp == NULL || pourcentage <= 50){
        printf("Aucun candidat n'a obtenu plus de 50 pourcent des voix.\n");
    }
    else{
        printf("\t\t\t+-----------+ le vainqueur des elections +-----------+\n\n");
        printf("Le vainqueur de l'election presidentielle est : %s %s avec %d Voix.\n\n", tmp->prenom, tmp->nom,tmp->nbreVotant);
    }

}

void Second_Tour(candidat *c){

    candidat *tmp=NULL;
    float pourcentage;
    int nombre=1;

    if (c == NULL)
    {
       printf("Il n y'a pas eu de vote\n");
       return ;
    }

    
    system("cls");
    //trier la liste des candidat par ordre decroissant de voix 
    c = Trier_Candidat_Par_Nbr_Voix(c);
    tmp = c;
    int total_Votant = nombre_total_Votant(c);
     //verifier s'il ya eu de vote ou pas
     if (total_Votant == 0)
        {
           printf("Il n y'a pas eu de vote\n");
           return;
        }
    pourcentage= (float)tmp->nbreVotant/(float)total_Votant*100;

    if (pourcentage > 50 )
        {
            printf(" Pas de second tour !!!! le Vainqueur a l'election presidentielle est : %s %s \n",tmp->prenom ,tmp->nom );
        }
    else
    {
          tmp=c;
            printf("\t\t\t+-----------+ Les candidats selectione au second tour +-----------+\n\n");
            while(tmp != NULL && nombre<=2)
            {

                //cette condition va saisir les candaìidat dont leur suffrage est superieur a 12,5%
                if ((float)(tmp->nbreVotant/total_Votant) >= 0.125)
                {
                    pourcentage = ((float)(tmp->nbreVotant*100)/total_Votant);
                    printf("\t\t\t+ %d %s %s : %.2f%%\n",nombre,tmp->prenom ,tmp->nom ,pourcentage);
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







// #================================== MENUS =====================================#



// MENU PRINCIPAL :
void menuPrincipal(){
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=         MENU PRINCIPAL          =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=     1. GESTION DES CANDIDATS      =-=\n");
    printf("\n\t\t\t\t=-=     2. GESTION DES ELECTEURS      =-=\n");
    printf("\n\t\t\t\t=-=     3. GESTION DES VOTES          =-=\n");
    printf("\n\t\t\t\t=-=     4. QUITTER                    =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("faites le choix : ");
}
// MENU DES CANDIDATS :
void menuCandidat(){
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=      GESTION DES CANDIDATS      =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=     1. Ajouter                    =-=\n");
    printf("\n\t\t\t\t=-=     2. Modifier                   =-=\n");
    printf("\n\t\t\t\t=-=     3. Supprimer un candidat      =-=\n");
    printf("\n\t\t\t\t=-=     4. Recherche un candidat      =-=\n");
    printf("\n\t\t\t\t=-=     5. liste des candidats        =-=\n");
    printf("\n\t\t\t\t=-=     6. Accueil                    =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("faites le choix : ");
}
// MENU DES ELECTEURS :
void menuElecteur(){
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=      GESTION DES ELECTEURS      =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=     1. Ajouter un electeur        =-=\n");
    printf("\n\t\t\t\t=-=     2. Modifier un electeur       =-=\n");
    printf("\n\t\t\t\t=-=     3. Supprimer un electeur      =-=\n");
    printf("\n\t\t\t\t=-=     4. Recherche un electeur      =-=\n");
    printf("\n\t\t\t\t=-=     5. liste des electeurs        =-=\n");
    printf("\n\t\t\t\t=-=     6. Accueil                    =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("faites le choix : ");
}
// MENU DES VOTES :
void menuVote(){
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=      GESTION DES VOTES          =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=     1. afficher un vote           =-=\n");
    printf("\n\t\t\t\t=-=     2. les votants par candidat   =-=\n");
    printf("\n\t\t\t\t=-=     3. position et pourcentage    =-=\n");
    printf("\n\t\t\t\t=-=     4. Vainqueur                  =-=\n");
    printf("\n\t\t\t\t=-=     5. candidats au 2nd tour      =-=\n");
    printf("\n\t\t\t\t=-=     6. Accueil                    =-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("faites le choix : ");
}



int main(){
    candidat * l_candidat = charger_listeCandidats();
    electeur *l_electeur =  charger_ficherElectoral();
    int x;
    char v;
    int id;
    char n[30];
    char pr[30];
    char s;
    char dn[11];
    char p[30];
    char lv[20];
    char bv[20];

    
    while(1)
    {
        accueil :
        menuPrincipal();
        scanf("%d",&x);
        system("cls");
        switch(x)
        {     
            case 1 :
            {
                candidat:
                system("cls");
                menuCandidat();
                scanf("%d",&x);
                switch(x)
                {
                    case 1 :
                    {
                        do
                        {
                            printf("Identifiant du candidat : ");
                            scanf("%d", &id);
                            fflush(stdin);
                            printf("Prenom : ");
                            scanf("%s", &pr);
                            printf("Nom : ");
                            scanf("%s", &n);
                            fflush(stdin);
                            printf("Sexe (M/F) : ");
                            scanf(" %c",&s);
                            printf("Date de Naissance (jj/mm/aaaa) : ");
                            scanf("%s", &dn);
                            printf("Partie : ");
                            scanf("%s",&p);
                            l_candidat = ajouter_candidat(l_candidat,creer_candidat(id,n,pr,s,dn,p,1));
                            printf("Le candidat est ajoute avec succes !\n");
                            printf("voulez vous ajouter un nouveau candidat (O/N): ");
                            fflush(stdin);
                            scanf("%c",&v);
                        }while(v == 'O' || v == 'o');
                        sauvegarder_listeCandidats(l_candidat); // SAUVEGARDER LES CANDIDATS NOUVELLEMENT SAISIE 
                        system("pause");
                        goto candidat;
                    }break;
                    case 2 :
                    {
                        printf("veillez saisir l'identifiant du candidat a modifier : ");
                        scanf("%d",&id);
                        l_candidat = modifier_candidat(l_candidat,id);
                        system("pause");
                        goto candidat;

                    }break;
                    case 3 :
                    {
                        printf("veillez saisir l'identifiant du candidat a supprimer : ");
                        scanf("%d",&id);
                        if(l_candidat){
                            l_candidat = supprimer_candidat(l_candidat,id);
                        }else{
                        printf("la liste est vide !\n"); 
                        }
                        system("pause");
                        goto candidat;
                    }break;
                    case 4 :
                    {
                        printf("veillez saisir l'identifiant du candidat a rechercher : ");
                        scanf("%d",&id);
                        if(l_candidat){
                            supprimer_candidat(l_candidat,id);
                        }else{
                        printf("la liste est vide !\n"); 
                        }
                        system("pause");
                        goto candidat;
                    }break;
                    case 5 :
                    {
                        lister_candidat(l_candidat);
                        system("pause");
                        goto candidat; 
                    }break;
                    case 6 :
                    {
                        system("cls");
                        goto accueil;
                    }
                    
                    
                }
                
            }break;
            case 2 :
            {
                electeur :
                system("cls");
                menuElecteur();
                scanf("%d",&x);
                switch(x)
                {
                    case 1 :
                    {
                        do
                        {
                            printf("Identifiant du candidat : ");
                            scanf("%d", &id);
                            fflush(stdin);
                            printf("Prenom : ");
                            scanf("%s", &pr);
                            printf("Nom : ");
                            scanf("%s", &n);
                            fflush(stdin);
                            printf("Sexe (M/F) : ");
                            scanf(" %c",&s);
                            fflush(stdin);
                            printf("Date de Naissance (jj/mm/aaaa) : ");
                            scanf("%s", &dn);
                            printf("Lieux de vote : ");
                            scanf("%s",&lv);
                            printf("Bureau de vote : ");
                            scanf("%s",&bv);
                            l_electeur = ajouter_electeur(l_electeur,creer_electeur(id,n,pr,s,dn,lv,bv,0));
                            printf("L'electeur est ajoute avec succes !\n");
                            printf("voulez vous ajouter un nouveau electeur (O/N): ");
                            fflush(stdin);
                            scanf("%c",&v);
                        }while(v == 'O' || v == 'o');
                        sauvegarder_ficherElectoral(l_electeur); // SAUVEGARDER LES ELECTEURS NOUVELLEMENT SAISIE 
                        system("pause");
                        goto electeur;
                    }break;
                    case 2 :
                    {
                        printf("veillez saisir l'identifiant de l'electeur a modifier : ");
                        scanf("%d",&id);
                        l_electeur = modifier_electeur(l_electeur,id);
                        system("pause");
                        goto electeur;
                    }break;
                    case 3 :
                    {
                        printf("veillez saisir l'identifiant de l'electeur a supprimer : ");
                        scanf("%d",&id);
                        if(l_electeur){
                            l_electeur = supprimer_electeur(l_electeur,id);
                        }else{
                        printf("la liste est vide !\n"); 
                        }
                        system("pause");
                        goto electeur;
                    }break;
                    case 4 :
                    {
                        printf("veillez saisir l'identifiant de l'electeur a chercher : ");
                        scanf("%d",&id);
                        if(l_electeur){
                            supprimer_electeur(l_electeur,id);
                        }else{
                        printf("la liste est vide !\n"); 
                        }
                        system("pause");
                        goto electeur;
                    }break;
                    case 5 :
                    {
                        lister_electeur(l_electeur);
                        system("pause");
                        goto electeur;
                    }break;
                    case 6 :
                    {
                        system("cls");
                        goto accueil;
                    }
                }
            }break;
            case 3 :
            {   vote:
                system("cls");
                menuVote();
                scanf("%d",&x);
                switch(x)
                {
                    case 1 :
                    {
                        Voter(l_electeur,l_candidat);
                        system("pause");
                        goto vote;
                    }break;
                    case 2 :
                    {
                        votantParCandidat(l_candidat);
                        system("pause");
                        goto vote;
                    }break;
                    case 3 :
                    {
                        Pourcentage_Et_Position(l_candidat);
                        system("pause");
                        goto vote;
                    }break;
                    case 4 :
                    {
                        Vainqueur(l_candidat);
                        system("pause");
                        goto vote;
                    }break;
                    case 5 :
                    {
                        Second_Tour(l_candidat);
                        system("pause");
                        goto vote;
                    }break;
                    case 6 :
                    {
                        system("cls");
                        goto accueil;
                        
                    }
                }  
            }break;
            case 4 :
            {
                exit(0);
            }break;
            default: {
                printf("\n\n\n\t\t\t\t\t\tMAUVAIS CHOIX !\n");
                system("pause");
                system("cls");
            }break;
        }
    }
    
    return 0;
}

