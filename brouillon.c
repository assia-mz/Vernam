#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char main(){

	FILE *fichier;
	int nbrchar=10;
	char cle[nbrchar];
	int a,place;
	char characteres[26]="abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	
	for(a=0;a<nbrchar;a++) 
	{
		place = rand()%26;
		cle[a]=characteres[place];
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