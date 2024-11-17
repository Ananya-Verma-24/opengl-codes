#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glut.h>
float tx=0.0, angle=0.0, scale=1.0;
void init() {
 glClearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-10.0,10.0,-10.0,10.0);
}
void drawLine() {
 glBegin(GL_LINES);
 glVertex2f(-5.0,0.0);
 glVertex2f(5.0,0.0);
 glEnd();
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glPushMatrix();  //Saves the current transformation matrix to a stack so that changes made here do not affect the global state.
 glTranslatef(tx,0.0,0.0);
 glRotatef(angle,0.0,0.0,1.0);
 glScalef(scale,scale,1.0);
 glColor3f(0.0,0.0,1.0);
 drawLine();
 glPopMatrix();
 glFlush();
}
void keyboard(unsigned char key,int x,int y) {
 if (key=='t') tx+=0.5;
 else if (key=='T') tx-=0.5;
 else if (key=='r') angle-=5.0;
 else if (key=='R') angle+=5.0;
 else if (key=='s') scale=(scale>0.1)?scale-0.1:0.1;
 else if (key=='S') scale+=0.1;
 else if (key==27) exit(0);
 glutPostRedisplay();
}
int main(int argc,char**argv) {
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutCreateWindow("Line Transformations");
 init();
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}
