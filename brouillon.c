#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char main(){

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
	
	return EXIT_SUCCESS;
	}