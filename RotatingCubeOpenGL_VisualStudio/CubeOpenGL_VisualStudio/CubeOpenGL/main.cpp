//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

//#include <glut.h> 
#include <Windows.h> 
 
float angle = 90.0f;
float mas[4] = {1.0, 0.0, 0.0, 0.0}; 


void drawCube(void){ 

glEnable(GL_LINE_SMOOTH); 
glEnable (GL_BLEND); 
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);

glColor3f(0.0, 0.0, 0.0); 

glLineWidth(2.0); 
  glBegin(GL_LINES); 
	glVertex3f( 0.0,    0.3,  0.425);
	glVertex3f( 0.425, -0.3,  0.0);
	glVertex3f( 0.425,  0.3,  0.0);
	glVertex3f( 0.0,   -0.3,  0.425);
	glVertex3f( 0.0,    0.3,  0.425);
	glVertex3f( 0.0,    0.3, -0.425);
	glVertex3f( 0.425,  0.3,  0.0);
	glVertex3f(-0.425,  0.3,  0.0);
	glVertex3f( 0.0,    0.3,  0.425);
	glVertex3f(-0.425, -0.3,  0.0);
	glVertex3f(-0.425,  0.3,  0.0);
	glVertex3f( 0.0,   -0.3,  0.425);
	glVertex3f( 0.0,   -0.3, -0.425);
	glVertex3f( 0.0,   -0.3,  0.425);
	glVertex3f( 0.425, -0.3,  0.0);
	glVertex3f(-0.425, -0.3,  0.0);
	glVertex3f( 0.0,   -0.3, -0.425);
	glVertex3f( 0.425,  0.3,  0.0);
	glVertex3f( 0.425, -0.3,  0.0);
	glVertex3f( 0.0,    0.3, -0.425);
	glVertex3f( 0.0,   -0.3, -0.425);
	glVertex3f(-0.425,  0.3,  0.0);
	glVertex3f( 0.0,    0.3, -0.425);
	glVertex3f(-0.425, -0.3,  0.0);
  glEnd();

	glLineWidth(0.6);
	glEnable(GL_LINE_STIPPLE); 
	glLineStipple(1, 0x00F0); 
  glBegin(GL_LINES); 
	glVertex3f( 0.0,    0.3,  0.425);
	glVertex3f( 0.0,   -0.3,  0.425);
	glVertex3f( 0.0,   -0.3,  0.425);
	glVertex3f( 0.425, -0.3,  0.0);
	glVertex3f( 0.425, -0.3,  0.0);
	glVertex3f( 0.425,  0.3,  0.0);
	glVertex3f( 0.425,  0.3,  0.0);
	glVertex3f( 0.0,    0.3,  0.425);
	glVertex3f( 0.0,    0.3,  0.425);
	glVertex3f(-0.425,  0.3,  0.0);
	glVertex3f(-0.425,  0.3,  0.0);
	glVertex3f( 0.0,    0.3, -0.425);
	glVertex3f( 0.0,    0.3, -0.425);
	glVertex3f( 0.425,  0.3,  0.0);	 
	glVertex3f(-0.425,  0.3,  0.0);
	glVertex3f(-0.425, -0.3,  0.0);
	glVertex3f(-0.425, -0.3,  0.0);
	glVertex3f( 0.0,   -0.3,  0.425);	
	glVertex3f( 0.0,   -0.3, -0.425);
	glVertex3f(-0.425, -0.3,  0.0);	 
	glVertex3f( 0.425, -0.3,  0.0);
	glVertex3f( 0.0,   -0.3, -0.425);
	glVertex3f( 0.0,   -0.3, -0.425);
	glVertex3f( 0.0,    0.3, -0.425);	 
  glEnd();
    glDisable(GL_LINE_STIPPLE); 
}


void change(float *arr){

	if(arr[0] == 1.0){
	 arr[1] = -0.2125;
	 arr[2] =  0.0;
	 arr[3] = -0.2125;
	 arr[0] =  2.0;
	 return;
	}
		
	 if(arr[0] == 2.0){
	 arr[1] =  0.2125;
	 arr[2] =  0.0;
	 arr[3] = -0.2125;
	 arr[0] =  3.0;
	 return;
	}
	
	if(arr[0] == 3.0){
	 arr[1] = 0.0;
	 arr[2] = -1.0;
	 arr[3] = 0.0;
	 arr[0] = 1.0;
	 return;
	}
}


void renderScene(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();
	
	glTranslatef(0.0, 0.0, 1.0); 
	
	if (mas[2] == -1.0){ 
		   gluLookAt( 0.0f, 0.6f, 0.85f, 
		   0.0f, 0.0f,  0.0f, 
		   0.0f, -1.0f,  0.0f); 
	}
	else {
		   gluLookAt(0.0f, 0.6f, 0.85f,
		   0.0f, 0.0f,  0.0f,
		   0.0f, 1.0f,  0.0f); 
	}

	if (angle != 90.0f)  
	   angle += 0.3125f;
	else { 
		angle = 0.0; 
		change(mas); 
		Sleep(300);
	}	
	
	Sleep(2); 

	glRotatef(angle, mas[1],  mas[2], mas[3]); 
	
	drawCube(); 

	
	glutSwapBuffers(); 
}


int main(int argc, char **argv) {
 
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("Cube");
 
	
	glutDisplayFunc(renderScene); 
	glutIdleFunc(renderScene); 
 
	
	glutMainLoop(); 
 
	return 1;
}