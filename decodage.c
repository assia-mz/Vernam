#include <stdio.h>
#include <stdlib.h>

int decodage(char *argv[]) {
	FILE *f_m, *f_k, *f_mdc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	int c;
	int k1;
	int calcul;
	
	char * cheminFic_m = argv[1];
	char * cheminFic_k = "cle.txt";
	char * cheminFic_mdc = "message_dc.txt";

	f_m = fopen(cheminFic_m, "r");
	if (!f_m){
		printf("L'ouverture du fichier a decode echouer.\n");
	}

	f_k = fopen(cheminFic_k, "r");
	if (!f_k){
		printf("L'ouverture du fichier clé a echouer.\n");
	}
	
	f_mdc = fopen(cheminFic_mdc, "wd");
	if (!f_mdc){
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
	
	return EXIT_SUCCESS;
	
}