#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#include<cstdio>

# define PI           3.14159265358979323846

GLfloat k = 0.0f;
GLfloat l = 0.0f;
GLfloat m = 0.0f;



void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	int i;

	 glBegin(GL_QUADS);//Background color
                glColor3ub(204,229,255);

                glVertex2f(1,1);
                glVertex2f(1,-1);
                glVertex2f(-1,-1);
                glVertex2f(-1,1);

                glEnd();



    glColor3ub(255,255,153);

	int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat x=0.0f; GLfloat y=0.0f; GLfloat radius =.85f;


	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
    glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    //Pin of the clock
	glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(0.0,0.8);
        glVertex2f(-0.05,0.75);
        glVertex2f(0.0,0.7);
        glVertex2f(0.05,0.75);


        glVertex2f(0.0,-0.8);
        glVertex2f(-0.05,-0.75);
        glVertex2f(0.0,-0.7);
        glVertex2f(0.05,-0.75);


        glVertex2f(-0.8,-0.0);
        glVertex2f(-0.75,-0.05);
        glVertex2f(-0.7,0.0);
        glVertex2f(-0.75,0.05);



        glVertex2f(0.8,-0.0);
        glVertex2f(0.75,-0.05);
        glVertex2f(0.7,0.0);
        glVertex2f(0.75,0.05);
    glEnd();


    //Sec
    glPushMatrix();
    glRotatef(k,0,0,1);

    glBegin(GL_LINES);
        glColor3ub(0,255,0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.7);

    glEnd();
    glLoadIdentity();

    glPopMatrix();


    //Min
    glPushMatrix();
    glRotatef(l,0,0,1);

    glBegin(GL_LINES);
        glColor3ub(255,0,0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.7);

    glEnd();
    glLoadIdentity();

    glPopMatrix();


    //Hour
    glPushMatrix();
    glRotatef(m,0,0,1);

    glBegin(GL_LINES);
        glColor3ub(0,0,255);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.7);

    glEnd();
    glLoadIdentity();

    glPopMatrix();

    //center box
    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(0.0,0.05);
        glVertex2f(-0.05,0.0);
        glVertex2f(0.0,-0.05);
        glVertex2f(0.05,0.0);
    glEnd();



    k-=0.0015;
    l-=0.000025;
    m-=0.000000416667;

	glFlush();  // Render now

}

void Idle() {
    glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);  // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutIdleFunc(Idle);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
