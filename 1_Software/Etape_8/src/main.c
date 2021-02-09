#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include <assert.h>
#include "PGCD.h"
#include <string.h>

int main (int argc, char * argv []){

	FILE* f_ref_A;
	char ref_A[32];
    f_ref_A = fopen("ref_A.txt", "r");

	if(f_ref_A==NULL){
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit(1);
    }

	FILE* f_ref_B;
	char ref_B[32];
    f_ref_B = fopen("ref_B.txt", "r");

	if(f_ref_B == NULL){
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit(1);
    }


	FILE* f_resu_C;
	char resu_C[32];
    f_resu_C = fopen("resu_C.txt", "w");

	if(f_resu_C==NULL){
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit(1);
    }

	int result;

	while((fgets(ref_A, 32, f_ref_A) != NULL) && (fgets(ref_B, 32, f_ref_B) != NULL) )
	{
		result = PGCD(atoi(ref_A), atoi(ref_B));
		sprintf(resu_C, "%d", result);
		strcat(resu_C, "\n");
		fputs(resu_C, f_resu_C);
	}
 
    fclose(f_ref_A);
    fclose(f_ref_B);
    fclose(f_resu_C);
	printf("~~~~~~~~~~Generating data sucessfully~~~~~~~~~~\n");
  	return 0;
}
