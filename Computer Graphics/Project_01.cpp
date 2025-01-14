#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void)
{
    glClearColor(0.62, 0.769, 0.341, 0.659);    // Set Background Display Window Color
    glMatrixMode(GL_PROJECTION);         // Set Projection Parameters
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);    // Set Orthogonal reference Frame's/ Graphs Limit (X axis & Y axis)
}

void drawFlag()
{
    // Draw the flag stand (wider and taller)
    glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0); // Black color for the stand
        glVertex2f(2.0, 2.0);         // Bottom left
        glVertex2f(2.2, 2.0);         // Bottom right
        glVertex2f(2.2, 8.0);         // Top right
        glVertex2f(2.0, 8.0);         // Top left
    glEnd();

    // Draw the first section of the flag (Sky Blue)
    glBegin(GL_QUADS);
        glColor3f(0.53, 0.81, 0.92); // Sky Blue color
        glVertex2f(2.2, 8.0);         // Top left (aligned with the stand)
        glVertex2f(6.0, 8.0);         // Top right
        glVertex2f(6.0, 7.0);         // Bottom right
        glVertex2f(2.2, 7.0);         // Bottom left
    glEnd();

    // Draw the second section of the flag (White)
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0); // White color
        glVertex2f(2.2, 7.0);         // Top left
        glVertex2f(6.0, 7.0);         // Top right
        glVertex2f(6.0, 6.0);         // Bottom right
        glVertex2f(2.2, 6.0);         // Bottom left
    glEnd();

    // Draw the third section of the flag (Sky Blue)
    glBegin(GL_QUADS);
        glColor3f(0.53, 0.81, 0.92); // Sky Blue color
        glVertex2f(2.2, 6.0);         // Top left
        glVertex2f(6.0, 6.0);         // Top right
        glVertex2f(6.0, 5.0);         // Bottom right
        glVertex2f(2.2, 5.0);         // Bottom left
    glEnd();

    // Draw the triangular roof
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0.439, 0.259);
        glVertex2i(7, 6);                // Vertex or Points Coordinates
        glVertex2i(5, 4);
        glVertex2i(9, 4);
    glEnd();

    // Draw the building structure
    glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(5, 4);                // Bottom left
        glVertex2i(5, 2);                // Bottom right
        glVertex2i(9, 2);                // Top right
        glVertex2i(9, 4);                // Top left
    glEnd();

    // Draw the door
    glBegin(GL_QUADS);
        glColor3f(0.545, 0.271, 0.075); // Brown color for the door
        glVertex2f(6.0, 2.0);            // Bottom left
        glVertex2f(7.0, 2.0);            // Bottom right
        glVertex2f(7.0, 3.5);            // Top right
        glVertex2f(6.0, 3.5);            // Top left
    glEnd();
}

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);        // Clear Background Display Window

    drawFlag();                          // Draw the flag and building

    glFlush();                           // Process all OpenGL Functions and Force Execution to Display
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                      // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set Display Mode

    glutInitWindowPosition(100, 100);                // Set Window Showing Position
    glutInitWindowSize(500, 500);                    // Set Window Size
    glutCreateWindow("Flag with Stand and Door");    // Set the Name of the Display Window

    init();                   // Execute Initialization Procedure
    glutDisplayFunc(display); // Send Graphics to Display Window
    glutMainLoop();           // Display Everything and Wait

    return 0;
}
