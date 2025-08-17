#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x0, y0, x1, y1, x, y, m, dx, dy, di;
void display(void)
{
    glBegin(GL_POINTS);
    dx = x1 - x0;
    dy = y1 - y0;
    m = dy / dx;
    if(m < 1)
    {
        di = 2 * dy - dx;
        glVertex2f(x0, y0);
        for(int i = 0; i <= dx; i++)
        {
            if(di < 0)
            {
                x = x0 + 1;
                y = y0;
                glVertex2f(x, y);
                di = di + 2 * dy;
            }
            else if(di >= 0)
            {
                x = x0 + 1;
                y = y0 + 1;
                glVertex2f(x, y);
                di = di + 2 * (dy - dx);
            }
            x0 = x;
            y0 = y;
        }
    }
    else if(m >= 1)
    {
        di = 2 * dx - dy;
        glVertex2f(x0, y0);
        for(int i = 0; i <= dy; i++)
        {
            if(di < 0)
            {
                x = x0;
                y = y0 + 1;
                glVertex2f(x, y);
                di = di + 2 * dx;
            }
            else if(di >= 0)
            {
                x = x0 + 1;
                y = y0 + 1;
                glVertex2f(x, y);
                di = di + 2 * (dx - dy);
            }
            x0 = x;
            y0 = y;
        }
    }
    glEnd();
    glFlush();
}
void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{
    printf("Enter the points:\n");
    printf("(x0, y0) (x1, y1)\n");
    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Tamima Naznin Chy");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
