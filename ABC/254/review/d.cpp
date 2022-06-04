#include <iostream>
using namespace std;

/**
 * https://atcoder.jp/contests/abc254/tasks/abc254_d
 *
 * i = x^2 * k
 * j = y^2 * k
 * => i * j = (x*y*k)^2
 * i の約数のうち、奇数個の部分の積が
 * j のそれに一致していればよい
 */
int main()
{
  long long N;
  cin >> N;

  long long res = 0;
  for (long long i=1; i<=N; i++) {
    long long k = i;

    for (long long d=2; d*d<=N; d++) {

      while (k%(d*d)==0) k /= d*d;
    }

    for (long long d=1; k*d*d<=N; d++) res++;
  }

  cout << res << endl;
}
