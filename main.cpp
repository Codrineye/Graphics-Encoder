#include "Frontend/Frontend.hpp"

int main(int argc, char** argv) {
  Frontend render;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  const int width = render.getWidth();
  const int height = render.getHeight();

  glutInitWindowSize(width, height);
  glutCreateWindow("Mouse Line Drawing");
  glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

  glutDisplayFunc(Frontend::displayWrapper);
  glutReshapeFunc(Frontend::reshapeWrapper);
  glutMouseFunc(Frontend::onMouseWrapper);
  glutMotionFunc(Frontend::onMotionWrapper);

  glutMainLoop();

  return 0;
}
