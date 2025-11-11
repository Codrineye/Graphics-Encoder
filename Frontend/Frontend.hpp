#pragma once

#include <GL/freeglut.h>
#include "../Storage/hdr/Data.hpp"

namespace GE {
  class Frontend {
  private:
    bool isDrawing;
    Data* dataStorage;

  public:
    Frontend();

    int getHeight();
    int getWidth();

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