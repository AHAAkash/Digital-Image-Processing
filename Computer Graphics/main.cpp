#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

/// Defining xMax, yMax and xMin, yMin for clipping rectangle. Since diagonal points are enough to define a rectangle
GLfloat xMin=-0.5,xMax=0.5,yMin=-0.5,yMax=0.5;
/// Defining x1, y1 and x2, y2 for clipping rectangle
GLfloat x1,y1,x2,y2;

int Left=1,Right=2,Bot=4,Top=8; /// Defining region codes
int C1,C2;
int Clip_Flag = 0, Flag = 1;;

/// Function to compute region code for a point(x, y)
int Get_Code(GLfloat x,GLfloat y)
{
    int Code = 0;
    if(x<xMin)
        Code = Code | Left;
    if(x>xMax)
        Code = Code | Right;
    if(y<yMin)
        Code = Code | Bot;
    if(y>yMax)
        Code = Code | Top;
    return Code;
}

/// Implementing Cohen-Sutherland algorithm
void Clip()
{
    int C;
    GLfloat x,y;
    if(C1)          ///If both endpoints lie within rectangle
        C = C1;
    else            ///If both endpoints are outside rectangle, in same region
        C = C2;

    if(C & Left)    ///point is to the left of rectangle
    {
        x = xMin;
        y = y1+(y2-y1)*((xMin-x1)/(x2-x1));
    }
    if(C & Right)   ///point is to the right of rectangle
    {
        x = xMax;
        y = y1+(y2-y1)*((xMax-x1)/(x2-x1));
    }
    if(C & Bot)     /// point is below the rectangle
    {
        y = yMin;
        x = x1+(x2-x1)*((yMin-y1)/(y2-y1));
    }
    if(C & Top)     /// point is above the clip rectangle
    {
        y = yMax;
        x = x1+(x2-x1)*((yMax-y1)/(y2-y1));
    }

    /// Now intersection point x,y is found We replace point outside rectangle by intersection point
    if(C == C1)
    {
        x1 = x;
        y1 = y;
    }
    else
    {
        x2 = x;
        y2 = y;
    }
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);  ///For Drawing Rectangle
    glBegin(GL_LINE_LOOP);
        glVertex2f(xMin,yMin);
        glVertex2f(xMax,yMin);
        glVertex2f(xMax,yMax);
        glVertex2f(xMin,yMax);
    glEnd();

    glColor3f(1,0,0);  ///For Drawing Lines
    if(Flag == 1)
    {
     glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    }

    while(1 & Clip_Flag == 1)
    {
        C1 = Get_Code(x1,y1);
        C2 = Get_Code(x2,y2);

        if((C1|C2) == 0)
            break;
        else if((C1&C2)!=0)
        {
            Flag = 0;
            break;
        }
        else
            Clip();
    }
    glFlush();
}

/// This function for remove the extra line in outside of the Rectangle. For pressing any key in the lines then it works it
void Key(unsigned char ch,int x,int y)
{
    Clip_Flag = 1;
    glutPostRedisplay();
}

int main(int argC,char *argV[])
{
    cout << ".........Cohen-Sutherland Algorithm.........\n\n";
    cout << "Enter the coordinates of the Line......" << endl;
	cout << "First X-coordinate : "; cin >> x1;
	cout << "\nFirst Y-coordinate : "; cin >> y1;
	cout << "\nSecond X-coordinate : "; cin >> x2;
	cout << "\nSecond Y-coordinate : "; cin >> y2;

    glutInit(&argC,argV);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Cohen-Sutherland Algorithm");
    glutDisplayFunc(Display);
    glutKeyboardFunc(Key);
    glutMainLoop();
    return 0;
}
