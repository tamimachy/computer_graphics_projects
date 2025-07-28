#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

float R, Xc,Yc,x,y,P, i;
void display(void)
{


    glBegin(GL_POINTS);
    x = 0;
    y = R;
    P = 1 - R;
    for(i=x; i<=y; i++){
    glVertex2f(Xc+x, Yc+y);
    glVertex2f(Xc+y, Yc+x);
    glVertex2f(Xc-y, Yc+x);
    glVertex2f(Xc-x, Yc+y);
    glVertex2f(Xc-x, Yc-y);
    glVertex2f(Xc-y, Yc-x);
    glVertex2f(Xc+y, Yc-x);
    glVertex2f(Xc+x, Yc-y);
        if(P<0){
            x++;
            P = P + (2*x)+3;
        }else{
            x++;
            y--;
            P = P+(2*(x-y))+5;
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
    printf("Enter the value of circle radius:");
    cin>> R;
    printf("Enter the co-ordinates of Center (Xc,Yc):");
    cin >> Xc >> Yc;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("___");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

return 0;
}
