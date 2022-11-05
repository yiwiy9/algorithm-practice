#include <iostream>
using namespace std;

/**
 * https://twitter.com/e869120/status/1385001057512693762/photo/1
 * 浮動小数点数を扱う場合、丸め誤差で WA が出る場合がある
 * 代表的な対処法
 * => - double ではなく、long double を使う
 *    * すべて整数で計算処理する
 *    - 差がeps以内であれば等しいとみなす
*/
int main() {
  long long A, B, C;
  cin >> A >> B >> C;

  long long right = 1;
  for (int i=0; i<B; i++) right *= C;

  if (A < right) cout << "Yes" << endl;
  else cout << "No" << endl;
}
