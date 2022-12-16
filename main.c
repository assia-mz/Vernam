#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonction.h"

int main(int argc, char *argv[]) {
	FILE* fp, *fichier, *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN exécuté de recupérer des informations pour manipuler les fichiers en C */
	int c, nbrchar, a,place,k1, calcul;
	char characteres[26]="abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));

	fp = fopen(argv[1], "r"); /*ouvre le fichier*/
	if (!fp) {
        printf("Could not open file.\n"); /*renvoie une erreur si le nom du fichier est incorrect*/
        }

	for (c = getc(fp); c != EOF; c = getc(fp)){ /*extrait les caractères du fichiers*/
        // Increment un caractère dans le compteur
        nbrchar = nbrchar + 1;
  		}

    // Close the file
    fclose(fp);

    /* !! ATTENTION nbrchar compte 2 caractères de plus que le nombre de caractère visible */
    if (argv[2]=="-k"){
    	cle(nbrchar);
    	}

    else if (argv[2]=="-c"){
		cle(nbrchar);
    	codage(argv);
    }

    else if (argv[2]=="-d"){
        decodage(argv);
    }



	return EXIT_SUCCESS;
}