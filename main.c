#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int decodage(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mdc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	int c;
	int k1;
	int calcul;
	
	char * cheminFic_m = argv[1];
	f_m = fopen(cheminFic_m, "r");
	if (f_m==NULL){
		printf("L'ouverture du fichier à échouer. Veuillez verifier l'existence de celui-ci.\n");
	}

	char * cheminFic_k = "cle.txt";
	f_k = fopen(cheminFic_k, "r");
	if (f_k==NULL){
		printf("L'ouverture du fichier à échouer. Veuillez verifier l'existence de celui-ci.\n");
	}
	
	char * cheminFic_mdc = "message_dc.txt";
	f_mdc = fopen(cheminFic_mdc, "w");
	if (f_mdc==NULL){
		printf("L'ouverture du fichier à échouer. Veuillez verifier l'existence de celui-ci.\n");
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
	
	return EXIT_SUCCESS;
	
}


int codage(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	int c;
	int k1;
	int calcul;
	
	char * cheminFic_m = argv[1];
	f_m = fopen(cheminFic_m, "r");
	if (f_m==NULL){
		printf("L'ouverture du fichier à échouer. Veuillez verifier l'existence de celui-ci.\n");
	}

	char * cheminFic_k = "cle.txt";
	f_k = fopen(cheminFic_k, "r");
	if (f_k==NULL){
		printf("L'ouverture du fichier à échouer. Veuillez verifier l'existence de celui-ci.\n");
	}

	char * cheminFic_mc = "message_c.txt";
	f_mc = fopen(cheminFic_mc, "w");
	if (f_mc==NULL){
		printf("L'ouverture du fichier à échouer. Veuillez verifier l'existence de celui-ci.\n");
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
	
	return EXIT_SUCCESS;
	
}

int main(int argc, char *argv[]) {
	FILE* fp, *fichier; /* strcutures permettant, une fois FOPEN exécuté de recupérer des informations pour manipuler les fichiers en C */
	int c, nbrchar;
	char cle[nbrchar];
	int a,place;
	char characteres[26]="abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	
	fp = fopen(argv[1], "r"); /*ouvre le fichier*/
	if (!fp) {
        printf("Could not open file \n"); /*renvoie une erreur si le nom du fichier est incorrect*/
        return 0;
        }

	for (c = getc(fp); c != EOF; c = getc(fp)){ /*extrait les caractères du fichiers*/
        // Increment un caractère dans le compteur
        nbrchar = nbrchar + 1;
  		}

    // Close the file
    fclose(fp);

    /* !! ATTENTION nbrchar compte 2 caractères de plus que le nombre de caractère visible */

    for(a=0;a<(nbrchar-2);a++) { /*on fait donc une première boucle*/
		place = rand()%26;
		cle[a]=characteres[place];
			}

	for (a=1;a<3;a++){
		place = rand()%26;
		cle[nbrchar-a]=characteres[place];
		}

	fichier = fopen ("cle.txt", "wb");
        if (fichier) {
        	fwrite (cle, sizeof(char), nbrchar, fichier);
        } else {
        	return EXIT_FAILURE;
        	}
        fclose (fichier);

    if (argv[2]=="-c"){
        codage(argc, argv);
    }

    else if (argv[2]=="-d"){
        decodage(argc, argv);
    }


	return EXIT_SUCCESS;
}