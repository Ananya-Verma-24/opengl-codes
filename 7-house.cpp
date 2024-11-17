#include<GL/glut.h>
#include<GL/gL.h>
#include<stdlib.h>
#include<math.h>
float D = 0;
float diff = -0.0001;
void MyInit() {
glClearColor(1, 1, 1, 0);
glColor3f(1, 0, 0);
}
void rise() {
if (D < 0) diff = 0.0001;
if (D > 1) diff = -0.0001;
D += diff;
glutPostRedisplay();
}
void mountain() {
glColor3f(0.64, 0.16, 0.16);
glBegin(GL_POLYGON);
glVertex2f(-1, 0);
glVertex2f(-0.5, 0.5);
glVertex2f(0, 0.25);
glVertex2f(0, 0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(1, 0);
glVertex2f(0.5, 0.5);
glVertex2f(0, 0.25);
glVertex2f(0, 0);
glEnd();
}
void garden() {
glColor3f(0.49, 0.98, 0);
glBegin(GL_POLYGON);
glVertex2f(-1, 0);
glVertex2f(-1, -1);
glVertex2f(1, -1);
glVertex2f(1, 0);
glEnd();
}
void house() {
glColor3f(0, 0, 1);
glBegin(GL_POLYGON);
glVertex2d(
-0.85, 
-0.5);
glVertex2d(
-0.5, 
-0.25);
glVertex2d(
-0.15, 
-0.5);
glEnd();
glColor3f(1, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(
-0.75, 
-0.5);
glVertex2d(
-0.75, 
-0.85);
glVertex2d(
-0.25, 
-0.85);
glVertex2d(
-0.25, 
-0.5);
glEnd();
}
void sun() {
glColor3f(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2f(
-1, 0);
glVertex2f(
-1, 1);
glVertex2f(1, 1);
glVertex2f(1, 0);
glEnd();
float x1, y1, x2, y2;
float angle;
double radius = 0.25;
x1 = 0, y1 = D;
glColor3f(1.0, 1.0, 0.6);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x1, y1);
for (angle = 1.0f;angle < 361.0f;angle += 0.2) {
x2 = x1 + sin(angle) * radius;
y2 = y1 + cos(angle) * radius;
glVertex2f(x2, y2);
}
glEnd();
}
void display() {
glLoadIdentity();
sun();
mountain();
garden();
house();
glFlush();
}
int main(int argc, char* argv[]) {
glutInit(&argc, argv);
glutInitWindowPosition(100, 100);
glutInitWindowSize(250, 250);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Sunrise");
MyInit();
glutDisplayFunc(display);
glutIdleFunc(rise);
glutMainLoop();
return 0;
}