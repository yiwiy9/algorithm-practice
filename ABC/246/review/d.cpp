#include <iostream>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

long long f(long long a, long long b) {
  return a*a*a + a*a*b + a*b*b + b*b*b;
}

/**
 * https://atcoder.jp/contests/abc246/tasks/abc246_d
 *
 * a^3 に注目する。
 * aは非負整数 && a^3 <= 10^18 (入出力例３より、Xmax=10^18)
 * よって、a <= 10^6
 *
 * あとは、aを0 ~ 10^6 でループして、各々で最小のbを求めていけば良い
 * そこから、N以上の最小のf(a,b)を求めればよい
 */
int main()
{
  long long N;
  cin >> N;

  long long ans = INF;
  for (long long a=0; a<=1000000; a++) {
    long long left = -1, right = 1000000;
    while (right - left > 1) {
      long long mid = (left + right) / 2;
      if (N <= f(a, mid)) right = mid;
      else left = mid;
    }
    chmin(ans, f(a, right));
  }

  cout << ans << endl;
}
