#include <stdio.h>
#include <math.h>

float x[100000];

int calc(float r, float x, float *xnext){
	*xnext = r*x*(1-x);
return 1;
}

int itera(int max, float r, float x0){
	int i;
	calc(r, x0, &(x[0]));
	for (i=1; i<max; i++)
		calc(r, x[i-1], &(x[i]));
	for (i=0; i<max; i++)
		printf("\ni = %d\tx = %f", i, x[i]);
return 1;
}

int main()
{
	itera(100000, 4.0, 0.5);
return 0;
}
	
