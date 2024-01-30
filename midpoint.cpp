#include <GL/glut.h>
#include <iostream>

int x2, y2, x3, y3;

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x2, int x3, int y2, int y3) {
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = x3 - x2;
    dy = y3 - y2;

    incx = 1;
    if (dx < 0) incx = -1;
    incy = 1;
    if (dy < 0) incy = -1;

    x = x2;
    y = y2;

    draw_pixel(x, y);

    if (dx > dy) {
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;

        for (i = 0; i < dx; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1;
            } else {
                e += inc2;
            }
            x += incx;
            draw_pixel(x, y);
        }
    } else {
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;

        for (i = 0; i < dy; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1;
            } else {
                e += inc2;
            }
            x += incx;
            draw_pixel(x, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3f(1.0, 1.0, 1.0); // Set color to white

    // Draw Y-axis
    glBegin(GL_LINES);
    glVertex2f(0, -10);  // Starting point of Y-axis
    glVertex2f(0, 10);   // Ending point of Y-axis
    glEnd();

    // Draw X-axis
    glBegin(GL_LINES);
    glVertex2f(-10, 0);  // Starting point of X-axis
    glVertex2f(10, 0);   // Ending point of X-axis
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Set color to red
    draw_line(x2, x3, y2, y3);

    glFlush();
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc, char **argv) {
    printf("Enter (x2, y2, x3, y3)\n");
    scanf("%d %d %d %d", &x2, &y2, &x3, &y3);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Smooth Lines for Axes and Line");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
