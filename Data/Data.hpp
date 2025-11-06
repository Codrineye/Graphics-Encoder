#pragma once

#include <string>

// project namespace Graphics Encoder combined to GE
namespace GE {
  struct Node {
    std::string label;
    float x, y;

    Node *next;
  };

  class Data {
  private:
    Node *root;
  public:
    Data();
    ~Data();
    void addPoint(float x, float y, const std::string& label = "label");
    void updateCoords(float x, float y);

    Node *getAtLastPoint();
    const Node *getAtIndex(int index, int factor, int offset) const;
    const Node *getAtIndex(int raw_index) const;

    const int getPointsCount() const;

    const float getCoord_x(int index, int factor, int offset) const;
    const float getCoord_y(int index, int factor, int offset) const;
    const std::string getLabel(int index, int factor, int offset) const;
  };

}