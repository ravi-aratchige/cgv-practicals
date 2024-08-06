#include <GL/glut.h>
using namespace std;

// Boolean to store state of teapot
bool solidState = true;

// Handler for window-repaint event.
// Call back when the window first appears and whenever the window needs to be re-painted
void display() {
    // Set background color to black and opaque
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw wire teapot primitive
    if (solidState) glutSolidTeapot(0.5);
    else glutWireTeapot(0.5);

    // Render now
    glFlush();
}

// Handle keypress actions to change primitive type or exit the program
void keypress(unsigned char key, int x, int y) {
    // Set primitive to solid ('s' ley)
    if (key == 's' || key == 'S' || key == 83) solidState = true;

    // Set primitive to wire ('w' key)
    else if (key == 'w' || key == 'W' || key == 87) solidState = false;

    // Exit the program ('q' key)
    else if (key == 'q' || key == 'Q' || key == 81) exit(0);
    glutPostRedisplay();
}

// Initialize the window's dimensions and position
void init() {
    // Set the window's size (width and height)
    glutInitWindowSize(320, 320);

    // Set the position of the window (top-left corner)
    glutInitWindowPosition(50, 50);
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // Create a window titled "OpenGL Keyboard Actions"
    glutCreateWindow("OpenGL Keyboard Actions");

    // Initialize the window's properties
    init();

    // Register the display callback handler for window repaint
    glutDisplayFunc(display);

    // Register the callback handler for keypress actions
    glutKeyboardFunc(keypress);

    // Start the infinite event-processing loop
    glutMainLoop();

    return 0;
}