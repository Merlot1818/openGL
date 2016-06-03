#include <GLUT/GLUT.h>

GLsizei winWidth = 600, winHeight = 500;    // Initial display window size.
GLint xRaster = 25, yRaster = 150;          // Initialize raster position. 

GLubyte label[36] = {'J', 'a', 'n',   'F', 'e', 'b',   'M', 'a', 'r', 
                      'A', 'p', 'r',   'M', 'a', 'y',   'J', 'u', 'n', 
                      'J', 'u', 'l',   'A', 'u', 'g',   'S', 'e', 'p', 
                      'O', 'c', 't',   'N', 'o', 'v',   'D', 'e', 'c'}; 

GLint dataValue [12] = {420, 342, 324, 310, 262, 185, 
                        190, 196, 217, 240, 312, 438};

void init (void)
{
    glClearColor (1.0, 1.0, 0.0, 0.2);    // White display window.
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 600.0, 0.0, 500.0);
}

void winReshapeFcn (GLint newWidth, GLint newHeight)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, GLdouble (newWidth), 0.0, GLdouble (newHeight));
    glClear (GL_COLOR_BUFFER_BIT);   
}


void barChart (void)
{
   GLint month, k;

   glClear (GL_COLOR_BUFFER_BIT); //  Clear display window.

   glColor3f (1.0, 0.0, 0.0);     //  Set bar color to red.
   for (k = 0; k < 12; k++){
      glRecti (20 + k*50, 165, 40 + k*50, dataValue [k]);
   }

   glColor3f (0.0, 0.0, 0.0);           //  Set text color to black.
  xRaster = 20;                   //  Display chart labels.
  for (month = 0; month < 12; month++) {
      glRasterPos2i (xRaster, yRaster);
      for (k = 3*month; k < 3*month + 3; k++)
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, 
                                              label[k]);
      xRaster += 50;
   }
   glFlush ( );
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Line Chart Data Plot");
    init();
    glutDisplayFunc(barChart);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
    return 0;
}
