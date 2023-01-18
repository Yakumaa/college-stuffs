#include <GL/glut.h>
#include <cmath>

const double PI = 3.1415;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  for(int i = 0; i < 5; i++) {
    double angle = i * 2 * PI / 5;
    glVertex2f(cos(angle), sin(angle));
  }
  glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Pentagon");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
