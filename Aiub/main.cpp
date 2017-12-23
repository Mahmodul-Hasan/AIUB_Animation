
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <iostream>
using namespace std;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = 0.0;

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1024, 0.0, 768.0);
}

void Full()
{
    glColor3ub(131,183,231);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1324,0,0);
    glVertex3i(1324,768,0);
    glVertex3i(-200,768,0);
}
//Road
void Road()
{
    glColor3ub(78,78,78);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1324,0,0);
    glVertex3i(1324,120,0);
    glVertex3i(-200,120,0);
    glEnd();
}
void TranslateRoadLine(int x,int y,int z)
{
    x-=50;
    if(x<=0)
    {
        x=1050;
    }
    glutPostRedisplay();
    Sleep(50);
}
//ROad Line
void RoadLine(int x,int y,int z)
{
    static float a=.0f;
    a+=.002f;
    if(a==49)
    {
        x=x-49;
    }
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(a,.0f,.0f);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+50,y,z);
    glVertex3i(x+50,y+10,z);
    glVertex3i(x,y+10,z);
    glEnd();

    glPopMatrix();
    glutPostRedisplay();
    //Sleep(50);
    //TranslateRoadLine(x,y,z);
}

void playGround()
{
    //Grass
    glColor3ub(42,95,17);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1324,120,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);
    glEnd();

    //Walkway
    glColor3ub(140,88,54);
    glBegin(GL_QUADS);
    glVertex3i(-200,250,0);
    glVertex3i(1324,250,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);

}
//Dynamic Tree Function
void Tree(int x,int y,int z)
{
    //Timber
    glColor3ub(90,70,60);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+7,y,z);
    glVertex3i(x+7,y+20,z);
    glVertex3i(x,y+20,z);
    glEnd();

    //Lower Leaf
    glColor3ub(14,120,14);
    glBegin(GL_TRIANGLES);
    glVertex3i(x-15,y+19,z);
    glVertex3i(x+22,y+19,z);
    glVertex3f(x+3.5,y+45,z);
    glEnd();

    //Upper Leaf
    glBegin(GL_TRIANGLES);
    glVertex3i(x-10,y+35,z);
    glVertex3i(x+17,y+35,z);
    glVertex3f(x+3.5,y+60,z);
    glEnd();
}
//Dynamic Windows Function
void Windows(int x,int y,int z)
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+60,y,z);
    glVertex3i(x+60,y+70,z);
    glVertex3i(x,y+70,z);
    glEnd();

    //Black
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(x+7,y+7,z);
    glVertex3i(x+27,y+7,z);
    glVertex3i(x+27,y+33,z);
    glVertex3i(x+7,y+33,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+33,y+7,z);
    glVertex3i(x+54,y+7,z);
    glVertex3i(x+54,y+33,z);
    glVertex3i(x+33,y+33,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+7,y+40,z);
    glVertex3i(x+27,y+40,z);
    glVertex3i(x+27,y+63,z);
    glVertex3i(x+7,y+63,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+33,y+40,z);
    glVertex3i(x+54,y+40,z);
    glVertex3i(x+54,y+63,z);
    glVertex3i(x+33,y+63,z);
    glEnd();
}
//Buildings
void FirstBuilding()
{
   int windowsXf=-220,windowsXl=556;

    //Left Building
    glColor3ub(56,46,47);
    glBegin(GL_QUADS);
    glVertex3i(-200,260,0);
    glVertex3i(396,260,0);
    glVertex3i(396,375,0);
    glVertex3i(-200,375,0);
    glEnd();

    //Right Building
    glBegin(GL_QUADS);
    glVertex3i(628,260,0);
    glVertex3i(1324,260,0);
    glVertex3i(1324,375,0);
    glVertex3i(628,375,0);
    glEnd();

    //Middle
    glColor3ub(48,49,54);
    glBegin(GL_QUADS);
    glVertex3i(396,260,0);
    glVertex3i(628,260,0);
    glVertex3i(628,400,0);
    glVertex3i(396,400,0);
    glEnd();

    //First 4 Windows
    for(int i=5;i>=0;i--)
    {
        windowsXf+=90;
        Windows(windowsXf,280,0);
    }
    //Last 4 Windows
    for(int i=6;i>=0;i--)
    {
        windowsXl+=90;
        Windows(windowsXl,280,0);
    }
}
//Cross For Tin Shade;
void Cross(int x,int y,int z)
{
    glColor3b(10,150,12);
    glBegin(GL_QUADS);

    glVertex3i(x,y,z);
    glVertex3i(x+2,y,z);
    glVertex3i(x+2,y+15,z);
    glVertex3i(x,y+15,z);
    glEnd();

}
//TinShade
void TinShade()
{
    glColor3ub(233,235,238);
    //Left One
    glBegin(GL_QUADS);
    glVertex3i(-200,375,0);
    glVertex3i(396,375,0);
    glVertex3i(396,390,0);
    glVertex3i(-200,390,0);
    glEnd();

    //Right One
    glBegin(GL_QUADS);
    glVertex3i(628,375,0);
    glVertex3i(1324,375,0);
    glVertex3i(1324,390,0);
    glVertex3i(628,390,0);
    glEnd();

    //Middle One
    glBegin(GL_QUADS);
    glVertex3i(386,400,0);
    glVertex3i(638,400,0);
    glVertex3i(638,420,0);
    glVertex3i(386,420,0);
    glEnd();
    //Green Top
    glColor3ub(42,85,6);
    glBegin(GL_QUADS);
    glVertex3i(-200,390,0);
    glVertex3i(396,390,0);
    glVertex3i(396,395,0);
    glVertex3i(-200,395,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(628,390,0);
    glVertex3i(1324,390,0);
    glVertex3i(1324,395,0);
    glVertex3i(628,395,0);
    glEnd();

    //Left Top Side
    glColor3ub(140,140,130);
    glBegin(GL_QUADS);
    glVertex3i(0,395,0);
    glVertex3i(125,395,0);
    glVertex3i(120,410,0);
    glVertex3i(0,410,0);
    glEnd();
    //Cross
    int CrossX=0;
    for(int i=15;i>0;i--)
    {
        Cross(CrossX,395,0);
        CrossX+=8;
    }

    glColor3b(10,150,12);
    glBegin(GL_QUADS);
    glVertex3i(0,400,0);
    glVertex3i(125,400,0);
    glVertex3i(122,402,0);
    glVertex3i(0,402,0);
    glEnd();
}

void Pillar(int x,int y,int z)
{
    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+3,y,z);
    glVertex3i(x+3,y+45,z);
    glVertex3i(x,y+45,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+15,y,z);
    glVertex3i(x+18,y,z);
    glVertex3i(x+18,y+40,z);
    glVertex3i(x+15,y+40,z);
    glEnd();
}

void FrontTop()
{
    int pillarX=0;
    //Back
    //glColor4ub(229,229,229,250);
    glColor3ub(147,154,174);
    glBegin(GL_QUADS);
    glVertex3i(3,395,0);
    glVertex3i(120,395,0);
    glVertex3i(120,440,0);
    glVertex3i(3,442,0);
    glEnd();

    glColor3ub(147,154,174);
    glBegin(GL_QUADS);
    glVertex3i(120,395,0);
    glVertex3i(220,395,0);
    glVertex3i(220,410,0);
    glVertex3i(120,410,0);
    glEnd();

    //Green Tin Shade
    glColor3ub(83,186,60);
    glBegin(GL_QUADS);
    glVertex3i(0,440,0);
    glVertex3i(200,440,0);
    glVertex3i(210,455,0);
    glVertex3i(10,455,0);
    glEnd();
    //Front Triangle
    glColor3ub(48,56,67);
    glBegin(GL_TRIANGLES);
    glVertex3i(190,435,0);
    glVertex3i(220,435,0);
    glVertex3i(210,455,0);
    glEnd();
    //Shadow
    glBegin(GL_QUADS);
    glVertex3i(0,436,0);
    glVertex3i(200,435,0);
    glVertex3i(210,440,0);
    glVertex3i(0,440,0);
    glEnd();
    //Pillar
    for(int i=6;i>=0;i--)
    {

        Pillar(pillarX,395,0);
        pillarX+=32;
    }

//    glBegin(GL_QUADS);
//    glVertex3i(208,395,0);
//    glVertex3i(211,395,0);
//    glVertex3i(211,454,0);
//    glVertex3i(208,454,0);
//    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(217,395,0);
    glVertex3i(220,395,0);
    glVertex3i(220,435,0);
    glVertex3i(217,435,0);
    glEnd();
}

//HEAD
//========
//Middle Top Corridor Functions
void VerticalLine(int x,int y,int z)
{
    for(int i=10;i>=0;i--)
    {
        glColor3ub(166,166,166);
        glBegin(GL_QUADS);
        glVertex3i(x,y,0);
        glVertex3i(x+2,y,0);
        glVertex3i(x+2,y+35,0);
        glVertex3i(x,y+35,0);
        glEnd();
        x+=10;
    }
}

void HorizontalLine(int x,int y,int z)
{
    for(int i=3;i>=0;i--)
    {
        glColor3ub(166,166,166);
        glBegin(GL_QUADS);
        glVertex3i(x,y,0);
        glVertex3i(x+105,y,0);
        glVertex3i(x+105,y+2,0);
        glVertex3i(x,y+2,0);
        glEnd();
        y+=10;
    }
}
//Middle top Corridor Main Function
void MiddleTop()
{
    //Top
    glColor3ub(205,205,205);
    glBegin(GL_QUADS);
    glVertex3i(300,430,0);
    glVertex3i(405,430,0);
    glVertex3i(405,440,0);
    glVertex3i(300,440,0);
    glEnd();

    //Pillar
    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(300,395,0);
    glVertex3i(303,395,0);
    glVertex3i(303,430,0);
    glVertex3i(300,430,0);
    glEnd();

    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(402,420,0);
    glVertex3i(405,420,0);
    glVertex3i(405,430,0);
    glVertex3i(402,430,0);
    glEnd();
    //Line
    VerticalLine(300,395,0);
    HorizontalLine(300,395,0);
    //Shadow
    glColor3ub(5,5,5);
    glBegin(GL_QUADS);
    glVertex3i(300,427,0);
    glVertex3i(405,427,0);
    glVertex3i(405,431,0);
    glVertex3i(300,431,0);
    glEnd();
}

void drawFilledCircle(GLfloat x, GLfloat y,GLfloat z, GLfloat radius){
	int i;
	int triangleAmount = 50; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1416;
    int color=137;
    int counter=0;
    glColor3ub(color,color,color);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y,z); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount)),z
			);
			if(counter<25)
            {
                color+=3;
                glColor3ub(color,color,color);
            }
            else
            {
                color-=3;
                glColor3ub(color,color,color);
            }
		}
	glEnd();
}






void reshape(int w,int h)
{
glViewport(0,0, (GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
//Main Display Function
void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int roadlineX=-4096;
    int treeXf=-104;
    int treeXl=528;
    glPushMatrix();
    glTranslatef(translate_x,translate_y,translate_z);
   //Full Body
    Full();

    //Road
    Road();
    //RoadLine
    for(int i=55;i>0;i--)
    {
        roadlineX+=100;
        RoadLine(roadlineX,55,0);
    }
    //Play Ground
    playGround();
    //Middle Top Corridor
    MiddleTop();
    drawFilledCircle(950.0f,500.0f,0.0f,170.0f);
    //Building
    FirstBuilding();

    //First 4 Tree
    for(int i=3;i>=0;i--)
    {
        treeXf+=120;
        Tree(treeXf,260,0);
    }
    //Last 4 Tree
    for(int i=3;i>=0;i--)
    {
        treeXl+=120;
        Tree(treeXl,260,0);
    }
    //Front top corridor
    FrontTop();

    //TinShade

    TinShade();
    glPopMatrix();
    glFlush();
glutSwapBuffers();
}


void SpecialKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:
            if(translate_x<200)
            {
                translate_x+=5;
                glutPostRedisplay();
            }
			break;

		case GLUT_KEY_RIGHT:
            if(translate_x>-300)
            {
                translate_x-=5;
                glutPostRedisplay();
            }
			break;
	}
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1024, 768);
glutInitWindowPosition (0, 0);
glutCreateWindow ("AIUB");
myInit();
glutDisplayFunc(myDisplay);
//glutReshapeFunc(reshape);
glutSpecialFunc(SpecialKeys);
glutMainLoop();
return 0;
}
