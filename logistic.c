//////////////////////////////////////////////////////////////////////////////////
//				Logistic Map v1.1.c				//
//				2007.12.08					//
//		Desenha o mapa segundo a função mais geral, permite 		//
//		redimensionamento da janela. Nao inclui eixos,leitura		//
//		de ficheiro,zoom ou diferentes funçoes				//
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

int itera(int num_pontos, double x0, double r){
	long int i;
	double x;
	x = calc(r, x0);
	for (i=0;i<OFFSET;i++){
		x = calc(r,x);
	}
	for (i=OFFSET; i<(OFFSET + num_pontos); i++){
		x = calc(r,x);
		glVertex2d((int)((r-START)*1390/(END-START)),x*790);
	}
return 1;
}

int draw_logistic(double start, double end, double jumps, int num_pontos, double x0){
	double r;
	for (r=start; r<end; r+=(1.0/jumps))
		itera(num_pontos, x0, r);
return 1;
}


void RenderScene(void){
	glClear(GL_COLOR_BUFFER_BIT);
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
	GLfloat aspectRatio;
	
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	aspectRatio = (GLfloat)w / (GLfloat)h;
	aspectRatio = (GLfloat)((END-START)*JUMPS) / (GLfloat)(790);
	if (w < h) glOrtho (-5.0 , 1400.0 , -5.0, 800.0, 1.0, -1.0);
	else glOrtho (-5.0, 1400.0, -5.0, 800.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//glutInitWindowSize(1433	, 864);			//Define tamanho da janela
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Logistic Map");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
return 0;
}

