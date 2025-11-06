#include "Data.hpp"

namespace GE {
  Data::Data() {
    root = nullptr;
  }
  Data::~Data() {
    while(root != nullptr) {
      Node *next = root->next;
      delete root;
      root = next;
    }
  }

  Node *Data::getAtLastPoint()
  {
    Node *point = root;
    while(point->next != nullptr) { point = point->next; }
    // Itterate over to the last point

    return point;
  }

  const Node *Data::getAtIndex(int index, int factor, int offset) const
  {
    // calculate the raw index and return the point
    int raw_index = (index * factor) + offset;
    return getAtIndex(raw_index);
  }

  const Node *Data::getAtIndex(int raw_index) const
  {
    Node *point = root;
    if (raw_index <= 0) { return point; }
    // return the first point if the raw_index is 0 or invalid

    for(int i = raw_index; i > 0; i --) {
      // itterate over the points
      // if we hit the end pre-maturely, break at the end.
      if(point->next == nullptr) break;

      point = point->next;
    }

    // this will always return the corresponding point
    return point;
  }

  void Data::addPoint(float x, float y, const std::string& label)
  {
    Node *point;
    if (root == nullptr) {
      root = new Node;
      point = root;
    } else {
      point = getAtLastPoint();
      point->next = new Node;
      point = point->next;
    }

    point->x = x;
    point->y = y;
    point->label = label;
    point->next = nullptr;
  }

  void Data::updateCoords(float x, float y)
  {
    if (root == nullptr) return;
    Node *point = getAtLastPoint();

    point->x = x;
    point->y = y;
  }

  const int Data::getPointsCount() const
  {
    Node *point = root;
    int counter = 0;
    while (point != nullptr) {
      point = point->next;
      counter += 1;
    }

    return counter;
  }

  const float Data::getCoord_x(int index, int factor, int offset) const
  {
    const Node *point = getAtIndex(index, factor, offset);
    return point->x;
  }
  const float Data::getCoord_y(int index, int factor, int offset) const
  {
    const Node *point = getAtIndex(index, factor, offset);
    return point->y;
  }
  const std::string Data::getLabel(int index, int factor, int offset) const
  {
    const Node *point = getAtIndex(index, factor, offset);
    return point->label;
  }
}
