#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <Mmsystem.h>  ///For music
#include<windows.h>
#include<fstream>
using namespace std;
#define int GLint
#define PI 3.1416

bool f=1;
float pos1=990,pos3=600,pos2=-100,speed1=2.9f, speed2=2.5f, speed3=1.95f;
float spin=0.0f,cpos1=200,cpos2=400,cpos3=-250,cpos4=50,cpos5=490,sp1=2.0f;
float sun_x=620 ,sun_y=310,sp_x=0.5f,sp_y=1.0f,plane_x=0.0f, plane_speed=4.5f;

///Circle
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60,i;
    GLfloat t_pi=2*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}
///Cloud Model-1 Structure
void cloudModel1(){
    if(f)
        glColor3f(1.0,1.0,1.0);
    else
        glColor3ub(169,169,169);

    glPushMatrix();
    circle(320,210,15);///Left
    circle(340,225,16);///Top
    circle(360,210,16);///Right
    ///Bottom
    circle(330, 210, 16);
    circle(340, 210, 16);
    circle(350, 210, 16);
    glPopMatrix();
}
///Cloud Model-2 Structure
void cloudModel2(){
    if(f)
        glColor3f(1.0,1.0,1.0);
    else
        glColor3ub(169,169,169);

    glPushMatrix();
    circle(305,205,10);    ///Left
    circle(320,210,15);    ///Top
    circle(334,207,10);    ///Right
    circle(320, 207, 10);  ///Bottom
    glPopMatrix();
}
///Cloud Model-3 Structure
void cloudModel3(){
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    circle(300,200,15);  ///Left
    circle(320,210,15);  ///Top Left
    circle(340,220,16);  ///Top
    circle(360,210,15);  ///Top Right
    circle(380,200,15);  ///Right
    circle(360,190,20);  ///Bottom Right
    circle(320,190,20);  ///Bottom Left
    circle(340,190,20);  ///Bottom
    glPopMatrix();
}

/// Big Hill Structure
void hill_big() {
    /// Hill Color (Green or brown for natural hill)
    glColor3ub(34, 139, 34);                  /// Forest green for a natural, lush hill color
    glBegin(GL_POLYGON);
        glVertex2i(70, 70);
        glVertex2i(200, 225);
        glVertex2i(330, 70);
    glEnd();
    /// Snow on top of the hill (Bright white or light gray depending on time of day)
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
/// Small Hill Structure
void hill_small(){
    /// Hill Small Color (Green or brown for a natural small hill)
    glColor3ub(34, 139, 34);              /// Forest green for a natural, lush hill color
    glBegin(GL_POLYGON);
        glVertex2i(250, 100);             /// Left base of the hill
        glVertex2i(310, 175);             /// Peak of the hill
        glVertex2i(370, 100);             /// Right base of the hill
    glEnd();
    /// Small Hill Snow
    glBegin(GL_POLYGON);
    if(f)
        glColor3f(1.0, 1.0, 1.0);          /// Daytime snow (pure white)
    else
        glColor3ub(172, 174, 176);         /// Nighttime snow (light gray with dim lighting)
    glVertex2i(290, 150);
    glVertex2i(310, 175);
    glVertex2i(330, 150);
    glVertex2i(325, 140);
    glVertex2i(310, 150);
    glVertex2i(300, 140);
    glEnd();
}
/// Tilla Structure
void tillaModel1(){
    /// Tilla Color (Grass green or dark green for a natural tilla)
    glBegin(GL_POLYGON);
        if(f)
            glColor3f(0.1, 1.0, 0.0);         /// Daytime bright green for lush vegetation
        else
            glColor3ub(15, 59, 11);           /// Nighttime dark green, resembling a more shadowed appearance
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
/// Tilla Model 2 - Structure
void tillaModel2(){
                        /// Tilla Color (Grass green or dark green for a natural tilla)
    if(f)
        glColor3f(0.1, 1.0, 0.0);            /// Daytime bright green for lush vegetation
    else
        glColor3ub(15, 59, 11);              /// Nighttime dark green, resembling a more shadowed appearance
    glPushMatrix();
    /// Circle placements to form the tilla's shape
    circle(430, 90, 30);                      /// Left circles
    circle(420, 87, 30);
    circle(410, 80, 30);
    circle(400, 80, 30);
    circle(390, 70, 30);                      /// Bottom left of the tilla
    circle(445, 80, 30);                      /// Right side circles
    circle(455, 75, 30);
    circle(465, 70, 30);
    circle(470, 65, 30);
    circle(480, 60, 30);                      /// Top right of the tilla
    circle(485, 55, 20);                      /// Small circle at the top, representing the tip of the tilla
    glPopMatrix();
}

/// House Structure
void house(){
    /// House Roof Structure
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.2, 0.0);                /// A rich, natural reddish-brown for the roof (earthy tone)
    glVertex2i(285, 105);
    glVertex2i(285, 130);
    glVertex2i(380, 115);
    glVertex2i(380, 105);
    glEnd();
    /// House Roof Shadow Structure
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.1, 0.0);                /// A darker shadow color to add depth to the roof
    glVertex2i(285, 105);
    glVertex2i(285, 120);
    glVertex2i(380, 105);
    glVertex2i(380, 105);
    glEnd();
    /// House Fence
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.7, 0.5);                 /// Light wood color (earthy beige) for the fence
    glVertex2i(290, 70);
    glVertex2i(290, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);
    glEnd();
    /// House Fence Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.6, 0.4);                 /// A slightly darker shade of wood for the shadow
    glVertex2i(310, 70);
    glVertex2i(350, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);
    glEnd();
    /// House Door
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.1);                  /// Dark brown color for the wooden door
    glVertex2i(330, 70);
    glVertex2i(330, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 70);
    glEnd();
    /// House Window 1, 2, 3
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);                  /// Dark gray for the window frames (wood or metal-like)
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2i(312, 75);
    glVertex2i(312, 90);
    glVertex2i(327, 90);
    glVertex2i(327, 75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);
    glEnd();
    /// House Small Roof
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.2, 0.1);                /// A rich, slightly darker red for the smaller roof
    glVertex2i(250, 90);
    glVertex2i(257, 104);
    glVertex2i(290, 104);
    glVertex2i(290, 90);
    glEnd();

    /// House Small Fence
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.7, 0.5);               /// Matching light wood color as the larger fence
    glVertex2i(255, 70);
    glVertex2i(255, 90);
    glVertex2i(290, 90);
    glVertex2i(290, 70);
    glEnd();

    /// House Small Door
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.2, 0.1);               /// Darker brown for the small door, matching the larger door
    glVertex2i(260, 70);
    glVertex2i(260, 80);
    glVertex2i(285, 80);
    glVertex2i(285, 70);
    glEnd();
}
/// House 2 structure
void house2(){
    /// body
    glTranslatef(50, 100, 0);
    glColor3ub(150, 135, 96);          /// Earthy beige color for the house body (wooden or stone look)
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(100, 49);
    glVertex2i(0, 49);
    glEnd();
    /// roof
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);          /// Dark brown for the roof (wooden or terracotta look)
    glVertex2i(0, 50);
    glVertex2i(105, 50);
    glVertex2i(105, 60);
    glVertex2i(0, 67);
    glEnd();
    /// window 1
    glBegin(GL_POLYGON);
    glColor3ub(98, 98, 112);           /// Grayish dark for window frames (metal or wood)
    glVertex2i(15, 7);
    glVertex2i(35, 7);
    glVertex2i(35, 25);
    glVertex2i(15, 25);
    glEnd();
    /// window 2
    glBegin(GL_POLYGON);
    glColor3ub(98, 98, 112);           /// Matching grayish dark window frames
    glVertex2i(78, 7);
    glVertex2i(95, 7);
    glVertex2i(95, 25);
    glVertex2i(78, 25);
    glEnd();
    /// door
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);           /// Dark brown color for the door (wooden)
    glVertex2i(42, 0);
    glVertex2i(68, 0);
    glVertex2i(68, 33);
    glVertex2i(42, 33);
    glEnd();
    /// extra design (side)
    glBegin(GL_POLYGON);
    glColor3ub(202, 176, 130);         /// Light tan for the side design (stone or brick)
    glVertex2i(-20, 0);
    glVertex2i(0, 0);
    glVertex2i(0, 70);
    glVertex2i(-20, 70);
    glEnd();
    /// extra design (roof)
    glBegin(GL_POLYGON);
    glColor3ub(47, 38, 224);            /// Blue (could be used for a decorative roof design)
    glVertex2i(-20, 70);
    glVertex2i(0, 70);
    glVertex2i(-5, 80);
    glVertex2i(-25, 80);
    glEnd();
    /// extra design (side)
    glBegin(GL_POLYGON);
    glColor3ub(202, 176, 130);          /// Matching the side design with light tan
    glVertex2i(-25, 10);
    glVertex2i(-20, 0);
    glVertex2i(-20, 70);
    glVertex2i(-25, 80);
    glEnd();
}

void field(){
    /// Field (bright green color for healthy grass)
    glBegin(GL_POLYGON);
        if(f)
            glColor3f(0.0, 0.5, 0.0);        /// Darker green for bright field (realistic grass)
        else
            glColor3ub(34, 139, 34);         /// Regular green for field
        glVertex2i(0, 200);
        glVertex2i(0, 220);
        glVertex2i(1000, 220);
        glVertex2i(1000, 200);
    glEnd();

    /// Field Shadow (darker shade for the shadow effect)
    glBegin(GL_POLYGON);
        if(f)
            glColor3f(0.0, 0.3, 0.0);        /// Darker green for shadow under the field
        else
            glColor3ub(10, 40, 10);          /// Darker shadow for realism
        glVertex2i(0, 180);
        glVertex2i(1000, 180);
        glVertex2i(1000, 200);
        glVertex2i(0, 200);
    glEnd();
}
///Tree Model
void treeModel1(){
    if(f)
        glColor3ub(0, 173, 36);
    else
        glColor3ub(17, 102, 30);
    circle(110,110,15);
    circle(110,100,15);
    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(109,70);
    glVertex2i(109,90);
    glVertex2i(111,90);
    glVertex2i(111,70);
    glEnd();
}

void treeModel2(){
    if(f)
        glColor3ub(0,173,36);
    else
        glColor3ub(17,102,30);
    circle(130,130,5);
    circle(125,126,5);
    circle(135,126,5);
    circle(130,125,5);

    glColor3ub(2,41,10);
    glBegin(GL_POLYGON);
        glVertex2i(129,110);
        glVertex2i(129,124);
        glVertex2i(131,124);
        glVertex2i(131,110);
    glEnd();
}

void treeModel3(){
    if(f)
        glColor3ub(0,173,36);
    else
        glColor3ub(17,102,30);
    glBegin(GL_POLYGON);
        glVertex2i(125,123);
        glVertex2i(133,145);
        glVertex2i(141,123);
    glEnd();

    glColor3ub(2,41,10);
    glBegin(GL_POLYGON);
        glVertex2i(132,110);
        glVertex2i(132,124);
        glVertex2i(134,124);
        glVertex2i(134,110);
    glEnd();
}

void Stand_Model(){
    glColor3f(0.38,0.41,0.36);
    glBegin(GL_POLYGON);
        glVertex2i(375, 100);
        glVertex2i(380, 100);
        glVertex2i(380, 200);
        glVertex2i(375, 200);
    glEnd();

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
       glVertex2i(380, 197);
       glVertex2i(403, 197);
       glVertex2i(403, 200);
       glVertex2i(380, 200);
    glEnd();

    glColor3f(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2i(392, 193);
        glVertex2i(403, 193);
        glVertex2i(403, 197);
        glVertex2i(392, 197);
    glEnd();
}

void pole(){
    glColor3f(0.38,0.41,0.36);
    glPushMatrix();
    Stand_Model();
    glPopMatrix();
}

///Windmill stand structure
void Windmill_Stand_Model(){
    glColor3f(0.38,0.41,0.36);
    glBegin(GL_POLYGON);
        glVertex2i(375, 100);
        glVertex2i(380, 240);
        glVertex2i(384, 240);
        glVertex2i(390, 100);
    glEnd();
}
///Windmill blade  Structure
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
/// Boat Structure
void boat1() {
    glTranslatef(50, 100, 0);
    /// Boat Base (Wooden or dark brown color for the hull)
    glColor3ub(139, 69, 19);              /// A rich wood color (brown)
    glBegin(GL_POLYGON);
        glVertex2i(20, 0);
        glVertex2i(70, 0);
        glVertex2i(90, 20);
        glVertex2i(0, 20);
    glEnd();
    /// Boat Sail (Bright red or orange for a bold look)
    glColor3ub(255, 69, 0);              /// A rich red-orange color (bold, eye-catching)
    glBegin(GL_TRIANGLES);
        glVertex2i(20, 20);
        glVertex2i(45, 20);
        glVertex2i(45, 40);
        glVertex2i(47, 20);
        glVertex2i(72, 20);
        glVertex2i(47, 38);
    glEnd();
}
///Car Structure
void car1(){
    glTranslatef(50,100,0);
    glColor3ub(0,51,102);           /// A deep,rich blue (luxurious, high-end car color)
    glBegin(GL_POLYGON);            /// Body of the car
        glVertex2i(20,0);
        glVertex2i(115,0);
        glVertex2i(100,20);
        glVertex2i(85,20);
        glVertex2i(75,35);
        glVertex2i(50,35);
        glVertex2i(40,20);
        glVertex2i(30,20);
        glVertex2i(20,0);
    glEnd();

    glColor3ub(255,255,255);       /// Windows of the car
    glBegin(GL_POLYGON);
        glVertex2i(52,22);
        glVertex2i(61,22);
        glVertex2i(61,33);
        glVertex2i(52,33);
        glVertex2i(43,22);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2i(63,22);
        glVertex2i(80,22);
        glVertex2i(73,33);
        glVertex2i(63,33);
    glEnd();

    /// Tires
    glColor3ub(0, 0, 0);               /// Black tires to give a realistic look
    circle(40, 0, 7);                  /// Front tire
    circle(90, 0, 7);                  /// Rear tire
}

void car2(){
    glTranslatef(50,100,0);
    glColor3ub(128,0,0);               /// Deep red or burgundy
    glBegin(GL_POLYGON);
        glVertex2i(20,0);
        glVertex2i(115,0);
        glVertex2i(113,20);
        glVertex2i(80,20);
        glVertex2i(80,35);
        glVertex2i(65,35);
        glVertex2i(68,20);
        glVertex2i(35,20);
        glVertex2i(20,0);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2i(68,22);
        glVertex2i(76,22);
        glVertex2i(76,33);
        glVertex2i(67,33);
        glVertex2i(53,22);
    glEnd();

    circle(40,0,7);
    circle(95,0,7);
}

/// Windmill Structure
void Windmill(){
    ///Windmill Stand
    glColor3f(0.56, 0.38, 0.24);          /// Color for wood or metallic stand (brownish)
    glPushMatrix();
    Windmill_Stand_Model();               /// Draw the stand
    glPopMatrix();
    ///Windmill Motor
    if(f)
        glColor3f(0.20, 0.20, 0.20);      /// Dark metallic color (dark gray/charcoal)
    else
        glColor3ub(105, 105, 105);        /// Light metallic gray for motor
    circle(380,250,10);                   /// Draw the motor as a circle

    ///Windmill Rotary Blades
    if(f)
        glColor3f(0.11, 0.23, 0.36);      /// windmill blades color (white)
    else
        glColor3ub(107, 130, 199);        /// Light gray for blades during the night
    glPushMatrix();
    glTranslatef(380,251,0);              /// Position the blades
    Windmill_Blade();
    glPopMatrix();
}

///`Right Side Big Hill 1
void rightBigHill1(){
    glPushMatrix();
    glTranslatef(600,150,0);
    if(f) {
        glColor3ub(34, 139, 34);  /// Daytime hill (green)
    } else {
        glColor3ub(139, 69, 19);  /// Nighttime hill (brown)
    }
    hill_big();
    glPopMatrix();
}

///Right Side- Big Hill 2
void rightBigHill2(){
    glPushMatrix();
    if(f) {
        glColor3ub(34, 139, 34);  /// Daytime hill (green)
    } else {
        glColor3ub(139, 69, 19);  /// Nighttime hill (brown)
    }
    glTranslatef(550,130,0);
    hill_big();
    glPopMatrix();
}

///Left Side- Small Hill
void leftSmallHill(){
    glPushMatrix();
    glTranslatef(0,120,0);
    if(f) {
        glColor3ub(34, 139, 34);  /// Daytime hill (green)
    } else {
        glColor3ub(139, 69, 19);  /// Nighttime hill (brown)
    }
    hill_small();
    glPopMatrix();
}

///Right Side-House
void rightHouse(){
    glPushMatrix();
    glTranslatef(400,150,0);
    house();
    glPopMatrix();
}

///Left Side house
void leftHouse(){
    glPushMatrix();
    glTranslatef(420,120,0);
    house2();
    glPopMatrix();
}

///Right Side- Tilla
void rightTillaL(){
    glPushMatrix();
    glTranslatef(400,150,0);
    tillaModel1();
    glPopMatrix();
}

///Left Side- Tilla
void leftTillaL(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel1();
    glPopMatrix();
}

///Right Side- Tilla
void rightTillaR(){
    glPushMatrix();
    glTranslatef(500,150,0);
    tillaModel2();
    glPopMatrix();
}

///Right Side- Wind Mill
void rightWindmMill(){
    glPushMatrix();
    glTranslatef(530,150,0);
    Windmill();
    glPopMatrix();
}

///Left Side- Wind Mill
void leftWindMill(){
    glPushMatrix();
    glTranslatef(0,150,0);
    Windmill();
    glPopMatrix();
}

void pole1(){
    glPushMatrix();
    glTranslatef(30,120,0);
    pole();
    glPopMatrix();
}

void pole2(){
    glPushMatrix();
    glTranslatef(-130,120,0);
    pole();
    glPopMatrix();
}

void pole3(){
    glPushMatrix();
    glTranslatef(-300,120,0);
    pole();
    glPopMatrix();
}

void pole4(){
    glPushMatrix();
    glTranslatef(230,120,0);
    pole();
    glPopMatrix();
}

void pole5(){
    glPushMatrix();
    glTranslatef(480,120,0);
    pole();
    glPopMatrix();
}

///Left Side- Big Hill
void leftHillBig(){
    glPushMatrix();
    glTranslatef(0,130,0);
    if(f) {
        glColor3ub(34, 139, 34);  /// Daytime hill (green)
    } else {
        glColor3ub(139, 69, 19);  /// Nighttime hill (brown)
    }
    hill_big();
    glPopMatrix();
}

///Left Side Tilla
void leftTillaL1(){
    glPushMatrix();
    glTranslatef(-140,150,0);
    tillaModel1();
    glPopMatrix();
}

///Left Side Tilla
void leftTillaR(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel2();
    glPopMatrix();
}

///Boat 2
void carB(){
    glPushMatrix();
    glTranslatef(pos2,42,0);
    car1();
    glPopMatrix();
}

///Boat 3
void boatC(){
    glPushMatrix();
    glTranslatef(pos3,-70,0);
    boat1();
    glPopMatrix();
}
void carA(){
    glPushMatrix();
    glTranslatef(pos1,-11,0);
    car2();
    glPopMatrix();
}

/// Tree 1 - Draws the first tree in the scene
void tree1(){
    glPushMatrix();            /// Save the current transformation matrix
    glTranslatef(0,188,0);     /// Translate the tree to the desired position (X=0, Y=188, Z=0)
    treeModel1();              /// Call the treeModel 1 function to draw the tree structure
    glPopMatrix();             /// Restore the previous transformation matrix
}
///tree 2
void tree2(){
    glPushMatrix();
    glTranslatef(-60,146,0);
    treeModel2();
    glPopMatrix();
}
///tree 3
void tree3(){
    glPushMatrix();
    glTranslatef(-110,130,0);
    treeModel3();
    glPopMatrix();
}
///tree 4
void tree4(){
    glPushMatrix();
    glTranslatef(300,160,0);
    treeModel2();
    glPopMatrix();
}
///tree 5
void tree5(){
    glPushMatrix();
    glTranslatef(530,150,0);
    treeModel1();
    glPopMatrix();
}
///tree 6
void tree6(){
    glPushMatrix();
    glTranslatef(455,142,0);
    treeModel3();
    glPopMatrix();
}
///tree 7
void tree7(){
    glPushMatrix();
    glTranslatef(200,110,0);
    treeModel2();
    glPopMatrix();
}

///Sky
void sky(){
    glPushMatrix();
    if(f)
        glColor3ub(135, 206, 250);
    else
        glColor3ub(4, 11, 51);
    glBegin(GL_POLYGON);
       glVertex2i(0, 250);          /// Bottom-left corner
       glVertex2i(1000, 250);       /// Bottom-right corner
       glVertex2i(1000, 500);       /// Top-right corner
       glVertex2i(0, 500);          /// Top-left corner
    glEnd();
    glPopMatrix();                  /// Restore the previous transformation matrix
}
///Water
void water(){
    if (f)
        glColor3ub(28, 163, 236);   /// daytime water color (ocean blue)
    else
        glColor3ub(5, 31, 64);      /// nighttime water color (deep dark blue)
    glBegin(GL_POLYGON);
        glVertex2i(0,0);
        glVertex2i(1000,0);
        glVertex2i(1000,250);
        glVertex2i(0,250);
    glEnd();
    glPopMatrix();
}
///Sun
void sun(){
    if (f) {                             /// Only draw the sun if it's daytime
        glPushMatrix();                  /// Save the current transformation matrix
        glColor3ub(255, 204, 0);         /// sun color (bright golden yellow)
        glTranslatef(sun_x, sun_y, 0.0); /// Move the sun to its position
        circle(0, 0, 30);                /// Draw the sun as a circle with radius 30
        glPopMatrix();                   /// Restore the previous transformation matrix
    }
}
///Moon
void moon() {
    if (!f) {                            /// Only draw the moon if it's nighttime
        glPushMatrix();                  /// Save the current transformation state
        glColor3ub(245, 245, 220);       /// Realistic moon color (soft pale yellowish-white)
        circle(620, 360, 30);            /// Draw the main moon body
        glColor3ub(4, 11, 51);           /// night sky color (used for crescent effect)
        circle(630, 380, 30);            /// Slightly offset circle to create a crescent moon effect
        glPopMatrix();                   /// Restore the previous transformation state
    }
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
/// Cloud 1
void cloud1() {
    if (f) {                         /// Only draw the cloud if it's daytime
        glPushMatrix();              /// Save the current transformation state
        glTranslatef(cpos1, 170, 0); /// Move the cloud to its position
        glColor3ub(255, 255, 255);   /// cloud color (white, representing the fluffy white clouds)
        cloudModel1();               /// Call the function to draw the cloud model
        glPopMatrix();               /// Restore the previous transformation state
    }
}
/// Cloud 2
void cloud2() {
    if (f) {
        glPushMatrix();
        glTranslatef(cpos2, 270, 0);
        glColor3ub(255, 255, 255);   /// cloud color (white)
        cloudModel2();
        glPopMatrix();
    }
}
/// Cloud 3
void cloud3() {
    if (f) {
        glPushMatrix();
        glTranslatef(cpos3, 200, 0);
        glColor3ub(255, 255, 255);
        cloudModel3();
        glPopMatrix();
    }
}
/// Cloud 4
void cloud4() {
    glPushMatrix();
    glTranslatef(cpos4, 250, 0);
    glColor3ub(255, 255, 255);
    cloudModel2();
    glPopMatrix();
}
/// Cloud 5
void cloud5() {
    glPushMatrix();
    glTranslatef(cpos5, 220, 0);
    glColor3ub(255, 255, 255);
    cloudModel1();
    glPopMatrix();
}
/// Airplane Design
void airPlane(){
    glPushMatrix();
    glTranslatef(plane_x,370,0);  /// Translate the airplane to the specified position

    /// Body of the airplane - a metallic grayish color for realism
    glColor3ub(169, 169, 169);  /// A realistic metallic gray for the airplane body
    glBegin(GL_POLYGON);
        glVertex2i(100,100);
        glVertex2i(135,100);
        glVertex2i(135,112);
        glVertex2i(100,112);
    glEnd();

    /// Windows - white color with a slight blue tint for realistic airplane windows
    glColor3ub(200, 220, 255);  /// Light blue for windows
    glBegin(GL_POLYGON);
        glVertex2i(107,104);
        glVertex2i(115,104);
        glVertex2i(115,110);
        glVertex2i(107,110);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(122,104);
        glVertex2i(130,104);
        glVertex2i(130,110);
        glVertex2i(122,110);
    glEnd();

    /// Head of the airplane - a brighter red color to represent the cockpit area
    glColor3ub(255, 69, 0);  /// A vivid red for the cockpit/airplane head
    glBegin(GL_POLYGON);
        glVertex2i(135,100);
        glVertex2i(155,102);
        glVertex2i(135,112);
    glEnd();

    /// Propeller (Pakha) - a standard color for airplane propellers (dark gray or black)
    glColor3ub(50, 50, 50);  /// Dark gray for the propeller
    glBegin(GL_POLYGON);
        glVertex2i(100,112);
        glVertex2i(110,112);
        glVertex2i(103,120);
        glVertex2i(100,120);
    glEnd();
    glPopMatrix();
}

void road(){
    /// Road Body - Asphalt Color
    glBegin(GL_POLYGON);
    glColor3ub(50, 50, 50);  /// Dark gray (asphalt) color for the road
    glVertex2i(0, 80);
    glVertex2i(0, 180);
    glVertex2i(1000, 80);
    glVertex2i(1000, 180);
    glVertex2i(0, 180);
    glEnd();
}

/// Road Strips - Dashed Lines on Road
void roadstrip(){
    glColor3ub(255, 255, 255);              /// White color for road markings
    for (int x = 30; x <= 930; x += 90) {   /// Adjust spacing between stripes
        glBegin(GL_POLYGON);
        glVertex2i(x, 135);
        glVertex2i(x, 125);
        glVertex2i(x + 50, 135);
        glVertex2i(x + 50, 125);
        glVertex2i(x, 125);
        glEnd();
    }
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

	sky();
	water();
	star();
	sun();
    moon();
    road();
    roadstrip();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    cloud5();
    airPlane();
    rightTillaL();
    rightWindmMill();
    rightBigHill1();
    rightBigHill2();
    rightTillaR();
    rightHouse();
    leftTillaL1();
    leftHillBig();
    leftSmallHill();
    leftWindMill();
    leftTillaR();
    leftHouse();
    pole1();
    pole2();
    pole3();
    pole4();
    pole5();
    field();
    carB();
    boatC();
    carA();
    tree1();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    tree7();
	glFlush();
}

void init(void){
	glClearColor(0.65, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void update(int value) {
    /// Boat animation logic
    if(pos1 < 20) pos1 = 1000;    /// Wrap boat 1 to right side  (Reset position when left edge reached)
    if(pos2 > 980) pos2 = -100;   /// Wrap boat 2 to left side   (Reset position when right edge reached)
    if(pos3 < 10) pos3 = 1000;    /// Wrap boat 3 to right side   (Reset position when left edge reached)

    /// Update boat positions with individual speeds
    pos1 -= speed1;                /// Move boat 1 left
    pos2 += speed2;                /// Move boat 2 right
    pos3 -= speed3;                /// Move boat 3 left

    /// Cloud animation logic
    if(cpos1 > 750) cpos1 = -320;   /// Cloud 1: Reset when too far right
    if(cpos2 < -350) cpos2 = 650;   /// Cloud 2: Reset when too far left
    if(cpos3 > 750) cpos3 = -320;   /// Cloud 3: Reset when too far right
    if(cpos4 > 750) cpos4 = -320;   /// Cloud 4: Reset when too far right
    if(cpos5 < -350) cpos5 = 650;   /// Cloud 5: Reset when too far left

    /// Update cloud positions (alternating directions)
    cpos1 += sp1;                   /// Move cloud 1 right
    cpos2 -= sp1;                   /// Move cloud 2 left
    cpos3 += sp1;                   /// Move cloud 3 right
    cpos4 += sp1;                   /// Move cloud 4 right
    cpos5 -= sp1;                   /// Move cloud 5 left

    /// Sun/Moon animation logic
    if(sun_y > 480) {               /// When sun reaches top (sunset)
        sun_x = 650;                /// Reset to moon position X
        sun_y = 290;                /// Reset to moon position Y
        f = 0;                      /// Switch to night mode
    }
    sun_x -= sp_x;                  /// Update celestial body X position
    sun_y += sp_y;                  /// Update celestial body Y position

    /// Airplane animation
    if(plane_x > 1000) {            /// When plane exits right
        plane_x = -100;             /// Reset to left
    }
    plane_x += plane_speed;         /// Move plane right

    /// Schedule next update (100ms delay) and refresh screen
    glutTimerFunc(100, update, 0);  /// Recursive timer call
    glutPostRedisplay();            /// Trigger redraw
}

void windMill_start(){
    spin+=0.1;                     ///Increment rotation angle---->>> 0.1 degree per frame rotation
    glutPostRedisplay();           /// Request screen refresh to show updated rotation
}

void handleMouse(int key, int state, int x, int y){
    switch (key){
        case GLUT_LEFT_BUTTON:      ///Click left mouse button → Windmill blades start spinning
            if (state == GLUT_DOWN){
                glutIdleFunc(windMill_start);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:      ///Click right mouse button → Freezes all motion
            if (state == GLUT_DOWN){
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}

void handleKeypress(unsigned char key, int x, int y){
	switch (key){
        case 'd':   ///Press d for day mode
            f=1;
            break;
        case 'n':  ///Press n for night mode
            f=0;
            break;
        glutPostRedisplay();
	}
}

void credit(){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Computer Graphics-  Project"<<endl;
    cout<<"Ahad Hosen Akash"<<endl;
    cout<<"ID: 21111121"<<endl;
    cout<<"------------------------------------------------------"<<endl;
}

int main(int argc, char** argv){
    credit();
    PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);                 /// Music Background   SND_ASYNC = play in background

    glutInit(&argc, argv);                                         /// Initialize GLUT with command line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                   /// Set display mode: single buffer & RGB color
    glutInitWindowPosition(0, 0);                                  ///Configure window position and size (Top-left screen position)
    glutInitWindowSize(1900, 1900);                                /// Full HD+ window size
    glutCreateWindow("Computer Graphics Project- Smart Village");  /// Create window with title
    init();                                                        /// Initialize OpenGL parameters
    glutDisplayFunc(display);                                      /// Main rendering function
    glutKeyboardFunc(handleKeypress);                              /// Keyboard input handler
    glutMouseFunc(handleMouse);                                    /// Mouse input handler
    /// Set timer for periodic updates (1000ms = 1 second)
    glutTimerFunc(1000, update, 0);                                /// Calls update() every second
    glutMainLoop();                                                /// Enters GLUT's infinite processing loop
    return 0;
}
