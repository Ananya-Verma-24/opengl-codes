#include <GL/glut.h>
#include <GL/gl.h>
void display(void) {
 glClear(GL_COLOR_BUFFER_BIT);
 glLineWidth(2.5);
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(0.0, 0.0, 0.0);
 glVertex3f(1, 1, 0.0);
 glEnd();
 glFlush();
}
void init(void) {
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(100, 100);
 glutInitWindowSize(500, 500);
 glutCreateWindow(" Line");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
