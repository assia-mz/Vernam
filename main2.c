#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonction.h"

int main(int argc, char *argv[]) {
	/* definition des variables */
	FILE* fp, *fichier, *f_m, *f_k, *f_mc, *f_mdc; /* strcutures permettant, une fois FOPEN exécuté de recupérer des informations pour manipuler les fichiers en C */
	int c, nbrchar, a,place,k1, calcul;
	char * fichierdonne = argv[1];
	char characteres[26]="abcdefghijklmnopqrstuvwxyz";
	int option;

	/**/
	srand(time(NULL));

	/*test si le nombre d'agrument donné en indique de commande lors de l'appel de la focntion est correct*/
	if (argc!=3) {
		printf("Le nombre d'arguments donné est incorrect.\n");
		return EXIT_FAILURE;
	}

	/* On va d'abord compter le nombre de caractères*/
	fp = fopen(argv[1], "r"); /*ouvre le fichier*/
	if (!fp) {
        printf("Le fichier n'a pas pu être ouvert.\n"); /*renvoie une erreur si le nom du fichier est incorrect*/
        return EXIT_FAILURE;
        }

	for (c = getc(fp); c != EOF; c = getc(fp)){ /*extrait les caractères du fichiers*/
        // Increment un caractère dans le compteur
        nbrchar = nbrchar + 1;
  		}
  	// ferme le fichier
    fclose(fp);
    
    /*on va ensuite vérifier l'option donné pour savoir quoi faire*/

    /* si la clé est -k, on va générer une nouvelle clé de la taille du message*/
    if ((strcmp(argv[2],"k"))==0){
    	cle(nbrchar);
    	}

    /* si la clé est -c, on va coder le message*/
    if ((strcmp(argv[2],"c"))==0){
    	cle(nbrchar);
    	char * cheminFic_m = argv[1];
		f_m = fopen(cheminFic_m, "r");
		if (f_m==NULL){
			printf("L'ouverture du fichier a decode a echouer.\n");
		}
		
		char * cheminFic_k = "cle.txt";
		f_k = fopen(cheminFic_k, "r");
		if (f_k==NULL){
			printf("L'ouverture du fichier cle a echouer.\n");
		}
		
		char * cheminFic_mc = "message_c.txt";
		f_mc = fopen(cheminFic_mc, "w");
		if (f_mc==NULL){
			printf("L'ouverture du fichier decode à échouer.\n");
		}
		
		
		while ((c = fgetc(f_m)) != EOF)
		/* EOF est une constante qui est obligatoirement
		négative (elle vaut -1 sous Linux). */
		{
			k1 = fgetc(f_k);
			calcul = (c+k1) % 256; /* modulo 256 du caractère qui est entrain d'être lu */
			fputc(calcul, f_mc); /* fputc permet d'écrire un caractère sur le flux de caractères passé en paramètre*/
		}
		
		fclose(f_m);
		fclose(f_k);
		fclose(f_mc);
    	}

    else if ((strcmp(argv[2],"d"))==0) {
    	printf("option d");
    	char * cheminFic_m = "message_c.txt";
		f_m = fopen(cheminFic_m, "r");
		if (f_m==NULL){
			printf("L'ouverture du fichier a decode echouer.\n");
		}
		
		char * cheminFic_k = "cle.txt";
		f_k = fopen(cheminFic_k, "r");
		if (f_k==NULL){
			printf("L'ouverture du fichier clé a echouer.\n");
		}
		
		char * cheminFic_mdc = "message_dc.txt";
		f_mdc = fopen(cheminFic_mdc, "w");
		if (f_mdc==NULL){
			printf("L'ouverture du fichier decode échouer.\n");
		}
		
		while ((c = fgetc(f_m)) != EOF)
		/* EOF est une constante obligatoirement
		négative (elle vaut -1 sous Linux). */	
		{
			k1 = fgetc(f_k); /* fgetc lis le caractère à la position courante du flux considéré*/
			calcul = c-k1 >= 0?c-k1:256-(c-k1); /* ?? */ 
			fputc(calcul, f_mdc);
		}
		
		/*fermeture des fichiers*/
		fclose(f_m);
		fclose(f_k);
		fclose(f_mdc);
		
    	}

return EXIT_SUCCESS;
}
