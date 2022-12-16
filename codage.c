#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int codage(int argc, char * argv[]) {
	FILE* f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	int c, k1, calcul;
	
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
	
	return EXIT_SUCCESS;
	
}