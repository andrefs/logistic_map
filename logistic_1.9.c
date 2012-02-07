//////////////////////////////////////////////////////////////////////////////////
//				Logistic Map v1.9.c				//
//				2007.12.13					//
//		Desenha cada conjunto de pontos para cada r de uma vez,		//
//		permite redimensionamento da janela, diferentes funçoes,	// 
//		Inclui eixos, nao inclui leitura de ficheiro ou zoom		//
//////////////////////////////////////////////////////////////////////////////////
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>

///////////////////////////////////////////////////////////
//variaveis globais
int		n;
int 		i=0;
int 		jumps = 1000;
long int 	offset = 50000;
double		r_min = 2.3;
double		r_max = 4.0;
double		x_min = 0.0;
double		x_max = 1.0;
int 		num_pontos = 200;
double 		x0 = 0.5;
double 		r = 2.3;
double 		x = 0.5;
int 		wgl = 1434;
int 		hgl = 852;

///////////////////////////////////////////////////////////
//funcoes calc
double calc_0(){	
	return (r*x*(1-x));
}

double calc_1(){
	return (r * sin(x) * (1 - sin(x)));
}

double (*calc[10])() = {calc_0,calc_1};



///////////////////////////////////////////////////////////
//funcoes set_glbvars

int set_glbvars_0(){
	i = 0;
	jumps = 1000;
	offset = 100000;
	r_min = 2.3;
	r_max = 4.0;
	x_min = 0.0;
	x_max = 1.0;
	num_pontos = 500;
	x0 = 0.5;
	r = 2.3;
	x = 0.5;	
return 1;
}

int set_glbvars_1(){
	i = 0;
	jumps = 250;
	offset = 50000;
	r_min = 2.3;
	r_max = 20.0;
	x_min = 0.0;
	x_max = 3.0;
	num_pontos = 200;
	x0 = 0.5;
	r = r_min;
	x = x0;
return 1;
}

int (*set_glbvars[10])() = {set_glbvars_0,set_glbvars_1};

int draw_eixos(){
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	//Eixo XX
	glVertex2f(r_min-0.05,x_min);
	glVertex2f(r_max+0.003,x_min);
	//Eixo YY
	glVertex2f(r_min,x_min-0.05);
	glVertex2f(r_min,x_max);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(r_max, x_min + 0.01);
	glVertex2f(r_max, x_min -0.01);
	glVertex2f(r_max+ 0.02, x_min);
	
	glColor3f(1.0f, .0f, 0.0f);
        glVertex2f(r_min - 0.01,x_max);
	glVertex2f(r_min +0.01, x_max);
	glVertex2f(r_min, x_max +0.02);
        glEnd();
	glFlush();
return 1;
}

 //////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void){
	while (i < (offset + num_pontos)){
		x = calc[n]();
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
// Called by GLUT library when idle (window not being resized or moved)
void TimerFunction(int value){
	i = 0;
	x = x0;
	r+= (1.0/jumps);
	while (i < offset){
		x = calc[n]();
		i++;
	}
	draw_eixos();
	// Redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(1,TimerFunction, 1);
}

 //////////////////////////////////////////////////////////
// Set up the Rendering state
void SetupRC(void)
	{
	// Set clear color to blue
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	}

///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(GLsizei w, GLsizei h){	
	wgl = w; hgl = h;
	set_glbvars[n]();
	glClear(GL_COLOR_BUFFER_BIT);
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (r_min-0.1 , r_max + 0.1  , x_min-0.1, x_max + 0.1 , 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
printf("%d\t%d\n",wgl,hgl);
}


int verify_args(int argc, char *argv[]){
	if (argc!=2){
		printf("\n./logistic num_funcao\n");
		return 0;
	}
	else {
		sscanf(argv[1],"%d",&n);
		if ((n<0)||(n>=10)) return 0;
		else return 1;
	}

}

void mouse(int button, int state, int r1, int x1){
	double dot_r,dot_x;
	dot_r = ((r_max-r_min+0.2)*r1/wgl)+r_min-0.1;
	dot_x = ((x_max-x_min+0.2)*(hgl-x1)/hgl)+x_min-0.1;
	if (state == GLUT_UP){
		printf("%d\n%d\n",r1,x1);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POINTS);
		glVertex2f(dot_r,dot_x);
		glEnd();
	}
}

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	if (!(verify_args(argc,argv))) return 0;
	else {

		set_glbvars[n]();
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(wgl,hgl);
		glutCreateWindow("Logistic Map");
		glutDisplayFunc(RenderScene);
		glutReshapeFunc(ChangeSize);
		glutTimerFunc(1, TimerFunction, 1);
		glutMouseFunc(mouse);
		SetupRC();	
		glutMainLoop();
	}
return 0;
}

