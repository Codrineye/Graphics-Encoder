#include "Data.hpp"

Data::Data() { points.clear(); }
Data::~Data() { points.clear(); }

void Data::addPoint(float x, float y, const std::string &lable)
{
  points.push_back({lable, x, y});
}

void Data::updateCoords(float x, float y)
{
  if(points.empty()) return;
  points.back().x = x;
  points.back().y = y;
}

const int Data::getPointsCount() const { return points.size(); }
const float Data::getCoord_x(int index) const { return points[index].x; }
const float Data::getCoord_y(int index) const { return points[index].y; }
const std::string Data::getLabel(int index) const { return points[index].label; }
const std::vector<Point> &Data::getPoints() const { return points; }
