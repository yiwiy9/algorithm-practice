#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
const double PI = 3.141592653589793;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_i
 * https://twitter.com/e869120/status/1380290146340245505/photo/1
 *
 * ・真ん中決めうち + 偏角ソート
 * ・偏角の求め方：atan2(y, x) * 180 / PI
*/
int main()
{
  int N;
  cin >> N;

  vector<double> X(N), Y(N);
  for (int i=0; i<N; i++) cin >> X[i] >> Y[i];

  double ans = -1;
  for (int i=0; i<N; i++) {
    vector<double> args;
    for (int j=0; j<N; j++) {
      if (j == i) continue;
      double arg = atan2(Y[j]-Y[i], X[j]-X[i]) * 180 / PI;
      args.push_back(arg);
    }

    sort(args.begin(), args.end());
    for (int k=0; k < (int)args.size(); k++) {
      int expect = ((int)args[k] + 180) % 360;
      auto lb_itr = lower_bound(args.begin(), args.end(), expect);

      if (lb_itr != args.end()) {
        double lb_arg = abs(args[k] - *lb_itr);
        if (lb_arg > 180) lb_arg = 360 - lb_arg;
        chmax(ans, lb_arg);
      }
      if (lb_itr != args.begin()) {
        lb_itr--;
        double lb_arg = abs(args[k] - *lb_itr);
        if (lb_arg > 180) lb_arg = 360 - lb_arg;
        chmax(ans, lb_arg);
      }
    }
  }

  cout << fixed << setprecision(8) << ans << endl;
}
