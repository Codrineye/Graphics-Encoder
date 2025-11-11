#include "../hdr/Values.hpp"

namespace GE {
  Values::Values() : root(nullptr) { }
  Values::~Values()
  {
    while (root != nullptr)
    {
      Point* points = root->point;
      while (points != nullptr)
      {
        Point* point = points;
        points = point->next;
        delete point;
      }

      Shape* shape = root;
      root = root->next;
      delete shape;
    }
  }
  Shape* Values::getTargetShape(const std::string label, bool& found_shape)
  {
    if (root == nullptr) {
      found_shape = false;
      return nullptr;
    }

    Shape* target = root;
    while (target->next != nullptr && target->label != label) { target = target->next; }

    found_shape = (target->label == label);
    return target;
  }

  bool Values::ShapeExists(const std::string label)
  {
    bool found_shape;
    Shape *target = getTargetShape(label, found_shape);

    return found_shape;
  }


  void Values::AddShape(const std::string label, const int members)
  {
    if (root == nullptr) {
      root = new Shape {members, label, nullptr, nullptr};
      return;
    }

    bool found_shape = false;
    Shape* target = getTargetShape(label, found_shape);

    if (!found_shape) {
      target->next = new Shape {members, label, nullptr, nullptr};
      return;
    }

    target->label = label;
    target->member_count = members;
  }

  Point* Values::getAtLastPoint(const std::string label, int& found_offset)
  {
    bool found_shape;
    Shape* target_shape = getTargetShape(label, found_shape);

    if (!found_shape || target_shape->point == nullptr) {
      found_offset = -1;
      return nullptr;
    }

    const int modulus = target_shape->member_count;
    Point* points = target_shape->point;

    while (points->next != nullptr) {
      found_offset = (found_offset + 1) % modulus;
      points = points->next;
    }

    return points;
  }

  Point* Values::getPointAtIndex(const std::string label, const int index, int& found_offset)
  {
    bool found_shape;
    Shape* target_shape = getTargetShape(label, found_shape);

    if (!found_shape) {
      found_offset = -1;
      return nullptr;
    }

    int raw_index = index * (target_shape->member_count);
    Point* points = target_shape->point;
    while (raw_index > 0) {
      if (points->next == nullptr) break;

      points = points->next;
      raw_index--;
    }

    found_offset = raw_index / (target_shape->member_count);
    return points;
  }

  void Values::AddPoint(const std::string label, float x_coord, float y_coord, float relative_x, float relative_y)
  {
    bool found_shape;
    Shape* shape = getTargetShape(label, found_shape);

    if (!found_shape) {
      throw std::runtime_error("Shape '" + label + "' not found while adding point.");
    }

    Point* new_point = new Point{ x_coord, y_coord, relative_x, relative_y, nullptr };

    if (shape->point == nullptr) {
      shape->point = new_point;
      return;
    }

    Point* last_point = shape->point;
    while (last_point->next) last_point = last_point->next;
    last_point->next = new_point;
  }
}