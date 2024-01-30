#include <GL/glut.h>
#include <iostream>

int x1, yi, x2, y2;

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void draw_line(int x1, int x2, int yi, int y2) {
    int x, y, dx, dy,i, p, step, incx, incy;
    dx = abs(x2 - x1);
    dy = abs(y2 - yi);  

    incx = ( x2 > x1 ) ? 1 : -1;
    incy = (y2 > yi) ? 1 : -1;

    step = (dx > dy) ? dx : dy;

    x = x1;
    y = yi;
    draw_pixel(x, y);
    p = 2 * dy - dx;

    for ( i=0; i<step; i++){
        if ( p < 0){
            x += incx;
            p += 2 * dy;
        } else {
            x += incx;
            y += incy;
            p += 2 * (dy - dx);
        }
        draw_pixel(x, y);
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
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

    glColor3f(1.0, 1.0, 1.0); // Set color to white
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
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
