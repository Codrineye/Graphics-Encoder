#include "../hdr/Data.hpp"

namespace GE {
  Data::Data()
  {
    scene.AddShape("Line", 2);
    target_shape = "Line";

    Width = Height = 600;
  }

  void Data::setTargetShape(std::string label)
  {
    const bool can_target = scene.ShapeExists(label);
    if (can_target) {
      target_shape = label;
    } else {
      throwRuntimeError("Unabel to find requested shape");
    }
  }

  void Data::Record_shape(std::string label, int member_count) { scene.AddShape(label, member_count); }
  void Data::Record_point(float x_coord, float y_coord)
  {
    float relative_x = x_coord / Width;
    float relative_y = y_coord / Height;

    scene.AddPoint(target_shape, x_coord, y_coord, relative_x, relative_y);
  }
  void Data::Update_point(float x_coord, float y_coord)
  {
    float relative_x = x_coord / Width;
    float relative_y = y_coord / Height;

    int found_offset;
    Point *last_point = scene.getAtLastPoint(target_shape, found_offset);

    last_point->root_x = x_coord;
    last_point->root_y = y_coord;
    last_point->rel_x = relative_x;
    last_point->rel_y = relative_y;
  }

  int Data::getPointsCount()
  {
    bool found_shape;
    Shape *shape = scene.getTargetShape(target_shape, found_shape);
    if (!found_shape) throwRuntimeError("Invalid shape label recorded in target_shape");

    Point *recorded_points = shape->point;
    int recording_count = 0;
    while(recorded_points != nullptr) {
      recorded_points = recorded_points->next;
      recording_count ++;
    }

    return recording_count / (shape->member_count);
  }

  void Data::update_Height(int new_height) { Height = new_height; }
  void Data::update_Width(int new_width)   { Width = new_width; }

  const int Data::get_Height() const { return Height; }
  const int Data::get_Width()  const { return Width; }

  void Data::throwRuntimeError(std::string message) { throw std::runtime_error(message); }
  float Data::getCoordX(int target_index, int offset)
  {
    int found_point;
    Point *target_point = scene.getPointAtIndex(target_shape, target_index, found_point);
    if (found_point > 0) throwRuntimeError(
      "Trying to access out of memory index " + std::to_string(target_index)
      + " off by " + std::to_string(found_point) + " units."
    );

    while (offset > 0 && target_point->next != nullptr) {
      target_point = target_point->next;
      offset --;
    }
    if (offset > 0) throwRuntimeError(
      "Trying to access out of memory index " + std::to_string(target_index)
      + " off by " + std::to_string(offset) + " units."
    );

    return Width * (target_point->rel_x);
  }

  float Data::getCoordY(int target_index, int offset)
  {
    int found_point;
    Point *target_point = scene.getPointAtIndex(target_shape, target_index, found_point);
    if (found_point > 0) throwRuntimeError(
      "Trying to access out of memory index " + std::to_string(target_index)
      + " off by " + std::to_string(found_point) + " units."
    );

    while (offset > 0 && target_point->next != nullptr) {
      target_point = target_point->next;
      offset --;
    }
    if (offset > 0) throwRuntimeError(
      "Trying to access out of memory index " + std::to_string(target_index)
      + " off by " + std::to_string(offset) + " units."
    );

    return Height * (target_point->rel_y);
  }
}