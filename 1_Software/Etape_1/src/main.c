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

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");
	
	int a, b;

	if (argc < 3){
		printf("ERROR : paramètre(s) incorrecte(s)\n\tRAPPEL : ./main a b\n");
		return 0;
	}else{

		a = atoi(argv[1]);
		b = atoi(argv[2]);
		
		if ( (0 < a) && (a <= 65535) && (0 < b) && (b <= 65535)){
			int result = PGCD(a, b);
			printf("----------Résultat : %u----------\n", result);

		}else{
			printf("Les valeurs utilisées doivent être comprises dans l'intervalle [1; 65535]\n");
			return 0;
		}
	}

	printf("(II) End of PGCD program\n");
  	return 0;
}
