#include <stdio.h>
#include <stdlib.h>

int codage(char *argv[]) {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	int c, k1, calcul;
	
	char * cheminFic_m = argv[1];
	char * cheminFic_k = "cle.txt";
	char * cheminFic_mc = "message_c.txt";
	char * cheminFic_mdc = "message_dc.txt";

	f_m = fopen(cheminFic_m, "r");
	if (!f_m){
		printf("L'ouverture du fichier a decode a echouer.\n");
	}

	f_k = fopen(cheminFic_k, "r");
	if (!f_k){
		printf("L'ouverture du fichier cle a echouer.\n");
	}

	f_mc = fopen(cheminFic_mc, "w");
	if (!f_mc){
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