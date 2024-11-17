#include<GL/glut.h>
#include<stdlib.h>
// Define the vertices of the cube
GLfloat vertices[][3] = {
 {-1, -1, -1},
 {1, -1, -1},
 {1, 1, -1},
 {-1, 1, -1},
 {-1, -1, 1},
 {1, -1, 1},
 {1, 1, 1},
 {-1, 1, 1}
};
// Define the cube's faces by specifying the vertices
int faces[][4] = {
 {0, 1, 2, 3},
 {4, 5, 6, 7},
 {0, 3, 7, 4},
 {1, 2, 6, 5},
 {0, 1, 5, 4},
 {2, 3, 7, 6}
};
// Define the colors for each face
GLfloat colors[][3] = {
 {0.0, 0.0, 0.0}, // Black
 {1.0, 0.0, 0.0}, // Red
 {0.0, 1.0, 0.0}, // Green
 {0.0, 0.0, 1.0}, // Blue
 {1.0, 1.0, 0.0}, // Yellow
 {1.0, 0.0, 1.0} // Magenta
};
void drawCube() {
    for (int i = 0; i < 6; i++) {
        glBegin(GL_POLYGON);
        glColor3fv(colors[i]);
        for (int j = 0; j < 4; j++) {
            glVertex3fv(vertices[faces[i][j]]);
        }
        glEnd();
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0); // Translate to a suitable viewing position
    glRotatef(45.0, 1.0, 1.0, 0.0); // Rotate the cube
    drawCube();
    glFlush();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cube Example");
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
