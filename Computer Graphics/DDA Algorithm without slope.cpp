#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

float x1 = 1.0, y1 = 1.0; // Starting point
float x2 = 8.0, y2 = 6.0; // Ending point
float x_inc, y_inc, x, y;
float dx, dy, steps;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);    // Set Background Display Window Color
    glMatrixMode(GL_PROJECTION);         // Set Projection Parameters
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);    // Set Orthogonal reference Frame's/ Graphs Limit (X axis & Y axis)
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);        // Clear Background Display Window

    glColor3f(1.0, 0.302, 0.004);
    glPointSize(3.0);
    glBegin(GL_POINTS); // Use GL_POINTS to draw individual pixels

    dx = x2 - x1;
    dy = y2 - y1;

    // Calculate the number of steps needed
    steps = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy);

    // Calculate the increment in x and y for each step
    x_inc = dx / steps;
    y_inc = dy / steps;

    x = x1;
    y = y1;

    // Draw the line
    for (int i = 0; i <= steps; i++) {
        glVertex2i(round(x), round(y)); // Round to nearest integer for pixel coordinates
        x += x_inc;
        y += y_inc;
    }

    glEnd();                             // Ending & Saving Coordinates in Refresh Buffer

    glFlush();                           // Process all OpenGL Functions and Force Execution to Display
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                      // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set Display Mode

    glutInitWindowPosition(100, 100);                // Set Window Showing Position
    glutInitWindowSize(500, 500);                    // Set Window Size
    glutCreateWindow("Basic OpenGL Lines & Shapes"); // Set the Name of the Display Window

    init();                   // Execute Initialization Procedure
    glutDisplayFunc(display); // Send Graphics to Display Window
    glutMainLoop();           // Display Everything and Wait

    return 0;
}
