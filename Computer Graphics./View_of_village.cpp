#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include <Mmsystem.h>   ///For music
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416
using namespace std;

///==================================================///
///      Name: Ahad Hosen Akash                      ///
///      Id: 21111121                                ///
///      Dept. of Computer Science and Engineering   ///
///      Jamalpur Science And Technology University  ///
///==================================================///

GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;
bool f=1;

void init(void)
{
	glClearColor(0.40,0.110, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

///-----------------------------All_Model------------------------------
///Circle_Model
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

///Sun Model
void Sun_Model(){
    glPushMatrix();
    glTranslatef(500,0,0);
    circle(30);
    glPopMatrix();
}
void Moving_Sun_Model(){
    glPushMatrix();
    glRotatef(-sun_spin, 0,0,-.009);
    Sun_Model();
    glPopMatrix();
}

///Cloud Model ///
void cloud_model_one(){
    if(f)
        glColor3f(1.0,1.0,1.0);
    else
        glColor3ub(169,169,169);
    ///Top Left
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();

    ///middle Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();
}

void lampB(){
    glTranslatef(50,100,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(10,0);
    glVertex2i(10,49);
    glVertex2i(0,49);
    glEnd();
}

void cloud_model_Two(){
    if(f)
        glColor3f(1.0,1.0,1.0);
    else
        glColor3ub(169,169,169);
    ///Left Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();
}

void cloud_model_Three(){
    if(f)
        glColor3f(1.0,1.0,1.0);
    else
        glColor3ub(169,169,169);
    ///Left Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top Left
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();
}

///Hill Model
void hill_big(){
    ///Hill
	glBegin(GL_POLYGON);
        glColor3f(0.38, 0.41, 0.36);
        glVertex2i(70, 70);
        glVertex2i(200, 225);
        glVertex2i(330, 70);
	glEnd();

	///Hill Snow
    glBegin(GL_POLYGON);
        if (f)
            glColor3f(1.0, 1.0, 1.0);            /// Daytime snow (pure white)
        else
            glColor3ub(172, 174, 176);           /// Nighttime snow (light gray with dim lighting)
	    glVertex2i(200, 225);
	    glVertex2i(230, 190);
	    glVertex2i(220, 180);
	    glVertex2i(200, 190);
	    glVertex2i(190, 180);
        glVertex2i(170, 190);
	glEnd();
}
void hill_small(){
    ///Hill Small
	glBegin(GL_POLYGON);
        glColor3f(0.11, 0.23, 0.36);
	    glVertex2i(250, 100);
	    glVertex2i(310, 175);
	    glVertex2i(370, 100);
	glEnd();

    ///Hill Small Snow
	glBegin(GL_POLYGON);
        if (f)
             glColor3f(1.0, 1.0, 1.0);            /// Daytime snow (pure white)
        else
             glColor3ub(172, 174, 176);           /// Nighttime snow (light gray with dim lighting)
        glVertex2i(290, 150);
        glVertex2i(310, 175);
	    glVertex2i(330, 150);
	    glVertex2i(325, 140);
	    glVertex2i(310, 150);
	    glVertex2i(300, 140);
	glEnd();
}

///Tilla Model
void Tilla_One_Model(){
    ///Tilla
	glBegin(GL_POLYGON);
	    if(f)
            glColor3f(0.1, 1.0, 0.0);         /// Daytime bright green for lush vegetation
        else
            glColor3ub(15, 59, 11);           /// Nighttime dark green
	    glVertex2i(125, 70);
	    glVertex2i(150, 80);
        glVertex2i(160, 90);
	    glVertex2i(170, 90);
	    glVertex2i(180, 100);
	    glVertex2i(190, 105);
	    glVertex2i(200, 108);
	    glVertex2i(300, 110);
	    glVertex2i(300, 70);
	glEnd();
}

void Tilla_Two_Model(){
	if(f)
            glColor3f(0.1, 1.0, 0.0);         /// Daytime bright green for lush vegetation
    else
            glColor3ub(15, 59, 11);           /// Nighttime dark green
    /// Left Part
    glPushMatrix();
    glTranslatef(430,90,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,87,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,70,0);
    circle(30);
    glPopMatrix();

    ///Right Part
    glPushMatrix();
    glTranslatef(445,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,75,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,70,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,65,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,60,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,55,0);
    circle(20);
    glPopMatrix();
}

///House Model
void house(){
    ///House Roof
	glBegin(GL_POLYGON);
        glColor3f(.990, 0.0, 0.0);
	    glVertex2i(285, 105);
	    glVertex2i(285, 130);
	    glVertex2i(380, 115);
	    glVertex2i(380, 105);
	glEnd();

    ///House Roof Shadow
	glBegin(GL_POLYGON);
        glColor3f(.890, 0.0, 0.0);
	    glVertex2i(285, 105);
	    glVertex2i(285, 120);
	    glVertex2i(380, 105);
	    glVertex2i(380, 105);
	glEnd();

    ///House Fence
	glBegin(GL_POLYGON);
        glColor3f(.555, 1.0, 1.0);
	    glVertex2i(290, 70);
	    glVertex2i(290, 104);
	    glVertex2i(375, 104);
	    glVertex2i(375, 70);
	glEnd();

    ///House Fence Shadow
	glBegin(GL_POLYGON);
        glColor3f(.555, 0.924, 0.930);
	    glVertex2i(310, 70);
	    glVertex2i(350, 104);
	    glVertex2i(375, 104);
	    glVertex2i(375, 70);
	glEnd();

    ///House Door
	glBegin(GL_POLYGON);
        glColor3f(0.38, 0.41, 0.36);
	    glVertex2i(330, 70);
	    glVertex2i(330, 100);
	    glVertex2i(350, 100);
	    glVertex2i(350, 70);
	glEnd();

    ///HouseWindow 1
	glBegin(GL_POLYGON);
        glColor3f(0.38, 0.21, 0.26);
	    glVertex2i(295, 75);
	    glVertex2i(295, 90);
	    glVertex2i(310, 90);
	    glVertex2i(310, 75);
	glEnd();

    ///House Window 2
	glBegin(GL_POLYGON);
        glColor3f(0.38, 0.21, 0.26);
	    glVertex2i(312, 75);
	    glVertex2i(312, 90);
	    glVertex2i(327, 90);
	    glVertex2i(327, 75);
	glEnd();

    ///House Window 3
	glBegin(GL_POLYGON);
        glColor3f(0.38, 0.21, 0.26);
	    glVertex2i(355, 75);
	    glVertex2i(355, 90);
	    glVertex2i(370, 90);
	    glVertex2i(370, 75);
	glEnd();

    ///House Small Roof
	glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
	    glVertex2i(250, 90);
	    glVertex2i(257, 104);
	    glVertex2i(290, 104);
	    glVertex2i(290, 90);
	glEnd();

    ///House Small Fence
	glBegin(GL_POLYGON);
        glColor3f(.555, .724, .930);
	    glVertex2i(255, 70);
	    glVertex2i(255, 90);
	    glVertex2i(290, 90);
	    glVertex2i(290, 70);
	glEnd();

    ///House Small Door
	glBegin(GL_POLYGON);
        glColor3f(0.11, 0.23, 0.36);
	    glVertex2i(260, 70);
	    glVertex2i(260, 80);
	    glVertex2i(285, 80);
	    glVertex2i(285, 70);
	glEnd();
}

///Field Model
void field(){
    ///Field Shadow
	glBegin(GL_POLYGON);
	    if(f)
            glColor3f(0.0, 0.3, 0.0);        /// Darker green for shadow under the field
        else
            glColor3ub(10, 40, 10);          /// Darker shadow for realism
	    glVertex2i(0, 0);
	    glVertex2i(0, 50);
	    glVertex2i(1000, 50);
	    glVertex2i(1000, 0);
	glEnd();
}

void roadstrip() {
    /// Road (Dark Gray)
    glBegin(GL_POLYGON);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray
        glVertex2i(0, 50);
        glVertex2i(0, 70);
        glVertex2i(1000, 70);
        glVertex2i(1000, 50);
    glEnd();

    /// Road Markings (White)
    glColor3ub(255, 255, 255); // White color for stripes

    for (int x = 50; x <= 950; x += 100) { // Adjusted starting position and spacing
        glBegin(GL_POLYGON);
            glVertex2i(x, 60);  // Centered along the y-axis of the road
            glVertex2i(x + 50, 60);
            glVertex2i(x + 50, 55);
            glVertex2i(x, 55);
        glEnd();
    }
}

///Tree Model
void Tree_Model_One() {
    /// Drawing the top part of the tree (Leaf canopy)
    glPushMatrix();
    glTranslatef(110, 110, 0);                       /// Move the circle to (110, 110)
    circle(15);                                      /// Draw a circular shape with radius 15 (Top Leaf)
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110, 100, 0);                       /// Move the circle slightly lower to (110, 100)
    circle(15);                                      /// Draw another circle for the leaf structure
    glPopMatrix();
    /// Drawing the trunk of the tree
    glBegin(GL_POLYGON);
        if (f)
            glColor3ub(0, 173, 36);                  /// Green shade if 'f' is true
        else
            glColor3ub(17, 102, 30);                 /// Darker green shade if 'f' is false

        glVertex2f(109, 70);                         /// Bottom-left of the trunk
        glVertex2f(109, 90);                         /// Top-left of the trunk
        glVertex2f(111, 90);                         /// Top-right of the trunk
        glVertex2f(111, 70);                         /// Bottom-right of the trunk
    glEnd();
}
void Tree_Model_Two(){
    glPushMatrix();
    glTranslatef(130,130,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,125,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
        if(f)
            glColor3ub(0, 173, 36);
        else
            glColor3ub(17, 102, 30);
	    glVertex2f(129, 110);
	    glVertex2f(129, 124);
	    glVertex2f(131, 124);
	    glVertex2f(131, 110);
    glEnd();
}

void Tree_Model_Three(){
    glBegin(GL_POLYGON);
	    glVertex2f(125, 123);
	    glVertex2f(133, 145);
	    glVertex2f(141, 123);
	glEnd();

    glBegin(GL_POLYGON);
        if(f)
            glColor3ub(0, 173, 36);
        else
            glColor3ub(17, 102, 30);
	    glVertex2f(132, 110);
	    glVertex2f(132, 124);
	    glVertex2f(134, 124);
	    glVertex2f(134, 110);
    glEnd();
}

///Windmill Stand Model
void Windmill_Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
        glVertex2i(375, 100);
        glVertex2i(380, 240);
        glVertex2i(384, 240);
        glVertex2i(390, 100);
    glEnd();
}

///Windmill Blades Model
void Windmill_Blade(){

    ///Blade One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();
}

///Windmill Final Model
void Windmill(){
    ///Windmill Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill Rotary Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();
}

///Sun
void Sun(){
    if(f){
        glColor3f(1, 1, 0);
        glPushMatrix();
        Moving_Sun_Model();
        glPopMatrix();
    }
}
void moon(){
    if(!f){
        glPushMatrix();
        glColor3ub(245, 245, 220);       /// Realistic moon color (soft pale yellowish-white)
        Moving_Sun_Model();;
        glPopMatrix();
    }
}
///Cloud One Model One
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,-40,0);
    cloud_model_one();
    glPopMatrix();
}
///Cloud two Model One
void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    cloud_model_one();
    glPopMatrix();

}
///Cloud Three Model Two
void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,80,0);
    cloud_model_Two();
    glPopMatrix();
}
///Cloud Four Model Two
void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_model_Two();
    glPopMatrix();
}
///Cloud Five Model Three
void cloud_five(){
    glPushMatrix();
    glTranslatef(ax+-300,170,0);
    cloud_model_Three();
    glPopMatrix();
}

///Cloud Six Model Three
void cloud_six(){
    glPushMatrix();
    glTranslatef(cx+-500,20,0);
    cloud_model_Three();
    glPopMatrix();
}

///House One
void house_one(){
    glPushMatrix();
    glTranslatef(0,0,0);
    house();
    glPopMatrix();
}
///House Two
void house_two(){
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}
///House Three
void house_three() {
    glPushMatrix();
    glTranslatef(320, 37, 0);              /// Move the house to position (320, 37)
    house();                               /// Call the house() function to draw the house
    glPopMatrix();                         /// Restore the previous transformation state
}


///Hill big One
void Hill_Big_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_big();
    glPopMatrix();
}

///Hill big Two
void Hill_Big_Two(){
    glPushMatrix();
    glTranslatef(550,-20,0);
    hill_big();
    glPopMatrix();
}
///Hill Small One
void Hill_Small_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_small();
    glPopMatrix();
}

///Tilla One Model One
void Tilla_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_One_Model();
    glPopMatrix();
}

///Tilla Two Model Two
void Tilla_Two(){
    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_Two_Model();
    glPopMatrix();
}

///Tilla Three Model Two
void Tilla_Three(){
    glPushMatrix();
    glTranslatef(400,0,0);
    Tilla_Two_Model();
    glPopMatrix();
}
///Tilla Four Model One
void Tilla_Four(){
    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380,0,0);
    Tilla_One_Model();
    glPopMatrix();
}
///Tree 1
void Tree_One(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///Tree 2
void Tree_Two(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///Tree 3
void Tree_Three(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///Tree 4
void Tree_Four(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292,40,0);
    Tree_Model_One();
    glPopMatrix();
}
///Tree 5
void Tree_Five(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30,-20,0);
    Tree_Model_Two();
    glPopMatrix();
}
///Tree 6
void Tree_Six(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50,-10,0);
    Tree_Model_Two();
    glPopMatrix();
}
///Tree 7
void Tree_Seven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322,0,0);
    Tree_Model_Two();
    glPopMatrix();
}
///Tree 8
void Tree_Eight(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350,-15,0);
    Tree_Model_Two();
    glPopMatrix();
}
///Tree 9
void Tree_Nine(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760,-25,0);
    Tree_Model_Two();
    glPopMatrix();
}
///Tree 10
void Tree_Ten(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90,-2,0);
    Tree_Model_Three();
    glPopMatrix();
}
///Tree 11
void Tree_Eleven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125,0,0);
    Tree_Model_Three();
    glPopMatrix();
}
///Tree 12
void Tree_Twelve(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408,-22,0);
    Tree_Model_Three();
    glPopMatrix();
}
///Windmill
void Windmill_One(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,-10,0);
    Windmill();
    glPopMatrix();
}
void Windmill_Two(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();
}
void Windmill_Three(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,-90,0);
    Windmill();
    glPopMatrix();
}
///Star
void star(){
    if(!f){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);
            glVertex2i(100,400);
            glVertex2i(120,420);
            glVertex2i(150,450);
            glVertex2i(170,470);
            glVertex2i(200,430);
            glVertex2i(230,470);
            glVertex2i(350,460);
            glVertex2i(900,400);
            glVertex2i(580,470);
            glVertex2i(840,460);
            glVertex2i(750,400);
            glVertex2i(950,400);
            glVertex2i(760,420);
            glVertex2i(690,450);
            glVertex2i(550,470);
            glVertex2i(790,430);
            glVertex2i(830,470);
            glVertex2i(690,460);
            glVertex2i(590,400);
            glVertex2i(490,430);
            glVertex2i(330,470);
            glVertex2i(390,460);
            glVertex2i(460,400);
            glVertex2i(490,330);
            glVertex2i(330,370);
            glVertex2i(390,360);
            glVertex2i(460,300);
            glVertex2i(990,230);
            glVertex2i(930,370);
            glVertex2i(990,360);
            glVertex2i(960,300);
            glVertex2i(160,300);
            glVertex2i(190,230);
            glVertex2i(30,370);
            glVertex2i(290,360);
            glVertex2i(260,300);
            glVertex2i(0,300);
            glVertex2i(90,230);
            glVertex2i(130,370);
            glVertex2i(60,360);
            glVertex2i(80,300);
            glVertex2i(570,200);
            glVertex2i(600,230);
            glVertex2i(630,270);
            glVertex2i(590,260);
            glVertex2i(680,200);
        glEnd();
        glPopMatrix();
    }
}
///Sky
void sky(){
    glPushMatrix();
    if(f)
        glColor3ub(135, 206, 250);
    else
        glColor3ub(4, 11, 51);
    glBegin(GL_POLYGON);
       glVertex2i(0, 0);               /// Bottom-left corner
       glVertex2i(1000, 0);            /// Bottom-right corner
       glVertex2i(1000, 500);          /// Top-right corner
       glVertex2i(0,500);              /// Top-left corner
    glEnd();
    glPopMatrix();                     /// Restore the previous transformation matrix
}

void river() {
    glBegin(GL_POLYGON);
        if (f)
            glColor3ub(28, 163, 236);  /// Realistic water blue (Sky reflection + slight green tint)
        else
            glColor3ub(10, 25, 68);    /// Dark blue for nighttime (Low light)
        glVertex2i(800, 40);           /// Bottom-left
        glVertex2i(820, 60);           /// Curve point 1
        glVertex2i(860, 80);           /// Curve point 2
        glVertex2i(900, 90);           /// Curve point 3
        glVertex2i(950, 100);          /// Curve point 4
        glVertex2i(1000, 110);         /// Top-right
        glVertex2i(1000, 0);           /// Bottom-right (closing the river)
    glEnd();
}

///Display Function
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);

        sky();
        star();
        Sun();
        moon();
        Windmill_Three();
        Hill_Big_One();
        Tilla_Four();
        house_three();
        Hill_Big_Two();
        Hill_Small_One();
        cloud_three();
        cloud_four();
        Windmill_One();
        Windmill_Two();
        Tilla_One();
        Tilla_Two();
        Tilla_Three();
        house_one();
        cloud_one();
        house_two();
        Tree_One();
        Tree_Two();
        Tree_Three();
        Tree_Four();
        Tree_Five();
        Tree_Six();
        Tree_Seven();
        Tree_Eight();
        Tree_Nine();
        Tree_Ten();
        Tree_Eleven();
        Tree_Twelve();
        cloud_two();
        cloud_five();
        cloud_six();
        field();
        roadstrip();
        river();
	glFlush();
}

///---------------------------Speed & Movement--------------------------
///Sun Move
void sun_move(){
    sun_spin = sun_spin + 0.0118;
}
void move_right(){
    sun_move();
    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    if(cx>1000){
        cx = -300;                 /// Reset cx to the left side
    }
    if(bx>1000){
            bx= -400;              /// Reset bx to the left side
    }
    if(cx>1000){
            cx= -400;
    }
    if(dx>1000){
            dx= -500;              /// Reset dx to the left side
    }
    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

void handleKeypress(unsigned char key, int x, int y){
	switch (key){
        case 'd':                           ///Press d for day mode
            f=1;
            break;
        case 'n':                           ///Press n for night mode
            f=0;
            break;
        glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
    PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);   /// Music Background   SND_ASYNC = play in background

	glutInit(&argc, argv);                           /// Initialize GLUT with command line arguments
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     /// Set display mode: single buffer & RGB color
	glutInitWindowPosition(50, 50);                  /// Window position and size
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("....Modern Village....");      /// Create window with title
	init();                                          /// Initialize OpenGL parameters
	glutDisplayFunc(display);
	glutKeyboardFunc(handleKeypress);                /// Keyboard input handler
    glutMouseFunc(mouse);                            /// Mouse input handler
	glutMainLoop();                                  /// Enters GLUT's infinite processing loop
}
