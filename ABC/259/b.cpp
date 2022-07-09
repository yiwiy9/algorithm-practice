#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const double PI = 3.141592653589793;

int main()
{
  double a, b, d;
  cin >> a >> b >> d;

  double d_radian = d * PI / 180;
  double x = a * cos(d_radian) - b * sin(d_radian);
  double y = a * sin(d_radian) + b * cos(d_radian);

  cout << fixed << setprecision(7) << x << ' ';
  cout << fixed << setprecision(7) << y << endl;
}
