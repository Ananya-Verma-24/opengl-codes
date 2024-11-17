#include <GL/glut.h>

// Variables to control transformation
float angleX = 0.0f, angleY = 0.0f;  // Rotation angles
float scale = 1.0f;                  // Scaling factor
float translateX = 0.0f, translateY = 0.0f, translateZ = -5.0f;  // Translation factors

// Initialize OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D effects
}

// Function to draw the cube
void drawCube() {
    glBegin(GL_QUADS);

    // Front face (z = 1.0)
    glColor3f(1.0, 0.0, 0.0);  // Red color
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f(-1.0,  1.0,  1.0);

    // Back face (z = -1.0)
    glColor3f(0.0, 1.0, 0.0);  // Green color
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);

    // Top face (y = 1.0)
    glColor3f(0.0, 0.0, 1.0);  // Blue color
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0, -1.0);

    // Bottom face (y = -1.0)
    glColor3f(1.0, 1.0, 0.0);  // Yellow color
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f(-1.0, -1.0,  1.0);

    // Right face (x = 1.0)
    glColor3f(1.0, 0.0, 1.0);  // Magenta color
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f( 1.0, -1.0,  1.0);

    // Left face (x = -1.0)
    glColor3f(0.0, 1.0, 1.0);  // Cyan color
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f(-1.0,  1.0, -1.0);

    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear color and depth buffer
    glLoadIdentity();  // Reset transformations

    // Apply transformations
    glTranslatef(translateX, translateY, translateZ);  // Translation
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);  // Rotation around X-axis
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);  // Rotation around Y-axis
    glScalef(scale, scale, scale);  // Scaling

    // Draw the cube
    drawCube();

    glutSwapBuffers();  // Swap buffers for smooth animation
}

// Timer function to update transformations
void timer(int value) {
    angleX += 1.0f;  // Increment rotation angle on X-axis
    angleY += 1.0f;  // Increment rotation angle on Y-axis

    if (scale >= 2.0f || scale <= 0.5f) value = -value;  // Reverse scaling if it exceeds limits
    scale += value * 0.01f;

    glutPostRedisplay();  // Request display update
    glutTimerFunc(16, timer, value);  // Call timer function every ~16 ms (~60 fps)
}

// Keyboard input handler
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': translateY += 0.1f; break;  // Move cube up
        case 's': translateY -= 0.1f; break;  // Move cube down
        case 'a': translateX -= 0.1f; break;  // Move cube left
        case 'd': translateX += 0.1f; break;  // Move cube right
        case 'q': translateZ += 0.1f; break;  // Move cube closer
        case 'e': translateZ -= 0.1f; break;  // Move cube further
        case 27:  exit(0);  // Exit on ESC key
    }
    glutPostRedisplay();
}

// Reshape function to handle window resize
void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // Set the viewport to cover the new window
    glMatrixMode(GL_PROJECTION);      // Switch to projection matrix
    glLoadIdentity();                 // Reset the projection matrix
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);  // Set perspective
    glMatrixMode(GL_MODELVIEW);       // Switch back to modelview matrix
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Enable double buffering and depth testing
    glutInitWindowSize(800, 600);  // Set window size
    glutCreateWindow("Cube Translation, Rotation, Scaling");  // Create window with title

    init();  // Call initialization routine

    // Register callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 1);

    glutMainLoop();  // Start the main loop

    return 0;
}
