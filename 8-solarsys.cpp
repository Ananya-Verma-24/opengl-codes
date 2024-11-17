#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
float diff = -0.0001;
float Er = 0.75, Eangle = 0.0;
float Mr = 0.3, Mangle = 0.0;
void MyInit()
{
 glClearColor(1, 1, 1, 0);
 glColor3f(1, 0, 0);
}
void moonRevolve()
{
 Mangle += 0.003;
 if (Mangle > 360)
 Mangle = 0.0;
}
void earthRevolve()
{
 Eangle += 0.001;
 if (Eangle > 360)
 Eangle = 0.0;
 moonRevolve();
 glutPostRedisplay();
}
void moon(float x, float y)
{
 float x1, y1, x2, y2;
 float angle;
 double radius = Mr;
 x1 = x, y1 = y;
 glColor3f(1, 1, 1);
 glBegin(GL_LINE_LOOP);
 for (angle = 0.0f; angle < 270.0f; angle += 0.2)
 {
 x2 = x1 + cos(angle) * radius;
 y2 = y1 + sin(angle) * radius;
 glVertex2f(x2, y2);
 }
 glEnd();
 glColor3f(0.96, 0.94, 0.83);
 radius = 0.10;
 x1 = cos(Mangle) * (Mr)+
x, y1 = sin(Mangle) * (Mr)+
y
;
 glBegin(GL_TRIANGLE_FAN);
 glVertex2f(x1, y1);
 for (angle = 1.0f; angle < 361.0f; angle += 0.2)
 
{
 x2 = x1 + cos(angle) * radius;
 y2 = y1 + sin(angle) * radius;
 glVertex2f(x2, y2);
 
}
 glEnd(); }
void sun() {
 float x1, y1, x2, y2;
 float angle;
 double radius = 0.25;
 x1 = 0, y1 = 0;
 glColor3f(1.0, 1.0, 0.6);
 glBegin(GL_TRIANGLE_FAN);
 glVertex2f(x1, y1);
 for (angle = 1.0f; angle < 361.0f; angle += 0.2)
 
{
 x2 = x1 + cos(angle) * radius;
 y2 = y1 + sin(angle) * radius;
 glVertex2f(x2, y2);
 
}
 glEnd(); }
void earth() {
 glColor3f(0, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2f(
-1, 
-1);
 glVertex2f(
-1, 1);
 glVertex2f(1, 1);
 glVertex2f(1, 
-1);
 glEnd();
 float x1, y1, x2, y2;
 float angle;
 double radius = Er;
 x1 = 0, y1 = 0;
 glColor3f(1, 1, 1);
 glBegin(GL_LINE_LOOP);
 for (angle = 0.0f; angle < 270.0f; angle += 0.2)
 
{
 x2 = x1 + cos(angle) * radius;
 y2 = y1 + sin(angle) * radius;
 glVertex2f(x2, y2);
 
}
 glEnd();
 glColor3f(0, 0, 1);
 radius = 0.15;
 x1 = cos(Eangle) * Er, y1 = sin(Eangle) * Er;
 glBegin(GL_TRIANGLE_FAN);
 glVertex2f(x1, y1);
 for (angle = 1.0f; angle < 361.0f; angle += 0.2)
 {
 x2 = x1 + cos(angle) * radius;
 y2 = y1 + sin(angle) * radius;
 glVertex2f(x2, y2);
 }
 glEnd();
 moon(x1, y1);
}
void display()
{
 glLoadIdentity();
 earth();
 sun();
 glFlush();
}
int main(int argc, char* argv[])
{
 glutInit(&argc, argv);
 glutInitWindowPosition(100, 100);
 glutInitWindowSize(250, 250);
 glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
 glutCreateWindow("Solar System");
 MyInit();
 glutDisplayFunc(display);
 glutIdleFunc(earthRevolve);
 glutMainLoop();
 return 0;
}
