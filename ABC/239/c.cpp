#include <iostream>
#include <vector>
using namespace std;

using Point = pair<long long, long long>;

vector<Point> get_points(long long x, long long y)
{
  vector<Point> points(8);
  points[0].first  = x + 1;
  points[0].second = y + 2;
  points[1].first  = x + 2;
  points[1].second = y + 1;
  points[2].first  = x + 2;
  points[2].second = y - 1;
  points[3].first  = x + 1;
  points[3].second = y - 2;
  points[4].first  = x - 1;
  points[4].second = y - 2;
  points[5].first  = x - 2;
  points[5].second = y - 1;
  points[6].first  = x - 2;
  points[6].second = y + 1;
  points[7].first  = x - 1;
  points[7].second = y + 2;

  return points;
}

int main()
{
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  vector<Point> points1 = get_points(x1, y1);
  vector<Point> points2 = get_points(x2, y2);

  bool exist = false;

  for (Point p1: points1) {
    for (Point p2: points2) {
        if (p1 == p2) {
          exist = true;
        }
    }
  }

  if (exist) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
