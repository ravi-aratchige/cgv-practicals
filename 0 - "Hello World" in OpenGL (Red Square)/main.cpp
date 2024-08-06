#include <GL/glut.h>  // GLUT, includes glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   // Set background color to black and opaque
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   
   // Clear the color buffer
   glClear(GL_COLOR_BUFFER_BIT);

   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      // Set color of square to red
      glColor3f(1.0f, 0.0f, 0.0f);

      // Define locations of the four vertices of the square (using x,y coordinates)
      glVertex2f(-0.5f, -0.5f);
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();

   // Render now
   glFlush();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   // Initialize GLUT
   glutInit(&argc, argv);

   // Create a window with the given title
   glutCreateWindow("OpenGL Setup Test");

   // Set the window's initial width & height
   glutInitWindowSize(320, 320);

   // Position the window's initial top-left corner
   glutInitWindowPosition(50, 50);

   // Register display callback handler for window re-paint
   glutDisplayFunc(display);

   // Enter the infinitely event-processing loop
   glutMainLoop();
   return 0;
}

