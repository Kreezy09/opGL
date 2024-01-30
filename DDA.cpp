#include <GL/glut.h>
#include <iostream>
#include <cmath>

float x1, x2, yi, y2;

void display(void) {
    float dy, dx, step, x, y, m, k, xp, yp;
    dx = x2 - x1;
    dy = y2 - yi;
    m = dy / dx;
	std::cout << "m: " << m << std::endl;
    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    } else
        step = abs(dy);
    xp = x1;
    yp = yi;
    glBegin(GL_POINTS);
    glVertex2i(xp, yp);
    glEnd();
    std::cout << "Initial x: " << xp << ", y: " << yp << std::endl;

    if (m < 1) {
        for (k = 1; k <= step; k++) {
            xp = 1 + xp;
			x = round(xp);
            yp = m + yp;
			y = round(yp);
            std::cout << "m<1 " << "x: " << x << ", y: " << y << std::endl;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    } else if (m == 1) {
        for (k = 1; k <= step; k++) {
            x = round(1 + x);
            y = round(1 + y);
            std::cout << "m==1 " << "x: " << x << ", y: " << y << std::endl;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    } else {
        for (k = 1; k <= step; k++) {
            x = round(1 / m + x);
            y = round(1 + y);
            std::cout << "m>1 " << "x: " << x << ", y: " << y << std::endl;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }
    glFlush();
}

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 15.0, 0.0, 5.0);
}

int main(int argc, char **argv) {
    x1 = 5;
    yi = 1;
    x2 = 10;
    y2 = 3;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
