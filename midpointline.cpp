#include <GL/glut.h>
#include <iostream>

int x1, yi, x2, y2;

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int x2, int yi, int y2) {
    int x, y, dx, dy,i, d, dd, step, incx, incy;

    dx = abs(x2 - x1);
    dy = abs(y2 - yi);  

    incx = ( dx > 0 ) ? 1 : -1;
    std::cout << "incx: " << incx << std::endl;
    incy = (dy > 0) ? 1 : -1;

    step = (dx > dy) ? dx : dy;

    x = x1;
    y = yi;

    draw_pixel(x, y);

    d = 2 * dy - dx;
    dd = 2 * (dy - dx);

    for ( i=0; i<step; i++){
        if ( d < 0){
            d += 2 * dy;
            x += incx;
        } else {
            d += dd;
            x += incx;
            y += incy;
        }
        draw_pixel(x, y);
        std::cout << "x: " << x << ", y: " << y << std::endl;
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
    draw_line(x1, x2, yi, y2);

    glFlush();
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc, char **argv) {
    printf("Enter (x1, yi, x2, y2)\n");
    scanf("%d %d %d %d", &x1, &yi, &x2, &y2);

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