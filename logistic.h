#include <stdio.h>
#include <math.h>

#define REASON 100
#define NUM_PONTOS 30
double xs[10];

double calc(double r, double x){
	return (r*x*(1-x));
return 1;
}

int itera_teste(){
	int i;
	double x;
	FILE *fp;
	fp = fopen("debug.txt","w+");
	x = calc(3.9998,0.5);
	for (i=0;i<100000;i++){
		x = calc(3.9998,x);
		fprintf(fp,"i = %d\tx = %f\t",i, x);
		if (!(i%5)) fprintf(fp,"\n");
	}
return 1;
}

int itera_v0_1(int max, double x0){
	int i;
	double x,r;	
	for (r=2.3;r<4.0;r+=(1.0/REASON)){
		x = calc(r, x0);
		for (i=1; i<max; i++)
			x = calc(r, x);
		xs[(int)((r-2.3)*REASON)] = x;
	}
		
return 1;
}

int itera_v0_2(int max, double x0, double r){
	int i;
	double x;
	x = calc(r,x0);
	for (i=1; i<(max-NUM_PONTOS); i++)
		x = calc(r,x);
	for (i=(max-NUM_PONTOS);i<max;i++){
		x = calc(r,x);
		xs[(10-max+i)] = x;
	}
return 1;
}

int itera_v1_0(int max, double x0, double r){
	int i;
	double x;
	for (i=0;i<10000;i++)
		x = calc(r,x);
	for (i=10000;i<10000+max;i++){
		x = calc(r,x);
		glVertex2d((int)((r-2.3)*REASON),x*790);
	}
return 1;
}
