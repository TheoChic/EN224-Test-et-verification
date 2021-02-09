#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include <assert.h>


int PGCD(int A, int B)
{
	assert(A > 0); assert(A < 65536);
	assert(B > 0); assert(B < 65536);
	
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
		
		int result = PGCD(a, b);
		printf("----------Résultat : %u----------\n", result);
		printf("(II) End of PGCD program\n");

	}

  	return 0;
}
