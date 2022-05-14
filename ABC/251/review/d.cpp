#include <iostream>
#include <cmath>
using namespace std;

/**
 * https://atcoder.jp/contests/abc251/tasks/abc251_d
 * https://atcoder.jp/contests/abc251/editorial/3958
 * 一般に、1桁以上d桁以下のp進表記を用いると p^d − 1 以下のすべての非負整数を表現することができます。
 * 例えば10進法では、10^4 − 1 =9999 以下の非負整数は4桁以下の10進表記で表すことができます。
 *
 * よって、p^3 = W = 10^6 を解けば良い（3つまで選ぶから）
 * => p = 10^2
 */
int main()
{
  int p = 100;
  cout << (p-1)*3 << endl;
  for (int j=0; j<3; j++) {
    for (int i=1; i<p; i++) {
      cout << i * pow(p, j) << ' ';
    }
  }
  cout << endl;
}
