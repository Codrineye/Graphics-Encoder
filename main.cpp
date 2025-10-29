#include "Frontend/Frontend.hpp"

int main(int argc, char** argv) {
  GE::Frontend render;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  const int width = render.getWidth();
  const int height = render.getHeight();

  glutInitWindowSize(width, height);
  glutCreateWindow("Mouse Line Drawing");
  glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

  glutDisplayFunc(GE::Frontend::displayWrapper);
  glutReshapeFunc(GE::Frontend::reshapeWrapper);
  glutMouseFunc(GE::Frontend::onMouseWrapper);
  glutMotionFunc(GE::Frontend::onMotionWrapper);

  glutMainLoop();

  return 0;
}
