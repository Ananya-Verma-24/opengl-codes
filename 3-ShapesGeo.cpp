#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>

const GLfloat radius = 0.2f;  // Radius of the circle
const GLfloat centerX = -0.5f;  // X-coordinate for the circle center
const GLfloat centerY = 0.5f;   // Y-coordinate for the circle center
const int sides = 100;          // Number of sides for the circle

// Function to draw a circle
void drawCircle() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);  // Yellow color for circle
    for (int i = 0; i < sides; i++) {
        GLfloat theta = 2.0f * 3.14f * (GLfloat)i / (GLfloat)sides;
        GLfloat x = radius * cos(theta) + centerX;
        GLfloat y = radius * sin(theta) + centerY;
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to draw a square in the top-right quadrant
void drawSquare() {
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);  // Gray color for square
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();
}

// Function to draw a rectangle in the bottom-left quadrant
void drawRectangle() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);  // Green color for rectangle
    glVertex3f(-0.75, -0.75, 0.0);
    glVertex3f(-0.25, -0.75, 0.0);
    glVertex3f(-0.25, -0.5, 0.0);
    glVertex3f(-0.75, -0.5, 0.0);
    glEnd();
}

// Function to draw a triangle in the bottom-right quadrant
void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);  // Red color for triangle
    glVertex3f(0.25, -0.25, 0.0);
    glVertex3f(0.5, -0.75, 0.0);
    glVertex3f(0.75, -0.25, 0.0);
    glEnd();
}

// Display function to render all the shapes
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw each shape with its specific function in different quadrants
    drawCircle();     // Top-left
    drawSquare();     // Top-right
    drawRectangle();  // Bottom-left
    drawTriangle();   // Bottom-right

    glFlush();
}

// Initialization
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Set background to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Combined Shapes in Quadrants");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
