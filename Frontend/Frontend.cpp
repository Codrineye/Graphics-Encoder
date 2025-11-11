#include "Frontend.hpp"

namespace GE {
  static Frontend* gl_Instance;
  Frontend::Frontend() {
    gl_Instance = this;
    isDrawing = false;

    dataStorage = new Data;
  }

  int Frontend::getHeight() { return dataStorage->get_Height(); }
  int Frontend::getWidth() { return dataStorage->get_Width(); }
  void Frontend::reshape(int width, int height)
  {
    dataStorage->update_Width(width);
    dataStorage->update_Height(height);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
  }

  void Frontend::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    const int points_count = dataStorage->getPointsCount();

    for (size_t i = 0; i < points_count; i ++) {
      glColor3f(1.0f, 1.0f, 1.0f);
      glLineWidth(3.0f);
      glBegin(GL_LINES);
      glVertex2f(dataStorage->getCoordX(i, 0), dataStorage->getCoordY(i, 0));
      glVertex2f(dataStorage->getCoordX(i, 1), dataStorage->getCoordY(i, 1));
      glEnd();
    }

    glFlush();
  }

  void Frontend::onMouse(int button, int state, int x, int y) {
    if (button != GLUT_LEFT_BUTTON) return;
    float fx = static_cast<float>(x);

    const int Height = dataStorage->get_Height();
    float fy = static_cast<float>(Height - y);

    if (state == GLUT_DOWN) {
      isDrawing = true;
      dataStorage->Record_point(fx, fy); // start point
      dataStorage->Record_point(fx, fy); // end point
    }
    else if (state == GLUT_UP) {
      isDrawing = false;
      glutPostRedisplay();
    }
  }

  void Frontend::onMotion(int x, int y) {
    if (!isDrawing || dataStorage->getPointsCount() == 0) return;
    const int Height = dataStorage->get_Height();
    dataStorage->Update_point(static_cast<float>(x), static_cast<float>(Height - y));
    glutPostRedisplay();
  }

  void Frontend::reshapeWrapper(int width, int height) { gl_Instance->reshape(width, height); }
  void Frontend::displayWrapper() { gl_Instance->display(); }
  void Frontend::onMouseWrapper(int button, int state, int x, int y) { gl_Instance->onMouse(button, state, x, y); }
  void Frontend::onMotionWrapper(int x, int y) { gl_Instance->onMotion(x, y); }
}