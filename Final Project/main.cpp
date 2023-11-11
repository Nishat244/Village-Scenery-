#include<windows.h>
#include <mmsystem.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static float cloud = -10;
static float cloud1 = -20;
static float cloud2 = -60;
static float cloud3 = -80;
static float cloud4 = -110;
static float cloud5 = -130;
static float birdmove = -5;

void delay(){
    for(int i=0;i<100000000;i++);
}
void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI= 2.0 * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<100;i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}

void birMove()
{   //left to right
    birdmove += 1;
    if(birdmove >100){
        birdmove = -5;
   }
    glutPostRedisplay();

}

void cloudMove()
{
    cloud1 += .7;
    if(cloud1 > 200){
        cloud1 = -20;
    }
    glutPostRedisplay();
    cloud2 += .5;
    if(cloud2 > 200){
        cloud2 = -60;
    }
    glutPostRedisplay();
    cloud3 += .5;
    if(cloud3 > 200){
        cloud3 = -80;
    }
    glutPostRedisplay();
    cloud4 += .4;
    if(cloud4 > 200){
        cloud4 = -110;
    }
    glutPostRedisplay();
    glutPostRedisplay();
    cloud5 += .5;
    if(cloud5 > 200){
        cloud4 = -130;
    }
    glutPostRedisplay();
}
static float apple1= 0;
static float apple2= 1;
static float apple3= 1;
static float apple4= 0;
static float apple5= 1;
static float apple6= 1;
void Apple()
{
    apple1 -= .5;
    if(apple1<-29){
        apple1=0;
    }
    apple2 -= .5;
    if(apple2<-30){
        apple2=0;
    }
    apple3 -= .5;
    if(apple3<-30){
        apple3=0;
    }
    apple4 -= .5;
    if(apple4<-30){
        apple4=0;
    }
    apple5 -= .3;
    if(apple5<-30){
        apple5=0;
    }
    apple6 -= .3;
    if(apple6<-30){
        apple6=0;
    }
    glutPostRedisplay();
}
void appleFall()
{
    glColor3ub(245,40,40);
    Apple();
    glPushMatrix();
        glTranslated(0, apple1, 0);
        circle(.5,1,11,68);
            glPopMatrix();
    glPushMatrix();
        glTranslated(0, apple2, 0);
        circle(.5,1,13,70);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, apple3, 0);
        circle(.5,1,19,70);
        //circle(.5,1,41,39);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0, apple4, 0);
        circle(.5,1,23,70);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, apple5, 0);
        circle(.5,1,24,66);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, apple6, 0);
        circle(.5,1,23,62);
    glPopMatrix();
}

static float orange1= 0;
static float orange2= 1;
static float orange3= 1;
static float orange4= 0;
static float orange5= 1;
static float orange6= 1;


void tree2(float x1, float y1)
{
    float x2 = x1+5,y2=y1, x3=x1+2.5,y3=y1+6;
    glColor3ub(25, 95, 25);
    glBegin(GL_TRIANGLES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2d(x1+2, y1);
        glVertex2d(x1, y1-5);
        glVertex2d(x2, y1-5);
        glVertex2d(x2-2, y1);

        glVertex2d(x1+2, y1-5);
        glVertex2d(x1, y1-10);
        glVertex2d(x2, y1-10);
        glVertex2d(x2-2, y1-5);
        glColor3ub(68, 43, 2);
        glVertex2d(x1+2, y1-10);
        glVertex2d(x1+1.5, y1-18);
        glVertex2d(x2-1.5, y1-18);
        glVertex2d(x2-2, y1-10);
    glEnd();
}

void house1(int x, int y)
{
    glColor3ub(160, 145, 185);
    glBegin(GL_TRIANGLES);
        glVertex2d(x+0.3, y);//2.60
        glVertex2d(x+2,y+4);//4,64
        glVertex2d(x+4,y-2);//6,58
    glEnd();

    glColor3f(1,0.7,.11);
    glBegin(GL_QUADS);
        //wall right
        glColor3ub(165, 157, 186);
        glVertex2f(x+3.5, y-7);//55,53
        glVertex2f(x+7.3, y-4.5);//9.3,55.5
        glVertex2f(x+7.3, y-1);//9.3,59
        glVertex2f(x+3.5, y-1.5);//5.5,58.5
        //door
        glColor3ub(32, 50, 130);
        glVertex2f(x+5.5,y-5.5);//7.5,54.5
        glVertex2f(x+6.25,y-5);//8.25,55
        glVertex2f(x+6.25,y-2.5);//8.25,57.5
        glVertex2f(x+5.5,y-2.5);//7.5,57.5

        //wall left
        glColor3ub(160, 145, 185);
        glVertex2f(x +0.3, y-5);//2.3,55
        glVertex2f(x + 3.5, y-7);//5.5,53
        glVertex2f(x + 3.5, y-1.5);//5.5,58.5
        glVertex2f(x+0.5, y);//2.5,60

        //window left
        glColor3ub(32, 50, 130);
        glVertex2f(x+1.5,y-3.5); //3.5,56.5
        glVertex2f(x+2.2,y-4);//4.2,56
        glVertex2f(x+2.2,y-1.7);//4.2,58.3
        glVertex2f(x+1.5,y-1.3);//3.5,58.7

        //right roof
        glColor3ub(32, 50, 130);
        glVertex2d(x+1.5,y+4.5);//4,64
        glVertex2d(x+5.5,y+5.5);//8,65
        glVertex2d(x+8,y-1);//10,59
        glVertex2d(x+3.5,y-2);//6,58
        glVertex2d(x+1.5,y+4.5);
        glVertex2d(x+2,y+4);
        glVertex2d(x+0.3,y);
        glVertex2d(x-0.5,y-0.2);
    glEnd();
}

void house2(int x, int y)
{
   glColor3ub(160, 145, 185);
    glBegin(GL_TRIANGLES);
        glVertex2d(x+0.3, y);//2.60
        glVertex2d(x+2,y+4);//4,64
        glVertex2d(x+4,y-2);//6,58
    glEnd();

    glColor3f(1,0.7,.11);
    glBegin(GL_QUADS);
        //wall right
        glColor3ub(165, 157, 186);
        glVertex2f(x+3.5, y-7);//55,53
        glVertex2f(x+7.3, y-4.5);//9.3,55.5
        glVertex2f(x+7.3, y-1);//9.3,59
        glVertex2f(x+3.5, y-1.5);//5.5,58.5
        //door
        glColor3ub(84, 51, 90);
        glVertex2f(x+5.5,y-5.5);//7.5,54.5
        glVertex2f(x+6.25,y-5);//8.25,55
        glVertex2f(x+6.25,y-2.5);//8.25,57.5
        glVertex2f(x+5.5,y-2.5);//7.5,57.5


        //wall left
        glColor3ub(160, 145, 185);
        glVertex2f(x +0.3, y-5);//2.3,55
        glVertex2f(x + 3.5, y-7);//5.5,53
        glVertex2f(x + 3.5, y-1.5);//5.5,58.5
        glVertex2f(x+0.5, y);//2.5,60

        //window left
        glColor3ub(84, 51, 90);
        glVertex2f(x+1.5,y-3.5); //3.5,56.5
        glVertex2f(x+2.2,y-4);//4.2,56
        glVertex2f(x+2.2,y-1.7);//4.2,58.3
        glVertex2f(x+1.5,y-1.3);//3.5,58.7

        //right roof
        glColor3ub(84, 51, 90);
        glVertex2d(x+1.5,y+4.5);//4,64
        glVertex2d(x+5.5,y+5.5);//8,65
        glVertex2d(x+8,y-1);//10,59
        glVertex2d(x+3.5,y-2);//6,58
        glVertex2d(x+1.5,y+4.5);
        glVertex2d(x+2,y+4);
        glVertex2d(x+0.3,y);
        glVertex2d(x-0.5,y-0.2);
    glEnd();
}

void bird(int x,int y)
{
    int i;
    const int PI=3.14159265358;
	GLfloat mm=x+5;
	GLfloat nn=y+0.2;
	GLfloat radiusmm =.5;
	int triangleAmount = 20;
	GLfloat twicePi = 2 * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(x+.2,y);
    glVertex2f(x+.5,y-1);
    glVertex2f(x+3.3,y-1.5);
    glVertex2f(x+3.5,y-2);
    glVertex2f(x+5,y-0.5);
    glVertex2f(x+6,y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(x+4.5,y);
    glVertex2f(x+2.5,y);
    glVertex2f(x+3.3,y+3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(x+4.5,y);
    glVertex2f(x+2.5,y);
    glVertex2f(x+2,y+2);
    glEnd();
}

void MovingBird()
{
    //bird left to right
    birMove();
    glPushMatrix();
    glTranslatef(birdmove+1,0,0);
    bird(6,75);
    glPopMatrix();

}

static float r1= 0;
static float r2= 10;
static float r3= 20;
static float r4= 30;
static float r5= 40;
static float r6= 50;
static float r7= 60;
static float r8= 70;
static float r9= 80;
static float r10= 90;
static float r11= 100;
static float r12= 110;

void rainfall()
{
    r1 -= 1;
    if(r1 < -100)
        r1 = 0;
    glutPostRedisplay();

    r2 -= 1;
    if(r2 < -100)
        r2 = 0;
    glutPostRedisplay();

    r3 -= 1;
    if(r3 < -100)
        r3 = 0;
    glutPostRedisplay();

    r4 -= 1;
    if(r4 < -100)
        r4 = 0;
    glutPostRedisplay();

    r5 -= 1;
    if(r5 < -100)
        r5 = 0;
    glutPostRedisplay();

    r6 -= 1;
    if(r6 < -100)
        r6 = 0;
    glutPostRedisplay();

    r7 -= 1;
    if(r7 < -100)
        r7 = 0;
    glutPostRedisplay();

    r8 -= 1;
    if(r8 < -100)
        r8 = 0;
    glutPostRedisplay();

    r9 -= 1;
    if(r9 < -100)
        r9 = 0;
    glutPostRedisplay();

    r10 -= 1;
    if(r10 < -100)
        r10 = 0;
    glutPostRedisplay();
    r11 -= 1;
    if(r11 < -100)
        r11 = 0;
    glutPostRedisplay();

    r12 -= 1;
    if(r12 < -100)
        r12 = 0;
    glutPostRedisplay();
}

void river()
{
    glColor3ub(100, 200, 255);

    circle(3,5,77.5,50);
    circle(3,5,78,42);
    circle(3,5,78.5,35);
    circle(3,5,79.5,27);
    circle(3,5,80,20);
    circle(3,5,80.5,14);
    circle(3,5,80.5,7);

    glBegin(GL_QUADS);
        glVertex2d(75, 55);
        glVertex2d(80, 2);
        glVertex2d(98.5, 2);
        glVertex2d(98.5, 55);

    glEnd();
}
void rightTriangle(float x, float y, float distance,float height)
{
    glBegin(GL_TRIANGLES);
        glVertex2d(x,y);
        glVertex2d(x+.5,y-distance);
        glVertex2d(x-height,(y+y-distance)/2);
    glEnd();
}

void leftTriangle(float x, float y, float distance,float height)
{
    glBegin(GL_TRIANGLES);
        glVertex2d(x,y);
        glVertex2d(x,y-distance);
        glVertex2d(x+height,(y+y-distance)/2);
    glEnd();
}
void road()
{
    glColor3f(1, 1, 1);
    glColor3ub(190,190,190);
    glBegin(GL_QUADS);
        glVertex2d(75, 2);
        glVertex2d(70, 60);
        glVertex2d(60, 60);
        glVertex2d(60, 2);

    glEnd();
    //railpath right side footpath
    glBegin(GL_POLYGON);
     glColor3ub(66, 195, 76);
        glVertex2d(70, 60);
        glVertex2d(75, 55);
        glVertex2d(80, 2);
        glVertex2d(75, 2);
    glEnd();

    //triangles
    glColor3ub(22, 58, 21);
    rightTriangle(70,60,2,3);
    rightTriangle(70.3,58,2,3);
    rightTriangle(70.6,56,2,3);
    rightTriangle(70.9,54,2,3);
    rightTriangle(71,52,2,2.5);
    rightTriangle(71.2,50,2,2.5);
    rightTriangle(71.4,48,2,2.3);
    float x =71.6, y=46.0;
    int i;
    for(i=1; i<23; i++){
        rightTriangle(x, y, 2.0,2.0);
        x += 0.2;
        y -= 2;
    }

    //leftt side
    glColor3ub(22, 58, 21);
    leftTriangle(60,60,2,3);
    leftTriangle(60,58,2,3);
    leftTriangle(60,56,2,3);
    leftTriangle(60,54,2,2.4);
    leftTriangle(60,52,2,2.2);
    leftTriangle(60,50,2,2);
    leftTriangle(60,48,1,1.5);
    leftTriangle(60,47,1,1.5);

    //left
    //leftTriangle(60,41,1,1.3);
    //leftTriangle(60,40,1,1.3);
    //leftTriangle(60,39,1,1.3);
    float a=41.5;
    for(int j=0;j<15;j++){
        leftTriangle(60,a,1,1);
           a = a -1;
    }
    //leftTriangle(60,21,1,1);
     a=21;
    for(int j=0;j<14;j++){
        leftTriangle(60,a,1,1);
           a = a -1;

    }
    leftTriangle(60,3,1,1);

    //railroad
    glColor3f(0,0,0);
   // glColor3ub(104, 92, 62);
    glRectf(64,59,66,58);
    glRectf(63.5,57,66.5,56);
    glRectf(63,55,67,54);
    glRectf(62.5,53,67.5,52);
    glRectf(62,51,68,50);
    glRectf(61.5,49,68.5,48);
    glRectf(61.3,47,69,46);
    glRectf(61.2,45,69.3,44);
    glRectf(61.1,43,69.5,42);
    glRectf(61,41,69.7,40);
    glRectf(61,39,69.8,38);
    glRectf(61.1,37,69.9,36);
    glRectf(61.05,35,70,34);
    glRectf(61,33,70.2,32);
    glRectf(61,31,70.4,30);
    glRectf(61,29,70.6,28);
    glRectf(61,27,70.8,26);
    glRectf(61,25,71,24);
    glRectf(61,23,71.2,22);
    glRectf(61,21,71.4,20);
    glRectf(61,19,71.6,18);
    glRectf(61,17,71.8,16);
    glRectf(61,15,72,14);
    glRectf(61,13,72.2,12);
    glRectf(61,11,72.5,10);
    glRectf(61,9,72.7,8);
    glRectf(61,7,72.9,6);
    glRectf(61,5,73,4);
    glRectf(61,3,73.3,2);

    //glColor3ub(40, 40, 39);

 //rail pati
    glBegin(GL_POLYGON);
    glColor3ub(104, 92, 62);
    glVertex2d(62.5,2);
    glVertex2d(62.5,45);
    glVertex2d(63,45);
    glVertex2d(63,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 92, 62);
    glVertex2d(62.5,45);
    glVertex2d(64.5,60);
    glVertex2d(64.8,60);
    glVertex2d(63,45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 92, 62);
    glVertex2d(69,2);
    glVertex2d(68.4,2);
    glVertex2d(68,45);
    glVertex2d(68.5,45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 92, 62);
    glVertex2d(72,2);
    glVertex2d(71.4,2);
    glVertex2d(68,45);
    glVertex2d(68.5,45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(104, 92, 62);
    glVertex2d(65.4,60);
    glVertex2d(65,60);
    glVertex2d(68,45);
    glVertex2d(68.5,45);
    glEnd();
}

void MovingCloud()
{
  glColor3ub(192, 197, 209);
    cloudMove();
    glPushMatrix();
        glTranslatef(cloud1,1,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloud2,-2,0);
        circle(3,5,30,88);
        circle(3,5,33,91);
        circle(3,5,37,92);
        circle(3,5,37,87);
        circle(3,5,32,85);

    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloud3,-3,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);

    glPopMatrix();
    glPushMatrix();
        glTranslatef(cloud4,1,0);
        circle(3,5,30,88);
        circle(3,5,33,91);
        circle(3,5,37,92);
        circle(3,5,37,87);
        circle(3,5,32,85);

    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloud5,1,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);
    glPopMatrix();
}
void movingCloud()
{
    glColor3f(1,1,1);
    cloudMove();
    glPushMatrix();
        glTranslatef(cloud1,1,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloud2,-2,0);
        circle(3,5,30,88);
        circle(3,5,33,91);
        circle(3,5,37,92);
        circle(3,5,37,87);
        circle(3,5,32,85);

    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloud3,-3,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);

    glPopMatrix();
    glPushMatrix();
        glTranslatef(cloud4,1,0);
        circle(3,5,30,88);
        circle(3,5,33,91);
        circle(3,5,37,92);
        circle(3,5,37,87);
        circle(3,5,32,85);

    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloud5,1,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);
    glPopMatrix();

}
void sky()
{
    glColor3ub(160, 210, 250);
    glBegin(GL_POLYGON);
        glVertex2d(1.5,60);
        glVertex2d(1.5, 98);
        glVertex2d(98.5, 98);
        glVertex2d(98.5, 60);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2d(70,60);
        glVertex2d(75,55);
        glVertex2d(98.5,55);
        glVertex2d(98.5,60);
    glEnd();
    //sun
    glColor3ub(255, 255, 0);
    circle(5,7,75,85);
    //cloud left to right
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(cloud, 0, 0);
    //static cloud
    circle(3,4,78,71);
    circle(3,4,75,67);
    circle(3,4,78,62);
    circle(3,4,80,65);
    glPopMatrix();
    cloud += .1;
    if(cloud > 50){
        cloud = -10;
    }
    glutPostRedisplay();
    //horizontal flying cloud
    movingCloud();
    //horizontal bird flying
    MovingBird();

}

void homes()
{
    glColor3ub(66, 195, 76);
    glBegin(GL_POLYGON);
        glVertex2d(1.5,60);
        glVertex2d(60,60);
        glVertex2d(60,2);
        glVertex2d(1.5,2);
    glEnd();

    glColor3ub(22, 49, 22);
    circle(2,3,8,60);
    circle(2,3,11,60);
    circle(1,2,13,60);

    circle(1,2,28,60);
    circle(2,3,30.5,60);
    circle(2,3,33.5,60);

    circle(1,2,51,60);
    circle(2,3,53.5,60);
    circle(2,3,56.5,60);

    //footpath in the village
    glColor3ub(88, 92, 101);
    glBegin(GL_QUADS);
    glVertex2d(1.5,40);
    glVertex2d(1.5,30);
    glVertex2d(60,30);
    glVertex2d(60,40);
    glColor3ub(66, 50, 13);
    glVertex2d(1.5,40);
    glVertex2d(1.5,39);
    glVertex2d(60,39);
    glVertex2d(60,40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(66, 50, 13);
    glVertex2d(1.5,31);
    glVertex2d(1.5,30);
    glVertex2d(60,30);
    glVertex2d(60,31);
    glEnd();

    glColor3ub(255, 253, 242);
    glRectf(5,35.5,9,34);
    glRectf(14,35.5,18,34);
    glRectf(23,35.5,27,34);
    glRectf(32,35.5,36,34);
    glRectf(41,35.5,45,34);
    glRectf(50,35.5,54,34);

    //houses
    house1(7,55);
    house2(27,55);
    house1(50,55);
    house1(2,18);
    house2(22,18);
    house1(44,18);
  //trees
    //first row
    //3
    glColor3ub(68, 83, 2);
   circle(1.5,1.5,25.5,55);
    tree2(23,73);

    //4
    glColor3ub(68, 83, 2);
    circle(1.5,1.5,42,49);
    //5
    glColor3ub(68, 83, 2);
    circle(1,1,45,55);

    //6
    glColor3ub(68, 83, 2);
    circle(1.5,1.5,48.5,44);
    tree2(46,62);
     //apple tree
     //root

     glColor3ub(68, 83, 2);
    circle(3.5,3,18,44);

    //body
    glColor3ub(68, 43,2);
    glBegin(GL_QUADS);
        glVertex2d(17,68);
        glVertex2d(19,68);
        glVertex2d(20,43);
        glVertex2d(16,43);
    glEnd();
    //leaves
    glColor3ub(11, 70, 11);
    circle(3,4,13,69);
    circle(3,4,16,71);
    circle(3,4,18,69);
    circle(3,4,21,71);
    circle(3,4,22,67);
    circle(3,4,22,63);
    circle(3,4,18,65);
    circle(3,4,15,64);
    circle(3,4,13,66);
    //fruits
    glColor3ub(245, 40, 40);
    circle(.5,1,11,69);
    circle(.5,1,13,71);
    circle(.5,1,16,73);
    circle(.5,1,19,72);
    circle(.5,1,21,73);
    circle(.5,1,23,71);
    circle(.5,1,24,67);
    circle(.5,1,23,63);
    circle(.5,1,21,67);
    circle(.5,1,18,67);
    circle(.5,1,15,68);
    circle(.5,1,12,65);
    circle(.5,1,14,64);
    //fruits fall
    appleFall();
    //trees
    //second row
    glColor3ub(68, 83, 2);
    circle(1,1,34,9);

    glColor3ub(68, 83, 2);
    circle(1.5,1.5,53.5,8.5);

    glColor3ub(68, 83, 2);
    circle(1,1,59,19);
    //orange tree
    glColor3ub(68, 83, 2);
    circle(3.5,3,40,12);

    //body
    glColor3ub(68, 43, 2);
    glBegin(GL_QUADS);
        glVertex2d(39,36);
        glVertex2d(41,36);
        glVertex2d(42,11);
        glVertex2d(38,11);
    glEnd();
    //leaves
    glColor3ub(11, 70, 11);
    circle(3,4,35,37);
    circle(3,4,38,39);
    circle(3,4,40,37);
    circle(3,4,43,39);
    circle(3,4,44,35);
    circle(3,4,44,31);
    circle(3,4,40,33);
    circle(3,4,37,32);
    circle(3,4,35,34);

    //fruits
    glColor3ub(255, 165, 0);
    circle(.5,1,33,37);
    circle(.5,1,35,39);
    circle(.5,1,38,41);
    circle(.5,1,41,39);
    circle(.5,1,43,41);
    circle(.5,1,45,39);
    circle(.5,1,46,35);
    circle(.5,1,45,31);
    circle(.5,1,43,35);
    circle(.5,1,40,35);
    circle(.5,1,37,36);
    circle(.5,1,34,33);
    circle(.5,1,36,32);
}
void dayMode()
{
    delay();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);

    sky();
    road();
    homes();
    river();
   glFlush();

}
void my_keyboard(unsigned char key,int x, int y)
{
	switch (key) {

		case 'd':
			 dayMode();
			 break;

	   default:
			break;
	}
}
void init()
{
    glClearColor(0, 0, 0, 10);
    glOrtho(0, 100.0, 0, 100.0 , 0, 100.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1300, 650);
	glutInitWindowPosition (0, -90);
	glutCreateWindow("Dream_Village");
	init();
	glutDisplayFunc(dayMode);
	glutKeyboardFunc(my_keyboard);
	glutFullScreen();
	glutMainLoop();
	return 0;
}

