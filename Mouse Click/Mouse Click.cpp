#include <iostream>
#include <GL/glut.h>
using namespace std;
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0, 0, 0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}
class GLintPoint {
public:
	GLint x, y;
};
const double screenHeight = 480;
void drawDot(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void myMouse(int button, int state, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT);
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		drawDot(x, screenHeight - y);
	}
	else if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
		exit(-1);
	}
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Mouse Click");
	glutDisplayFunc(myDisplay);
	//glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	//glutKeyboardFunc(myKeyboard);
	myInit();
	glutMainLoop();
}