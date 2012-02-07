#include <GL/glut.h>
#include <GL/gl.h>
#include "logistic2.c"


///////////////////////////////////////////////////////////
// Invocação da área de desenho
void RenderScene(void){
	int i,j;
	glClear(GL_COLOR_BUFFER_BIT);		// Limpa a janela com a cor actual
	glColor3f(0.0f, 0.0f, 0.0f);		// Define a cor de desenho preto
	glBegin(GL_POINTS);
	for (i=1;i<175;i++)
		for (j=0;j<10;j++)
			glVertex2d( i*1.0, xs[i][j]);
	glEnd();

	glFlush();				// Manda executar todas as funçoes pendentes
	}
///////////////////////////////////////////////////////////
// Especifica a cor ca ser usada em glClear
void SetupRC(void){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	}
//////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
/*
void ChangeSize(GLsizei w, GLsizei h){
	GLfloat aspectRatio;
	
	if(h == 0)				// Prevent a divide by zero
		h = 1;
	glViewport(0, 0, w, h);			// Set Viewport to window dimensions
	glMatrixMode(GL_PROJECTION);		// Reset coordinate system
	glLoadIdentity();
	aspectRatio = (GLfloat)w / (GLfloat)h;	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho (-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho (-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}
*/
///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);			//Define tamanho da janela
	glutInitWindowPosition(0, 0);		//Define posição da janela
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Logistic Map v1.0 RC");
	glutDisplayFunc(RenderScene);
//	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
return 0;
}

