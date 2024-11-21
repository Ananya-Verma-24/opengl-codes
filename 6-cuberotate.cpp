#include<GL/glut.h>

//define vertices of the cube

GLfloat vertices[][3] = {
    {-1,-1,-1},
    {1,-1,-1},
    {1,1,-1},
    {-1,1,-1},
    {-1,-1,1},
    {1,-1,1},
    {1,1,1},
    {-1,1,1}
};

//define the cube's faces by specifying the vertices

int faces[][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {0,3,7,4},
    {1,2,6,5},
    {0,1,5,4},
    {2,3,7,6}
};

//Define the colors for each faces
GLfloat colors[][3] = {
    {1.0, 1.0, 1.0}, //white
    {1.0, 0.0, 0.0},  // Red
    {0.0, 1.0, 0.0},  //Green
    {0.0, 0.0, 1.0},  //Blue
    {1.0, 1.0, 0.0},  //Yellow
    {1.0, 0.0, 1.0}   //Magenta
};

GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLfloat angleZ = 0.0f;
GLfloat scale = 1.0f;
GLfloat translx = -1.0f;
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
    glTranslatef(translx, 0.0, -5.0); //translate to a sutable viewing
    glRotatef(angleX, 1.0, 0.0, 0.0), // Rotate the cube glRotatef(angley, 08, 10, 88),
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    glScalef(scale, scale, scale),
    drawCube();
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'x': angleX += 5.0f;
        break;
    case 'y': angleY += 5.0f;
        break;
    case 'z': angleZ += 5.0f;
        break;
    case 's': scale += 0.1f;
        break;
    case 'S': scale -= 0.1f;
        break;
    case 't': translx += 0.1f;
        break;
    case 'T': translx -= 0.1f;
        break;
    case 27: exit(0); break;
   }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   // glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow(" Cube");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();
    return 0;
}
