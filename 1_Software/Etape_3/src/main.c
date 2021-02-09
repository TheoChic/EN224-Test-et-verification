#include "stdio.h"
#include "stdlib.h"
#include "math.h"


int PGCD(int A, int B)
{
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
	printf("(II) Starting PGCD program\n");
	
	srand(time(NULL));
	
	int a,b;
	int nbError = 0;
	for (int i = 0; i < 65535; i++){
		a = randA();
		b = randB();
		printf("\n~~~~~Essai n°%d~~~~~\n\t", (i+1));
		if ((a < 1) || (b < 1)){
			printf("ERREUR : Une des deux valeurs a ou b est en dehors de l'intervalle [0;65535]\n");
		}else {
			printf("Valeur de A : %d\t Valeur de B : %d\n", a, b);
			int result = PGCD(a, b);

			if (result != PGCD_verif(a,b)){
				nbError ++;
			}
			printf("~~~~~Résultat : %d~~~~~\n", result);
		}
		
	}
		
	printf("\n\n~~~~~~~~~~Nombre d'erreurs détectées : %d~~~~~~~~~~\n\n", nbError);

	printf("(II) End of PGCD program\n");
  	return 0;
}
