#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void myinit();
void display();
void car();
GLint flag=0;
GLfloat axis[] = {0.0,0.0,0.0};
//GLint axis = 2;
GLdouble viewer[]= {0.0, 0.0, 5.0};
void light()
{
GLfloat mat_ambient[]={1.0,1.0,1.0,1.0};
GLfloat mat_diffuse[]={0.5,0.5,0.5,1.0};
GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
GLfloat light_position[]={2.0,6.0,3.0,1.0};
GLfloat lightIntensity[]={0.7,0.7,0.7,1.0};
display();
}
void mouse(int btn, int state, int x, int y)
{
if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) flag=1;
//if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) viewer[1]=15;
if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) flag=0;
//theta[axis] += 2.0;
//if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
display();
}
void keys(unsigned char key, int x, int y)
{
if(key == 'x') viewer[0]-= 1.0;
if(key == 'X') viewer[0]+= 1.0;
if(key == 'y') viewer[1]-= 1.0;
if(key == 'Y') viewer[1]+= 1.0;
if(key == 'z') viewer[2]-= 1.0;
if(key == 'Z') viewer[2]+= 1.0;
display();
}


void myinit()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glClearColor(0.54,0.82,0.94,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,1000.0,0.0,1000.0);
}
void tree()
{
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.2,0);
 glVertex2i(90,200);
 glVertex2i(110,200);
 glVertex2i(110,100);
 glVertex2i(90,100);
 glEnd();
 glBegin(GL_TRIANGLES);
 glColor3f(0.1,0.5,0.1);
 glVertex2i(50,200);
 glVertex2i(150,200);
 glVertex2i(100,300);
 glEnd();
 glBegin(GL_TRIANGLES);
 glColor3f(0.1,0.5,0.1);
 glVertex2i(30,250);
 glVertex2i(170,250);
 glVertex2i(100,350);
 glEnd();
 glScalef(1.0,1.0,0.0);
}
void display()
{
static GLfloat ty=-500; 
glClear(GL_COLOR_BUFFER_BIT);
//replicating the trees 3t by tree func using translate n scale func
glMatrixMode(GL_MODELVIEW);
tree();
glPushMatrix();
glTranslatef(0.0,600.0,0.0);
tree();
glPopMatrix();
glPushMatrix();
glTranslatef(800.0,0.0,0.0);
glScalef(1.0,1.0,0.0);
tree();
glPopMatrix();
glPushMatrix();
glTranslatef(800.0,600.0,0.0);
//glScalef();
tree();
glPopMatrix();
glPushMatrix();
 glColor3f(0.0,0.4,0.2);
 glBegin(GL_POLYGON);
 glColor3f(0.1,0.1,0.1);
 glVertex2i(300,0);
 glVertex2i(700,0);
 glVertex2i(700,1000);
 glVertex2i(300,1000);
 glEnd();
 
 //toll
 static GLfloat rx = 505;int i=0;
 static GLfloat lx = 505;
 //toll lines on left side
 glBegin(GL_LINES);
 glColor3f(1.0,1.0,1.0);
 glVertex2i(380,740);
 glVertex2i(rx,740);
 glEnd();
 //toll lines on left side
 glBegin(GL_LINES);
 glColor3f(1.0,1.0,1.0);
 glVertex2i(lx,740);
 glVertex2i(620,740);
 glEnd();
 
 //toll side rect connection
 //left connection
 glBegin(GL_POLYGON);
 glColor3f(1.0,0.0,0.0);
 glVertex2i(380,730);
 glVertex2i(390,730);
 glVertex2i(390,750);
 glVertex2i(380,750);
 glEnd();
 //right connection
 glBegin(GL_POLYGON);
 glColor3f(1.0,0.0,0.0);
 glVertex2i(620,730);
 glVertex2i(610,730);
 glVertex2i(610,750);
 glVertex2i(620,750);
 glEnd();
 //toll middle connection
 glBegin(GL_POLYGON);
 glColor3f(1.0,0.0,0.0);
 glVertex2i(490,730);
 glVertex2i(510,730);
 glVertex2i(510,750);
 glVertex2i(490,750);
 glEnd();
  //toll box
 //left box
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(320,700);
 glVertex2i(380,700);
 glVertex2i(380,780);
 glVertex2i(320,780);
 glEnd();
 //right box
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(620,700);
 glVertex2i(680,700);
 glVertex2i(680,780);
 glVertex2i(620,780);
 glEnd();
  //toll box top
 //left toll box
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(330,780);
 glVertex2i(335,790);
 glVertex2i(345,790);
 glVertex2i(350,780);
 glEnd();
 //right toll box
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(630,780);
 glVertex2i(635,790);
 glVertex2i(645,790);
 glVertex2i(650,780);
 glEnd();
  
 //dash line
 glEnable(GL_LINE_STIPPLE);
 glLineStipple(6,0x00FF);
 glLineWidth(6);
 glBegin(GL_LINES);
 glColor3f(1.0,1.0,1.0);
 glVertex2i(500,0);
 glVertex2i(500,1000);
 glEnd();
 glDisable(GL_LINE_STIPPLE);
 //calling car func 2 times for 2cars
 //car on left side
glColor3f(0.2+i,0.1+i,0.05+i); 
glPushMatrix();
 glTranslatef(0.0,ty,0.0);
 car();
 glPopMatrix();
 //car on right side
 //glColor3f(0.2+i,0.1+i,0.05+i); 
 glPushMatrix();
 glTranslatef(150.0,ty,0.0);
car();
 glPopMatrix();

 glFlush();
 
 //making the car move
 if(flag==1)
 {
 ty=ty+0.5;
 }//inc r dec car speed
 if(ty==600)//if car crosses out  window   come back
    ty=-600;
    //i+=0.1;
  if(ty==110)
     sleep(1);
 //toll gate to open
 if(ty>110 && ty<350 && rx>=380)
 {
 	rx-=0.5;
 	lx+=0.5;
 }
  //toll gate to close
  if(ty>350 && ty<600 && rx<=505)
 {
 	rx+=0.5;
 	lx-=0.5;
 }
 glutSwapBuffers();/*use two buffers for animation,one buffer contains alll info abt an first image n second buffer will be ready with next image for smooth image which takes less time*/
 glutPostRedisplay();/*to call display fun  repeatedly*/
 //set the light source properties

}
void car()
{
 //car left side
 glBegin(GL_POLYGON);
 glColor3f(1.0,0.0,0.0);
 glVertex2i(400,400);
 glVertex2i(450,400);
 glVertex2i(450,500);
 glVertex2i(400,500);
 glEnd();
 //car lines left
 glBegin(GL_LINES);
 glColor3f(1.0,1.0,1.0);
 glLineWidth(10.0);
 glVertex2i(400,420);
 glVertex2i(450,420);
 glEnd();

 glBegin(GL_LINES);
 glColor3f(1.0,1.0,1.0);
 glVertex2i(400,480);
 glVertex2i(450,480);
 glEnd();
 //front wheel left
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(400,470);
 glVertex2i(390,470);
 glVertex2i(390,490);
 glVertex2i(400,490);
 glEnd();
  
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(450,490);
 glVertex2i(460,490);
 glVertex2i(460,470);
 glVertex2i(450,470);
 glEnd();
 //backside wheel left
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(390,430);
 glVertex2i(400,430);
 glVertex2i(400,410);
 glVertex2i(390,410);
 glEnd();
 
 glBegin(GL_POLYGON);
 glColor3f(0.5,0.5,0.5);
 glVertex2i(450,430);
 glVertex2i(460,430);
 glVertex2i(460,410);
 glVertex2i(450,410);
 glEnd();
 
}
void main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize(1000,1000);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutCreateWindow("an complex prg");
  glutInitWindowPosition(100,200);
  myinit();
  display();
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keys);
  glutMainLoop();
}
  

