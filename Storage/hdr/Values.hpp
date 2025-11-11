#pragma once

#include <string>
#include <stdexcept>

namespace GE {
  struct Point{
    float root_x, root_y; // root values of x and y
    float rel_x, rel_y;   // relative values of x and y

    Point *next; // point to the next point
  };

  struct Shape {
    int member_count;  // number of points to create this shape
    std::string label; // label for the shape

    Point *point; // Point value, because its shape holds its own points.
    Shape *next;  // point to the next shape
  };
  class Values {
  private:
    Shape *root;
  public:
    Values();
    ~Values();

    void AddShape(const std::string label, const int members);
    void AddPoint(const std::string label, float x_coord, float y_coord, float relative_x, float relative_y);

    bool ShapeExists(const std::string label);

    /*
     * Return the shape with the label <input label> or the last shape in the list
     * found shape returns true if we found a shape, or false if we didn't
    */
    Shape *getTargetShape(const std::string label, bool &found_shape);
    /*
     * Return the last point in the list of points.
     * found_offset contains the value current edge in the shape
     * (eg, a triangle with only 2 points would have a found_offset of 1 instead of 2)
    */
    Point *getAtLastPoint(const std::string label, int &found_offset);

    /*
     * Returns the point at the specified index in the list of points.
     * found_offset has the number of shapes we're off by.
     * (eg, if we have 3 triangles and request triangle 6, found_offset would be 3 instead of 0)
    */
    Point *getPointAtIndex(const std::string label, const int index, int &found_offset);
  };
}

