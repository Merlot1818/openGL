//
//  main.cpp
//  GlutDevDemo
//
//  Created by Jeff on 11/9/15.
//  Copyright (c) 2015 Jeff. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>

void display()
{
    // glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);//GL_POINTS,GL_POLYGON
    
    /**
     * OpenGL 画点函数
     */
    //1.打点
    glBegin(GL_POINTS);
    
    // glVertex2f(-0.5, -0.5);
    // glVertex2f(-0.5, 0.5);
    // glVertex2f(0.5, 0.5);
    // glVertex2f(0.5, -0.5);

    //2.矩阵形式
    int point1 [] = {50,100};
    int point2 [] = {75,150};
    int point3 [] = {100,200}; 
    glVertex2iv(point1);
    glVertex2iv(point2);
    glVertex2iv(point3);

    // glColor3f(1.0,0.0,0.0);
    // glVertex3f(-1.0,0.0,0.0);
    // glColor3f(0.0,1.0,0.0);
    // glVertex3f(0.0,1.0,0.0);
    // glColor3f(0.0,0.0,1.0);
    // glVertex3f(1.0,0.0,0.0);
    
    glEnd();
    glFlush();
}
void init(){
    glClearColor(1.0,0.0,0.0,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Xcode Glut Demo");
    // init();
    glutDisplayFunc(display);
    glutMainLoop();
}

