
#include <stdlib.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
float rAngle  = 0.0;
float translate=0.0;
float i;
int j;
#define PI 3.1415926535898


  void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27:
			exit(0);
	  }
   }


   void initRendering() {
	  glEnable(GL_DEPTH_TEST);
     }
   void handleResize(int w, int h) {
	 glViewport(0, 0, w, h);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluPerspective(45.0,
				   (double)w / (double)h,
				   1.0,
				   200.0);
    }

   void update(int value){
      rAngle += 1.0f;
      if(rAngle > 360){
         rAngle -= 360;
        }
        translate-= 0.01;
         if( translate <=- 2.2)
            {
                 translate += 0.01;
            }
            glutPostRedisplay();
       glutTimerFunc(25,update,0);

            }



    void drawScene() {
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslated(0,-1.0,0);

	// Drawing  the center planet

        glColor3d(0.0,0.0,1.0);
        glBegin(GL_POINTS);
        for(j=0;j<1000;++j)
            {
             glVertex2d(0.65 * cos(3.14159*j/1000.0),0.65 * sin(3.14159*j/1000.0));
            }
        glEnd();
        glutSwapBuffers();

    //Drawing the sun

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslated(0.0,-0.85,0);

        glRotatef(rAngle, 0.0f, 0.0f, 1.0f);
        // Rotation about the axis
        glTranslated(0.3,-0.85,0);

        glBegin(GL_POINTS);
        for(j=0;j<1000;++j)
          {
           glVertex2d(0.08* cos(2*3.14159*j/1000.0),0.08 * sin(2*3.14159*j/1000.0));
          }

        glEnd();
        glFlush();
        glutSwapBuffers();

    // Drawing a few stars

       // Star 1

          //Upper triangle

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(-0.75,0.7);
          glVertex2f(-0.7,0.75);
          glVertex2f(-0.65,0.7);
          glEnd();
          glFlush();
          glutSwapBuffers();

          //Lower Triangle
          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(-0.75,0.73);
          glVertex2f(-0.65,0.73);
          glVertex2f(-0.70,0.68);
          glEnd();
          glFlush();
          glutSwapBuffers();
       // Star2

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(-0.45,0.5);
          glVertex2f(-0.4,0.55);
          glVertex2f(-0.35,0.5);
          glEnd();
          glFlush();
          glutSwapBuffers();

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(-0.45,0.53);
          glVertex2f(-0.35,0.53);
          glVertex2f(-0.40,0.48);
          glEnd();
          glFlush();
          glutSwapBuffers();

       // Star3

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(0.15,0.5);
          glVertex2f(0.2,0.55);
          glVertex2f(0.25,0.5);
          glEnd();
          glFlush();
          glutSwapBuffers();

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(0.15,0.53);
          glVertex2f(0.25,0.53);
          glVertex2f(0.20,0.48);
          glEnd();
          glFlush();
          glutSwapBuffers();

       // Star 4

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(-0.15,0.7);
          glVertex2f(-0.1,0.75);
          glVertex2f(-0.05,0.7);
          glEnd();
          glFlush();
          glutSwapBuffers();

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(-0.15,0.73);
          glVertex2f(-0.05,0.73);
          glVertex2f(-0.10,0.68);
          glEnd();
          glFlush();
          glutSwapBuffers();

       // Star 5

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(0.55,0.7);
          glVertex2f(0.5,0.75);
          glVertex2f(0.45,0.7);
          glEnd();
          glFlush();
          glutSwapBuffers();

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glColor3d(1.0,1.0,0.0);
          glBegin(GL_POLYGON);
          glVertex2f(0.55,0.73);
          glVertex2f(0.45,0.73);
          glVertex2f(0.50,0.68);
          glEnd();
          glFlush();
          glutSwapBuffers();



   //  Drawing the rocket front end

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef( translate,0,0 );
        glColor3d(1.0,0.0,0.0);
        glTranslated(0.5,-0.1,0);
        glBegin(GL_POLYGON);
        glVertex2f(0.2,0.3);
        glVertex2f(0.28,0.37);
        glVertex2f(0.28,0.23);
        glEnd();
        glFlush();
        glutSwapBuffers();

    //  Drawing the rocket rear end

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef( translate,0,0 );
        glColor3d(1.0,0.0,1.0);
        glTranslated(0.5,-0.1,0);
        glBegin(GL_POLYGON);
        glVertex2f(0.28,0.34);
        glVertex2f(0.36,0.34);
        glVertex2f(0.36,0.26);
        glVertex2f(0.28,0.26);
        glEnd();
        glFlush();
        glutSwapBuffers();

    // Drawing the rocket fumes

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef( translate,0,0 );
        glColor3d(1.0,0.5,0.0);
        glTranslated(0.5,-0.1,0);
        glBegin(GL_LINES);
        glVertex2f(0.36,0.33);
        glVertex2f(0.42,0.35);
        glVertex2f(0.36,0.30);
        glVertex2f(0.42,0.30);
        glVertex2f(0.36,0.26);
        glVertex2f(0.42,0.24);
        glEnd();
        glFlush();
        glutSwapBuffers();
}




 void Init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
     }

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(550, 400);
	glutCreateWindow("The Stars and The Sun");
	Init();
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);;
	glutTimerFunc(2,update,0);
	glutMainLoop();
    return 0;
}
