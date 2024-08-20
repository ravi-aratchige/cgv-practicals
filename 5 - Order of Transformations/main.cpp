#include <GL/glut.h>
using namespace std;

bool toggleOrder = false;

void display() {
    // Set the background color to black and opaque
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Apply transformations
    glMatrixMode(GL_MODELVIEW);  // Set the model-view matrix
    glLoadIdentity();            // Reset the model-view matrix

    // ----------------------------------------------------

    // TRANSFORMATIONS

    if (toggleOrder) {
        // Transformation Order 1: Translate -> Rotate -> Scale

        // Translate the object by (0.5, 0.0, 0.0)
        glTranslatef(0.5f, 0.0f, 0.0f);

        // Rotate the object 45 degrees around the y-axis
        glRotatef(45.0f, 0.0f, 1.0f, 0.0f);

        // Scale the object by 0.75 on all axes
        glScalef(0.75f, 0.75f, 0.75f);
    } else {
        // Transformation Order 2: Rotate -> Scale -> Translate

        // Rotate the object 45 degrees around the y-axis
        glRotatef(45.0f, 0.0f, 1.0f, 0.0f);

        // Scale the object by 0.75 on all axes
        glScalef(0.75f, 0.75f, 0.75f);

        // Translate the object by (0.5, 0.0, 0.0)
        glTranslatef(0.5f, 0.0f, 0.0f);
    }

    // ----------------------------------------------------

    // Set color of primitive to be drawn
    glColor3f(0.0f, 0.75f, 0.0f);

    // Draw an OpenGL 3D primitive
    glutWireTeapot(0.5);

    // Render now
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'c' || key == 'C') {
        toggleOrder = !toggleOrder;  // Toggle transformation order
        glutPostRedisplay();         // Request display update
    }
}

// Initialize dimensions and position of window used to display graphics
void init() {
    // Set the window's initial width and height
    glutInitWindowSize(320, 320);

    // Set the window's initial position (position of top-left corner)
    glutInitWindowPosition(50, 50);
}

int main(int argc, char **argv) {
    // Initialize GLUT (OpenGL Utility Toolkit)
    glutInit(&argc, argv);

    // Create a window titled "OpenGL Primitives"
    glutCreateWindow("OpenGL Primitives");

    // Initialize window dimensions and position
    init();

    // Register the display callback handler for window repaint
    glutDisplayFunc(display);

    // Register the keyboard callback handler for key presses
    glutKeyboardFunc(handleKeypress);

    // Start the infinite event-processing loop
    glutMainLoop();

    return 0;
}