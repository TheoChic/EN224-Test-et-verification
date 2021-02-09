#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include <assert.h>


int PGCD(int A, int B)
{
	assert((A > 0) && (A < 65536));
	assert((B > 0) && (B < 65536));

	while ( A != B){
		if (A > B){
			A = A - B;
		}else{
			B = B - A;
		}
	}
	return A;
}

int PGCD_verif(int N1, int N2){
	int reste;
	do{
		reste = N1 % N2;
		N1 = N2;
		N2 = reste;
	}while(N2 != 0);
	return N1;
}

int randA(){
	int A = (int)(rand() / (double)RAND_MAX * (65535 - 1));
	return A;
}

int randB(){
	int B = (int)(rand() / (double)RAND_MAX * (65535 - 1));
	return B;
}

int main (int argc, char * argv []){
	if (argc < 2){
		printf("ERROR : paramètre(s) incorrecte(s)\n\tRAPPEL : ./main nbIteration\n");
		return 0;
	}else if(atoi(argv[1]) < 1) {
		printf("ERROR : nbIteration >= 1\n");
		return 0;
	}else{
		srand(time(NULL));

		printf("(II) Starting PGCD program\n");
		
		int a,b;
		int n = atoi(argv[1]);

		for (int i = 0; i < n; i++){
			a = randA();
			b = randB();
			printf("\n~~~~~Essai n°%d~~~~~\n\t", (i+1));
			if ((a < 1) || (b < 1)){
				printf("ERREUR : Une des deux valeurs a ou b est en dehors de l'intervalle [0;65535]\n");
			}else {
				printf("Valeur de A : %d\t Valeur de B : %d\n", a, b);
				int result = PGCD(a, b);

				assert(result == PGCD_verif(a, b));

				printf("~~~~~Résultat : %d~~~~~\t ~~~~~PGCD Vérif : %d~~~~~~\n", result,PGCD_verif(a, b));
			}
			
		}
		printf("(II) End of PGCD program\n");
	}
  	return 0;
}
