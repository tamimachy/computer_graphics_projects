#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x0, y0, x1, y1, m, dx, dy, absM, x, y;

void display(void)
{
    glBegin(GL_POINTS);

    dx = x1 - x0;
    dy = y1 - y0;
    m = dy / dx;

    absM = abs(m);

    if(absM <= 1)
    {
        for(int i = x0; i <= x1; i++)
        {
            x = x + 1;
            y = y + m;
            glVertex2f(x,y);
        }
    }
    else if(absM > 1)
    {
        for(int i = y0; i <= y1; i++)
        {
            y = y + 1;
            x = x + (1/m);
            glVertex2f(x,y);
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
    glutCreateWindow("Sayem Mustafiz");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
