#include<GL/glut.h>
#include<windows.h>
#include<stdio.h>
#include <iostream>
using namespace std;

float x1,y1,x2,y2;
void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,100.0,0.0,100.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glPointSize(2.0);
    float dy,dx,x,y,m,p,xin,yin;

    dx=x2-x1 ;
    dy=y2-y1 ;
    m=abs(dy)/abs(dx);

    glBegin(GL_POINTS);

    x=x1;
    y=y1;

/// For slope less than to 1
    if(m<1 && dx>0 && dy>0 )
    {
        p=2*abs(dy)-abs(dx);
        while(x<=x2 && y<=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dy);
                x=x+1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dy)-2*abs(dx);
                x=x+1;
                y=y+1 ;
            }
        }
    }

    else if(m<1 && dx<0 && dy>0)
    {
        p=2*abs(dy)-abs(dx);
        while(x>=x2 && y<=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dy);
                x=x-1 ;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dy)-2*abs(dx) ;
                x=x-1;
                y=y+1 ;
            }
        }
    }

    else if(m<1 && dx>0 && dy<0)
    {
        p=2*abs(dy)-abs(dx);
        while(x<=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dy);
                x=x+1 ;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dy)-2*abs(dx) ;
                x=x+1;
                y=y-1 ;
            }
        }
    }

    else if(m<1 && dx<0 && dy<0)
    {
        p=2*abs(dy)-abs(dx);
        while(x>=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dy);
                x=x-1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dy)-2*abs(dx) ;
                x=x-1;
                y=y-1;
            }
        }
    }

/// For slope greater than and equal to 1
    else if(m>=1 && dx>0 && dy>0 )
    {
        p=2*abs(dx)-abs(dy);
        while(x<=x2 && y<=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dx) ;
                y=y+1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx)- 2*abs(dy);
                x=x+1 ;
                y=y+1 ;
            }
        }
    }
    else if(m>=1 && dx<=0 && dy>0)
    {
        p=2*abs(dx)-abs(dy);
        while(x>=x2 && y<=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dx);
                y=y+1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx)- 2*abs(dy);
                x=x-1;
                y=y+1;
            }
        }
    }

    else if(m>=1 && dx>0 && dy<0)
    {
        p=2*abs(dx)-abs(dy);

        while(x<=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dx) ;
                y=y-1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx)- 2*abs(dy);
                x=x+1;
                y=y-1;
            }
        }
    }

    else if(m>=1 && dx<0 && dy<0)
    {
        p=2*abs(dx)-abs(dy);
        while(x>=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);
                p=p+2*abs(dx);
                y=y-1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx)-2*abs(dy);
                x=x-1;
                y=y-1;
            }
        }
    }
    else
    {
        printf("Error 404!");
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    cout << ".........Bresenham Algorithm.........\n\n";
    cout << "Enter the coordinates of the Line......" << endl;
	cout << "First X-coordinate : "; cin >> x1;
	cout << "\nFirst Y-coordinate : "; cin >> y1;
	cout << "\nSecond X-coordinate : "; cin >> x2;
	cout << "\nSecond Y-coordinate : "; cin >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition (100,100);
    glutCreateWindow("line draw");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}
