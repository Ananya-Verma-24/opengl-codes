#include <GL/glut.h>
#include <cmath>
// Ball properties
float ballRadius = 0.1;
float ballX = 0.0;
float ballY = 0.0;
float ballSpeedX = 0.0;
float ballSpeedY = 0.0;
// Window dimensions
int windowWidth = 800;
int windowHeight = 600;
// Timer function for animation
void timer(int value) {
 // Update ball position
 ballX += ballSpeedX;
 ballY += ballSpeedY;
 // Bounce off the walls
 if (ballX + ballRadius > 1.0 || ballX - ballRadius < -1.0) {
 ballSpeedX = -ballSpeedX;
 }
 if (ballY + ballRadius > 1.0 || ballY - ballRadius < -1.0) {
 ballSpeedY = -ballSpeedY;
 }
 glutPostRedisplay();
 glutTimerFunc(16, timer, 0); // 60 frames per second
}
// Keyboard input function
void keyboard(unsigned char key, int x, int y) {
 switch (key) {
 case 'w':
 ballSpeedY = 0.02;
 ballSpeedX = 0.0;
 break;
 case 's':
 ballSpeedY = -0.02;
 ballSpeedX = 0.0;
 break;
 case 'a':
 ballSpeedX = -0.02;
 ballSpeedY = 0.0;
 break;
 case 'd':
 ballSpeedX = 0.02;
 ballSpeedY = 0.0;
 break;
 case 'S':
 ballSpeedX = 0.0;
 ballSpeedY = 0.0;
 break;
 default:
 break;
 }
}
// Display function
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 // Draw the ball
 glColor3f(1.0, 0.0, 0.0); // Red color
 glTranslatef(ballX, ballY, 0.0);
 glutSolidSphere(ballRadius, 30, 30);
 glLoadIdentity();
 glutSwapBuffers();
}
// Initialize OpenGL settings
void init() {
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
 glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(windowWidth, windowHeight);
 glutCreateWindow("Bouncing Ball with Keyboard Control");
 init();
 glutDisplayFunc(display);
 glutTimerFunc(0, timer, 0);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}