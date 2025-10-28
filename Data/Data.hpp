#include <vector>
#include <string>

struct Point {
  std::string label;
  float x, y;
};

class Data {
private:
  std::vector<Point> points;
public:
  Data();
  ~Data();
  void addPoint(float x, float y, const std::string& label);
  void updateCoords(float x, float y);

  const int getPointsCount() const;
  const float getCoord_x(int index) const;
  const float getCoord_y(int index) const;
  const std::string getLabel(int index) const;
  const std::vector<Point>& getPoints() const;
};
