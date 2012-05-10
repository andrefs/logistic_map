//////////////////////////////////////////////////////////////////////////////////
//				Logistic Map v1.6.c				//
//				2007.12.13					//
//		Desenha cada conjunto de pontos para cada r de uma vez,		//
//		permite redimensionamento da janela. Nao inclui eixos,leitura	//
//		de ficheiro,zoom ou diferentes funçoes				//
//////////////////////////////////////////////////////////////////////////////////
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>

#define JUMPS	1000
#define OFFSET	50000
#define START	2.3
#define END	4.0
#define NUM_PONTOS 200
#define X0 0.5

double r = START;
double x = X0;
int i=0;

double calc(double r, double x){
	return (r*x*(1-x));
return 1;
}

 //////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void){
	// Clear the window with current clearing color
	while (i<OFFSET+NUM_PONTOS){
		x = calc(r,x);
		// Set current drawing color to red
		// 	    R	  G    B
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_POINTS);
			glVertex2f(r,x);
		glEnd();		
		i++;
	}
	// Flush drawing commands and swap
	glutSwapBuffers();
}

///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value){
	i = 0;
	x = X0;
	r+= (1.0/JUMPS);
	while (i < OFFSET){
		x = calc(r,x);
		i++;
	}
	// Redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(1,TimerFunction, 1);
}

 //////////////////////////////////////////////////////////
// Set up the rendering state
void SetupRC(void)
	{
	// Set clear color to blue
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	}

///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(GLsizei w, GLsizei h){	
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (START-0.1 , END + 0.1  , -0.1, 1.1 , 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
	{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1483,864);
	glutCreateWindow("Logistic Map");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(1, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
return 0;
}

