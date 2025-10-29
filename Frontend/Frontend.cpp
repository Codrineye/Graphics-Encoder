#include "Frontend.hpp"

namespace GE {
  static Frontend* gl_Instance;
  Frontend::Frontend() {
    gl_Instance = this;
    Width = 600;
    Height = 600;
    isDrawing = false;

    scene = new Data;
  }


  int Frontend::getWidth() { return this->Width; }
  int Frontend::getHeight() { return this->Height; }

  void Frontend::reshape(int width, int height)
  {
    Width = width;
    Height = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
  }

  void Frontend::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    const int points_count = scene->getPointsCount();

    for (size_t i = 0; i + 1 < points_count; i += 2) {
      glColor3f(1.0f, 1.0f, 1.0f);
      glLineWidth(3.0f);
      glBegin(GL_LINES);
      glVertex2f(Width * scene->getCoord_x(i), Height * scene->getCoord_y(i));
      glVertex2f(Width * scene->getCoord_x(i + 1), Height * scene->getCoord_y(i + 1));
      glEnd();
    }

    glFlush();
  }

  void Frontend::onMouse(int button, int state, int x, int y) {
    if (button != GLUT_LEFT_BUTTON) return;
    float fx = static_cast<float>(x) / Width;
    float fy = static_cast<float>(Height - y) / Height;

    if (state == GLUT_DOWN) {
      isDrawing = true;
      scene->addPoint(fx, fy, "line"); // start point
      scene->addPoint(fx, fy, "line"); // end point
    }
    else if (state == GLUT_UP) {
      isDrawing = false;
      glutPostRedisplay();
    }
  }

  void Frontend::onMotion(int x, int y) {
    if (!isDrawing || scene->getPointsCount() == 0) return;
    scene->updateCoords(static_cast<float>(x) / Width, static_cast<float>(Height - y) / Height);
    glutPostRedisplay();
  }

  void Frontend::reshapeWrapper(int width, int height) { gl_Instance->reshape(width, height); }
  void Frontend::displayWrapper() { gl_Instance->display(); }
  void Frontend::onMouseWrapper(int button, int state, int x, int y) { gl_Instance->onMouse(button, state, x, y); }
  void Frontend::onMotionWrapper(int x, int y) { gl_Instance->onMotion(x, y); }
}