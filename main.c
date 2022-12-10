#include <stdio.h>
#include <stdlib.h>
#define CODAGE

int main(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	
	int c;
	int k1;
	int calcul;
	int option;
	
	if (arg[]==c){
		codage()

	}

	if (arg[]==d){

	}
	

	/* recupération sur la ligne de commande des noms de fichiers et option (-c pour codage
		-d pour décodage : message cle message_calculé 
	
	
	
	code -c f1 f2 f3
	code -d f1 f2 f3
	
	*/
	
	datafile = ouvre_fichier(argv[1], argv[2], argv[3]);
	ouvre_fichier (argv[1], argv[2], argv[3], &f1, &f2, &f3);
	
	while ((c = fgetc(datafile.f_m)) != EOF)
		
		{
			k1 = fgetc(datafile.f_k);
			if (option == CODAGE)
				calcul = (c+k1) % 256;
			else 
				calcul = c-k1 >= 0?c-k1:256-(c-k1);
			fputc(calcul, datafile.f_mc);
		}
	
	
	fermefichier(datafile);
	return EXIT_SUCCESS;
}