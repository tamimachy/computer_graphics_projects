#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1, y1, x2, y2, x, y, m, dx, dy, di, R, Xc, Yc, P;

void display(void)
{
    glBegin(GL_POINTS);  // dont remove




    x = 0;
    y = R;
    P = 1 - R;
    for(int i = x; i <= y; i++)
    {
        glVertex2f(Xc + x, Yc + y);
        glVertex2f(Xc + y, Yc + x);
        glVertex2f(Xc - y, Yc + x);
        glVertex2f(Xc - x, Yc + y);
        glVertex2f(Xc - x, Yc - y);
        glVertex2f(Xc - y, Yc - x);
        glVertex2f(Xc + y, Yc - x);
        glVertex2f(Xc + x, Yc - y);

        if(P < 0){
            x++;
            P = P + (2 * x) + 3;
        }
        else
        {
            x++;
            y--;
            P = P + (2 * (x - y)) + 5;
        }
    }




    glEnd();  // dont remove
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
    printf("Enter the value of the radius(R) and center(Xc, Yc)\n");
    printf("R Xc Yc\n");
    scanf("%f %f %f", &R, &Xc, &Yc);
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
