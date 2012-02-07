#include <GL/glut.h>
#include <GL/gl.h>
#include <unistd.h>
#include "logistic.h"

///////////////////////////////////////////////////////////
// Invocação da área de desenho
void RenderScene(void){
	int i;
	double r;

	glClear(GL_COLOR_BUFFER_BIT);		// Limpa a janela com a cor actual
	glColor3f(1.0f, 1.0f, 1.0f);		// Define a cor de desenho vermelho
	glBegin(GL_POINTS);
	for (r=2.3;r<4.0;r+=(1.0/REASON)){
		itera_v0_2(1000,0.5,r);
		for (i=0;i<10;i++)
			glVertex2d((int)((r-2.3)*REASON),(xs[i])*REASON);
	}
	glEnd();
	glFlush();				// Manda executar todas as funçoes pendentes
	}
///////////////////////////////////////////////////////////
// Especifica a cor a ser usada em glClear
void SetupRC(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
//////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(GLsizei w, GLsizei h){
	GLfloat aspectRatio;
	
	if(h == 0)				// Prevent a divide by zero
		h = 1;
	glViewport(0, 0, w, h);			// Set Viewport to window dimensions
	glMatrixMode(GL_PROJECTION);		// Reset coordinate system
	glLoadIdentity();
	aspectRatio = (GLfloat)w / (GLfloat)h;	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho (-5.0, 1400.0, -5.0 / aspectRatio, 800.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho (-5.0 * aspectRatio, 1400.0 * aspectRatio, -5.0, 800.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}
///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1433	, 864);			//Define tamanho da janela
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("GLRect");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
return 0;
}

