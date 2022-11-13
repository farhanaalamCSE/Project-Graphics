#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#define PI 3.1416

bool flagScale=false;
double sun_running=0;
double boat_running=0;
double cloud_running=0;
double cloud1_running=0;





void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 20;


    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void sun()
{

    glPushMatrix();
    glColor3f(128,128,0);

    drawFilledCircle(10,16,1.5);

    glPopMatrix();


}

void house()
{


    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.19, 0.11, 0.28);
    glVertex2f(6,0);
    glVertex2f(6,6);
    glVertex2f(9,6);
    glVertex2f(9,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.07, 0.43);
    glVertex2f(5,6);
    glVertex2f(7.5,9);
    glVertex2f(11,9);
    glVertex2f(9,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.81, 0.79, 0.85);
    glVertex2f(7,0);
    glVertex2f(7,4);
    glVertex2f(8,4);
    glVertex2f(8,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.47, 0.07, 0.9);//Violet
    glVertex2f(9,0);
    glVertex2f(9,6);
    glVertex2f(11,9);
    glVertex2f(13,6);
    glVertex2f(13,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.81, 0.79, 0.85);
    glVertex2f(10,3);
    glVertex2f(10,5);
    glVertex2f(12,5);
    glVertex2f(12,3);
    glEnd();
    glPopMatrix();





}

void tree()
{

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.23, 0.22, 0.12);
    glVertex2f(16,0);
    glVertex2f(16,6);
    glVertex2f(17,6);
    glVertex2f(17,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);

    glColor3f(0.28, 0.83, 0.15);
    glVertex2f(14,6);
    glVertex2f(16.5,9);
    glVertex2f(19,6);

    glEnd();
    glPopMatrix();




}


void cloud ()
{

    glPushMatrix();
    glColor3f(1,1,1);
    drawFilledCircle(-6,6,2);
    drawFilledCircle(-4,6,1.4);
    drawFilledCircle(-8,6,1.2);
    glPopMatrix();


}

void cloud1 ()
{

    glPushMatrix();
    glColor3f(1,1,1);
    drawFilledCircle(4,6,1.8);
    drawFilledCircle(2,6,1.4);
    drawFilledCircle(6,6,1.2);
    glPopMatrix();

}


void river ()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.49, 0.91);//cyan
    glVertex2f(-20,-5);
    glVertex2f(-20,-20);
    glVertex2f(20,-20);
    glVertex2f(20,-5);
    glEnd();
    glPopMatrix();

}

void road ()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.38, 0.31, 0.3);

    glVertex2f(-20,3);
    glVertex2f(-20,-5);
    glVertex2f(20,-5);
    glVertex2f(20,0);
    glEnd();
    glPopMatrix();

}

void boat()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.12, 0.11, 0.12);
    glVertex2f(0,2.2);
    glVertex2f(4,2.2);
    glVertex2f(5,4);

    glVertex2f(-1,4);


    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.81, 0.1, 0.72);
    glVertex2f(2,5);
    glVertex2f(4,5);

    glVertex2f(4,7);
    glVertex2f(2,7);


    glEnd();
glPopMatrix();

glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex2f(2,4);
    glVertex2f(2,7);

    glEnd();
glPopMatrix();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

    case 'M':
        flagScale=true;
        break;
    case 'm':
        flagScale=false;
        break;



    case 20:
        exit(1);
    }
    glutPostRedisplay();
}
void animate()
{

    //SUN

    if (flagScale == true)
    {
        sun_running+= 0.005;
        if(sun_running > 11)
            sun_running = 0.005;
    }
    if (flagScale == false)
    {
        sun_running = 1;

    }

    //Boat

    if (flagScale == true)
    {
        boat_running+= 0.005;
        if(boat_running > 24)
            boat_running = 0.005;
    }
    if (flagScale == false)
    {
        boat_running = 1;

    }

    //Cloud

    if (flagScale == true)
    {
        cloud_running+= 0.005;
        if(cloud_running > 11)
            cloud_running = 0.005;
    }
    if (flagScale == false)
    {
        cloud_running = 1;

    }


    if (flagScale == true)
    {
        cloud1_running+= 0.005;
        if(cloud1_running > 11)
            cloud1_running = 0.005;
    }
    if (flagScale == false)
    {
        cloud1_running = 1;

    }





    glutPostRedisplay();
}



void init()
{


    glClearColor(0.0,0.80,1.0,1.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Road
    road();

    //House
    glPushMatrix();
    glTranslatef(2.5,0,0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.5,0,0);
    house();
    glPopMatrix();

    //Tree

    glPushMatrix();
    glTranslatef(-30.5,0,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.7,0,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-33.5,0,0);
    tree();
    glPopMatrix();

   //Cloud
    glPushMatrix();
    glTranslatef(cloud_running,10,0);
    cloud();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(cloud1_running,10,0);
    cloud1();
    glPopMatrix();



    //river

     river();

     //boat

    glPushMatrix();
    glTranslatef(boat_running,-17,0);
    boat();
    glPopMatrix();

    //sun

    glPushMatrix();
    glTranslatef(sun_running,0,0);
    sun();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);

    glutInitWindowSize(500,500);
    glutCreateWindow("DIBA");


    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);
    glutDisplayFunc(display);
    init();

    glutMainLoop();

    return 0;
}
