#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include <assert.h>
#include "PGCD.h"


int main (int argc, char * argv []){

	assert(PGCD(0, 128) == 128);
	assert(PGCD(12, 0) == 12);
	assert(PGCD(256, 12) == 4);
	assert(PGCD(48756, 24612) == 12);
	assert(PGCD(65535, 3519) == 51);
	printf("~~~~~~~~~~Test sucessfull~~~~~~~~~~\n");
  	return 0;
}
