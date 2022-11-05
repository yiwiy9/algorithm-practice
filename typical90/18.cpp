#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Point = pair<double, double>;
const double PI = 3.141592653589793;

double T, L, X, Y;

Point calc_E8_pos(double min)
{
  double radian = (3 * PI / 2) - (min / T * 2 * PI);
  double y = (L/2) * cos(radian);
  double z = (L/2) * sin(radian) + L/2;
  return {y, z};
}

double calc_degree(Point E8_pos)
{
  double horizontal = sqrt(X*X + (Y-E8_pos.first)*(Y-E8_pos.first));
  return 180.0 / PI * atan2(E8_pos.second, horizontal);
}

int main() {
  int Q;
  cin >> T >> L >> X >> Y >> Q;

  double E;
  for (int i=0; i<Q; i++) {
    cin >> E;
    auto E8_pos = calc_E8_pos(E);
    cout << fixed << setprecision(7) << calc_degree(E8_pos) << endl;
  }
}
