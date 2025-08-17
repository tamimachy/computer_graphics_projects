#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1, y1, x2, y2, x3, y3;
int n;

void triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_LINE_LOOP);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}

void SG(float x1, float y1, float x2, float y2, float x3, float y3, int n)
{
    if(n>0)
    {
        float x12 = (x1 + x2)/2;
        float y12 = (y1 + y2)/2;
        float x13 = (x1 + x3)/2;
        float y13 = (y1 + y3)/2;
        float x23 = (x2 + x3)/2;
        float y23 = (y2 + y3)/2;
        SG(x1, y1, x12, y12, x13, y13, n-1);
        SG(x12, y12, x2, y2, x23, y23, n-1);
        SG(x13, y13, x23, y23, x3, y3, n-1);
    }
    else
    {
        triangle(x1, y1, x2, y2, x3, y3);
    }
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    SG(x1, y1, x2, y2, x3, y3, n);

    glFlush();

}

void init(void)
{

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    printf("Enter three vertices of the triangle\n");
    printf("(x1, y1), (x2, y2), (x3,y3)\n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Enter the order: ");
    scanf("%d", &n);
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
