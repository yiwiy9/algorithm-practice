#include <iostream>
using namespace std;


// a と b の最大公約数を返す関数
// Greatest common divisor
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

// a と b の最小公倍数を返す関数
// Least common multiple
long long LCM(long long a, long long b) {
  return a * b / GCD(a, b);
}

// https://qiita.com/drken/items/b97ff231e43bce50199a
// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
      x = 1;
      y = 0;
      return a;
  }
  long long d = extGCD(b, a%b, y, x);
  y -= a / b * x;
  return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK)
// c++の場合、負の数の余りが負になるので、割る数を足して正にする
inline long long mod(long long a, long long m) {
  return (a % m + m) % m;
}

// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
// https://drken1215.hatenablog.com/entry/2018/06/08/210000
// 逆元計算 (ここでは a と m が互いに素であることが必要)
// a*x ≡ 1 (mod m) => a*x - 1 = m*y => extGCD()を使う
long long modinv(long long a, long long m) {
  long long x, y;
  extGCD(a, m, x, y);
  return mod(x, m);
}




int main() {
  long long a = 42;
  long long b = 105;

  cout << "GCD: " << GCD(a, b) << endl;
  cout << "LCM: " << LCM(a, b) << endl;

  long long x;
  long long y;
  extGCD(a, b, x, y);
  cout << "extGCD: " << x << ", " << y << endl;

  cout << "modinv: " << modinv(2, 998244353) << endl;
}
