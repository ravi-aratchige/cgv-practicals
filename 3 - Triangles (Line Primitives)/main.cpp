#include <GL/glut.h>
using namespace std;

// Handler for window-repaint event.
// Call back when the window first appears and whenever the window needs to be re-painted.
void display() {
    // Set background color to black and oqaque
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the triangle
    glBegin(GL_TRIANGLES);
        // Color of triangle
        glColor3f(1.0f, 0.0f, 0.0f);

        // First vertex of the triangle
        glVertex3f(-0.5f, -0.5f, 0.0f);

        // First vertex of the triangle
        glVertex3f(0.0f, 0.5f, 0.0f);

        // First vertex of the triangle
        glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();

    // Render now
    glFlush();
}

void init() {
    // Set width and height of window
    glutInitWindowSize(320, 320);

    // Set position (of top-left corner) of window
    glutInitWindowPosition(50, 50);
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // Create window titled "OpenGL 2D Primitives"
    glutCreateWindow("OpenGL 2D Primitives");

    // Set properties of window
    init();

    // Register the display callback handler for window repaint
    glutDisplayFunc(display);

    // Start the infinite event-processing loop
    glutMainLoop();
    return 0;
}