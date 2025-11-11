#pragma once

#include <iostream>
#include "Values.hpp"

namespace GE {
  class Data
  {
  private:
    int Height, Width;
    // height and width of the scene
    Values scene;
    std::string target_shape;
  public:
    Data();

    void Record_shape(std::string label, int member_count);
    void Record_point(float x_coord, float y_coord);
    void Update_point(float x_coord, float y_coord);

    void setTargetShape(std::string label);

    void update_Height(int new_height);
    void update_Width(int new_width);

    // throw a runtime error if we're trying to access an out of bounds area.
    void throwRuntimeError(std::string message);

    int getPointsCount();

    const int get_Height() const;
    const int get_Width()  const;

    float getCoordX(int target_point, int offset);
    float getCoordY(int target_point, int offset);
  };
}