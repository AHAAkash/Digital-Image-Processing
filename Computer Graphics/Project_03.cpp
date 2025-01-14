#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
GLfloat T = 0;   //Start the rotation from 0 degree
void Spin()
{
    //Increasing the degree
    T = T+0.08;
    if(T > 360)
        T = 0;
    glutPostRedisplay();   // This call the displayCall function back
}
void MyInit()
{
    glClearColor(0,0,0,0);
    glColor3f(1,1,1);
    glEnable(GL_DEPTH_TEST);
}
void Face(GLfloat a[],GLfloat b[],GLfloat c[],GLfloat d[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(a);
        glVertex3fv(b);
        glVertex3fv(c);
        glVertex3fv(d);
    glEnd();
}
void Cube(GLfloat v0[],GLfloat v1[],GLfloat v2[],GLfloat v3[],GLfloat v4[],GLfloat v5[],GLfloat v6[],GLfloat v7[])
{
    glColor3f(1,0,0);  //Front color
    Face(v0,v1,v2,v3);

    glColor3f(0,1,0);  //Back color
    Face(v4,v5,v6,v7);

    glColor3f(0,0,1);  //Left color
    Face(v0,v3,v7,v4);

    glColor3f(1,0,1);  //Right color
    Face(v1,v2,v6,v5);

    glColor3f(1,1,0);  //Top color
    Face(v0,v1,v5,v4);

    glColor3f(0,1,1);  //Right color
    Face(v3,v2,v6,v7);
}
void Draw()
{
    GLfloat V[8][3]={
                            {-0.5, 0.5, 0.5},
                            { 0.5, 0.5, 0.5},
                            { 0.5,-0.5, 0.5},
                            {-0.5,-0.5, 0.5},

                            {-0.5, 0.5,-0.5},
                            { 0.5, 0.5,-0.5},
                            { 0.5,-0.5,-0.5},
                            {-0.5,-0.5,-0.5},
                           };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(T,1,1,0);

    Cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);

    glutSwapBuffers();
}
int main(int C, char *V[])
{
    glutInit(&C,V);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Basic OpenGL Program");

    MyInit();

    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutMainLoop();

    return 0;
}
