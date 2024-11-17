#include <GL/glut.h>
#include <GL/gl.h>
#define GL_GLEXT_PROTOTYPES

void display();
void specialKeys();

// Rotation, scale, and translation variables
double rotate_y = 0.0;
double rotate_x = 0.0;
double scale = 2.5;
double translate_x = 0.0;
double translate_y = 0.0;

void display() {
    // Clear screen and Z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reset transformations
    glLoadIdentity();

    // Apply translations
    glTranslatef(translate_x, translate_y, 0.0);
    
    // Apply rotations
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    
    // Apply scaling
    glScaled(scale, scale, 1.0);
    
    // Set line width and draw the line
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5); // Line color
    glVertex3f(0.0, 0.0, 0.0); // Starting point of the line
    glVertex3f(1.0, 1.0, 0.0); // Ending point of the line
    glEnd();
    
    // Flush and swap buffers to display result
    glFlush();
    glutSwapBuffers();
}

// Handle special key presses
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            rotate_y += 5.0;
            break;
        case GLUT_KEY_LEFT:
            rotate_y -= 5.0;
            break;
        case GLUT_KEY_UP:
            rotate_x += 5.0;
            break;
        case GLUT_KEY_DOWN:
            rotate_x -= 5.0;
            break;
        case GLUT_KEY_F1:
            scale += 0.1; // Scale up
            break;
        case GLUT_KEY_F2:
            scale -= 0.1; // Scale down
            break;
        case GLUT_KEY_F3:
            translate_x += 0.1; // Translate right
            break;
        case GLUT_KEY_F4:
            translate_x -= 0.1; // Translate left
            break;
        case GLUT_KEY_F5:
            translate_y += 0.1; // Translate up
            break;
        case GLUT_KEY_F6:
            translate_y -= 0.1; // Translate down
            break;
    }
    // Redisplay updated transformations
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    
    // Set display mode (double buffer and RGB)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    // Create the window
    glutCreateWindow("Line Transformation");
    
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    
    // Register callbacks
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    
    // Start the GLUT main loop
    glutMainLoop();
    
    return 0;
}
