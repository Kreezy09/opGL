#include <GL/glut.h>
#include <iostream>

int x1 = -4, yi = 3, x2 = 5, y2 = -2;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    int dx = x2 - x1;
    int dy = y2 - yi;

    int x = x1, y = yi;

    glBegin(GL_POINTS);
    glVertex2i(x, y); // Plot the initial point

    int P = 2 * dy - dx; // Initial decision parameter

    while (x < x2) {
        x++;
        if (P < 0) {
            P += 2 * dy;
        } else {
            P += 2 * dy - 2 * dx;
            y--; // Corrected: Decrement y when P_k >= 0
        }
        glVertex2i(x, y);
    }

    glEnd();
    glFlush();
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Line Drawing Algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
