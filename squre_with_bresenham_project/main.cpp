#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1, y1, x2, y2, x3, y3, x4, y4, dx, dy, m, di, x, y;

void bresenham(float x1, float y1, float x2, float y2)
{
    glBegin(GL_POINTS);  // dont remove

    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;
    if(m < 1){
        di = 2 * dy - dx;
        glVertex2f(x1,y1);

        for(int i = 0; i <= dx; i++){
            if(di < 0){
                x = x1 + 1;
                y = y1;
                glVertex2f(x,y);
                di = di + 2 * dy;
            }
            else if(di >= 0){
                x = x1 + 1;
                y = y1 + 1;
                glVertex2f(x,y);
                di = di + 2 * (dy - dx);
            }
            x1 = x;
            y1 = y;
        }
    }
    else if (m >= 1){
        di = 2 * dx - dy;
        glVertex2f(x1,y1);

        for(int i = 0; i <= dy; i++){
            if(di < 0){
                x = x1;
                y = y1 + 1;
                glVertex2f(x,y);
                di = di + 2 * dx;
            }
            else if(di >= 0){
                x = x1 + 1;
                y = y1 + 1;
                glVertex2f(x,y);
                di = di + 2 * (dx - dy);
            }
            x1 = x;
            y1 = y;
        }
    }

    glEnd();  // dont remove
}

void display(void)
{
    bresenham(x1, y1, x2, y2);
    bresenham(x2, y2, x3, y3);
    bresenham(x4, y4, x3, y3);
    bresenham(x1, y1, x4, y4);

    glFlush();  // dont remove

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
    printf("Enter the value of the points\n");
    printf("x1 y1 ");
    scanf("%f %f", &x1, &y1);
    printf("x2 y2 ");
    scanf("%f %f", &x2, &y2);
    printf("x3 y3 ");
    scanf("%f %f", &x3, &y3);
    printf("x4 y4 ");
    scanf("%f %f", &x4, &y4);
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
