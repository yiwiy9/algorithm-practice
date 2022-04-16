#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.141592653589793;
const double INF = 1 << 30;

double A, B, C;

bool P(double t)
{
  double res = A*t + B*sin(C*t*PI);
  return res >= 100;
}

// sin関数は周期的（複数の解が存在する）だが、二分探索を使えばそのうちの一つを求められる
int main()
{
  cin >> A >> B >> C;

  double left = 0, right = INF;
  while (right - left > 0.0000001) {
    double mid = (left + right) / 2;

    if (P(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << fixed << setprecision(7) << right << endl;
}
