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

	for (int i = 0; i < 200000; i++){
		a = randA();
		b = randB();
		printf("\n~~~~~Essai n°%d~~~~~\n\t", (i+1));
		if ((a < 1) || (b < 1)){
			printf("ERREUR : Valeur de A : %d\t Valeur de B : %d\n", a, b);
		}else {
			printf("Valeur de A : %d\t Valeur de B : %d\n", a, b);
			int result = PGCD(a, b);
			printf("~~~~~Résultat : %d~~~~~\n", result);
		}
		
	}
		

	printf("(II) End of PGCD program\n");
  	return 0;
}
