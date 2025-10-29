#pragma once

#include <GL/freeglut.h>
#include "../Data/Data.hpp"

namespace GE {
  class Frontend {
  private:
    int Width, Height;
    bool isDrawing;
    Data* scene;

  public:
    Frontend();
    int getWidth();
    int getHeight();

    void display();
    void reshape(int width, int height);
    void onMouse(int button, int state, int x, int y);
    void onMotion(int x, int y);

    static void displayWrapper();
    static void reshapeWrapper(int width, int height);
    static void onMouseWrapper(int button, int state, int x, int y);
    static void onMotionWrapper(int x, int y);
  };
}