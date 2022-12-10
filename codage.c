#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	int c;
	int k1;
	int calcul;
	
	char * cheminFic_m = "message.txt";
	f_m = fopen(cheminFic_m, "r");
	if (flux) {
    ...
    fclose(flux);                 /* fermeture du flux */
 	}
	 char * cheminFic_k = "cle.txt";
	f_k = fopen(cheminFic_k, "r");
	/* Traitement erreur */
	char * cheminFic_mc = "message_c.txt";
	f_mc = fopen(cheminFic_mc, "w");
	/* Traitement erreur */
	
	
	while ((c = fgetc(f_m)) != EOF)
		
	{
		k1 = fgetc(f_k);
		calcul = (c+k1) % 256;
		fputc(calcul, f_mc);
	}
	
	
	fclose(f_m);
	fclose(f_k);
	fclose(f_mc);
	
	return EXIT_SUCCESS;
	
}