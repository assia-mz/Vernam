#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char cle(int nbrchar){

	char cle[nbrchar];
	int a,place;
	srand(time(NULL));

	for(a=0;a<nbrchar;a++)
		{
			cle[a]=0;
		}
		
		for(a=0;a<nbrchar;a++)
		{
			place = rand()%nbrchar;
			if(cle[place]!=0)
			{
				a--;
			}
			else
			{
				cle[place]=a;
			}
		}

	for(a=0;a<nbrchar;a++){
		printf("%d", cle[a]);
		printf("-");
		}

	printf("\n");
	return EXIT_SUCCESS;
	}

