#include <iostream>
#include <string>

using namespace std;

/*
 https://atcoder.jp/contests/abc238/tasks/abc238_d

 1. x AND y = a
 2. x + y = s

 2. <=> (x XOR y) + 2*(x AND y) = s <=> x XOR y = s - 2a
 (x XOR y) >= 0 より、s >= 2a

 また、1., 2. を AND演算する
 => (x AND y) AND (x XOR y) = a & (s - 2a)
 => 0 = a & (s - 2a)
*/
int main()
{
  long long T;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    long long a, s;
    cin >> a >> s;

    string ans = "No";
    if (s >= 2*a) {
      long long b = s - 2*a;
      if ((a & b) == 0) {
        ans = "Yes";
      }
    }

    cout << ans << endl;
  }
}
