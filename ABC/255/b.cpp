#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;
using Point = pair<double, double>;
const double inf = 1 << 30;

bool is_light_up(Point a, Point b, double R)
{
  double dd = (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
  return dd <= R*R;
}

int main()
{
  int N, K;
  cin >> N >> K;

  int light_i;
  vector<int> A(N+1, false);
  for (int j=0; j<K; j++) {
    cin >> light_i;
    A[light_i] = true;
  }

  vector<Point> P(N+1);
  double x, y;
  for (int i=1; i<=N; i++) {
    cin >> x >> y;
    P[i] = {x, y};
  }

  double left = 0, right = inf;
  while (right - left > 0.000001) {
    double mid = (left + right) / 2;

    set<int> light_set;
    for (int i=1; i<=N; i++) {
      if (A[i] == false) continue;
      light_set.insert(i);

      for (int j=1; j<=N; j++) {
        if (is_light_up(P[i], P[j], mid)) {
          light_set.insert(j);
        }
      }
    }

    if (light_set.size() == N) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << fixed << setprecision(7) << right << endl;
}
