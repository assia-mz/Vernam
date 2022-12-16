#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char cle(int nbrchar){

	FILE *fichier;
	char cle[nbrchar];
	int a,place;
	char characteres[26]="abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	
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

	return EXIT_SUCCESS;
	}