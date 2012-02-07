//////////////////////////////////////////////////////////////////////////////////
//				Logistic Map v1.2.c				//
//				2007.12.11					//
//		Desenha o mapa segundo a função mais geral (tudo de uma vez),	//
//		permite redimensionamento da janela. Inclui eixos, nao inclui	//
//		leitura	de ficheiro,zoom ou diferentes funçoes			//
//////////////////////////////////////////////////////////////////////////////////		

#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>

#define JUMPS	5000
#define OFFSET	50000
#define START	2.3
#define END	4.0
#define NUM_PONTOS 50
#define X0 0.5

double calc(double r, double x){
	return (r*x*(1-x));
return 1;
}

/*
double calc(double r, double x){
	return (r*sin(x)*(1-sin(x)));
}
*/
int itera(int num_pontos, double x0, double r){
	long int i;
	double x;
	x = calc(r, x0);
	for (i=0;i<OFFSET;i++){
		x = calc(r,x);
	}
	for (i=OFFSET; i<(OFFSET + num_pontos); i++){
		x = calc(r,x);
		glVertex2d(r,x);
	}
return 1;
}

int draw_logistic(double start, double end, double jumps, int num_pontos, double x0){
	double r;
	for (r=start; r<end; r+=(1.0/jumps)){
		itera(num_pontos, x0, r);
		glFlush();
		}
return 1;
}

int draw_eixos(){
	glColor3f(1.0f, .0f, 0.0f);
	glBegin(GL_LINES);
	//Eixo XX
	glVertex2f(START-0.05,0);
	glVertex2f(END+0.003,0);
	//Eixo YY
	glVertex2f(START,-0.05);
	glVertex2f(START,1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(END, 0.01);
	glVertex2f(END, -0.01);
	glVertex2f(END+ 0.02, 0);
	
	glColor3f(1.0f, .0f, 0.0f);
        glVertex2f(2.29,1.0);
	glVertex2f(2.31, 1.0);
	glVertex2f(2.3, 1.02);
        glEnd();
	glFlush();
return 1;
}

void RenderScene(void){
	glClear(GL_COLOR_BUFFER_BIT);
	draw_eixos();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
		draw_logistic(START, END, JUMPS, NUM_PONTOS, X0);
	glEnd();
	glFlush();
	}

void SetupRC(void){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

void ChangeSize(GLsizei w, GLsizei h){	
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (START-0.1 , END + 0.1  , -0.1, 1.1 , 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1433	, 864);			//Define tamanho da janela
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Logistic Map");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
return 0;
}

