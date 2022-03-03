#include <iostream>
using namespace std;
const int MOD = 998244353;
const int modinv2 = 499122177; // my-template/gcd.cpp modinv()より


long long calc_sigma_by_digits(long long x) {
  long long ans = x%MOD;

  ans *= (x+1)%MOD;
  ans %= MOD;

  ans *= modinv2;
  ans %= MOD;

  return ans;
}

/*
 https://atcoder.jp/contests/abc238/tasks/abc238_c

 f(1)=1, f(2)=2, ... f(9)=9
 f(10)=1, f(11)=2, ... f(99)=90
 f(100)=1, f(101)=2, ... f(999)=900

 dを桁数とすると、
 f(x) = x - (10^(d-1) - 1)

 各桁ごとに、y = min(10^d - 1, x) としたときに、1+2+...+f(y) の総和を求める
 => f(y) * (f(y) + 1) / 2

 あとは、オーバーフローするので都度modを取る
*/
int main()
{
  long long N;
  cin >> N;

  long long ans = 0;
  long long pow10 = 10;
  for (int d = 1; d <= 18; d++)
  {
    long long before_pow10 = pow10/10;
    long long y = min(pow10 - 1, N);

    ans += calc_sigma_by_digits(y - before_pow10 + 1);
    ans %= MOD;

    pow10 *= 10;

    if (y == N) break;
  }

  cout << ans << endl;
}
