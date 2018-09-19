

/* -- INCLUDE FILES ------------------------------------------------------ */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>


static GLfloat spin = 0.0;
void init(void)
{
    std::cout << "INIT" << std::endl << std::endl;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
void display(void)
{
    std::cout << "DISPLAY" << std::endl << std::endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay(void)
{
    std::cout << "SPIN" << std::endl << std::endl;
    spin = spin + 2.0;
    if (spin > 360.0)
    spin = spin - 360.0;
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    std::cout << "RESHAPE" << std::endl << std::endl;
    std::cout << w << " " << h << std::endl;
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void mouse(int button, int state, int x, int y)
{
    std::cout << "MOUSE" << std::endl << std::endl;
    switch (button) {
    case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN)
    glutIdleFunc(spinDisplay);
    break;
    case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN)
    glutIdleFunc(NULL);
    break;
    default:
    break;
    }
}

void key(unsigned char Key, int x, int y)
{
    std::cout << "MOUSE" << std::endl << std::endl;
    switch (Key) {
    case 'r':
        glutIdleFunc(spinDisplay);
        break;
    case 'c':
        glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}
/*
* Request double buffer display mode.
* Register mouse input callback functions
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Vidu_02");
    init();
    std::cout << "MAIN" << std::endl << std::endl;
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutMainLoop();
return 0;
}
/* ----------------------------------------------------------------------- */

