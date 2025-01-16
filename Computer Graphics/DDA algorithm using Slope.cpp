#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

float x1, y1, x2, y2, x_inc, y_inc, dx, dy;
float x,y,m,steps;

void myInit (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,50.0,0.0,50.0);
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 1.0, 0.0);
	glPointSize(3.0);

	glBegin(GL_POINTS);
	        dx = (x2 - x1);
            dy = (y2 - y1);
            m = abs(dy)/abs(dx);

            if (abs(dx) >= abs(dy)) {
                   steps = abs(dx);
            } else {
                   steps = abs(dy);
            }

            if (m <= 1 && dx > 0 && dy > 0) {
                   x_inc = 1;
                   y_inc = m;
            }
            else if (m <= 1 && dx <= 0 && dy > 0) {
                   x_inc = -1;
                   y_inc = m;
            }
            else if (m <= 1 && dx > 0 && dy <= 0) {
                  x_inc = 1;
                  y_inc = -m;
           }
           else if (m <= 1 && dx <= 0 && dy <= 0) {
                  x_inc = -1;
                  y_inc = -m;
           }
           else if (m > 1 && dx > 0 && dy > 0) {
                 x_inc = (1 / m);
                 y_inc = 1;
           }
           else if (m > 1 && dx <= 0 && dy > 0) {
                 x_inc = -(1 / m);
                 y_inc = 1;
           }
           else if (m > 1 && dx > 0 && dy <= 0) {
                x_inc = (1 / m);
                y_inc = -1;
           }
           else if (m > 1 && dx <= 0 && dy <= 0) {
                x_inc = -(1 / m);
                y_inc = -1;
           }
           else if(m<0){
             printf("Error");
           }
           x = x1;
           y = y1;

           /// Draw the line
          for (int i = 0; i < steps; i++) {
              glVertex2i(x,y);            /// Round to nearest integer for pixel coordinates
              x += x_inc;
              y += y_inc;
          }

    glEnd();                             /// Ending & Saving Coordinates in Refresh Buffer
	glFlush ();
}
int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center:\n\n" << endl;
	cout << "First X-coordinate   : "; cin >> x1;
	cout << "\n First Y-coordinate : "; cin >> y1;
	cout << "Second X-coordinate   : "; cin >> x2;
	cout << "\n Second Y-coordinate : "; cin >> y2;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}
