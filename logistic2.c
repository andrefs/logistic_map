#include <stdio.h>
#include <math.h>
#include "logistic.h"


int main()
{
	int i;
	printf("before itera\n");
	itera(1000, 0.5);

	for (i=0;i<171;i++){
		printf("r = %f\t\t", (float) (i/100.0 + 2.3));
		printf("x = %f\n", xs[i]);
	}
return 0;
}

