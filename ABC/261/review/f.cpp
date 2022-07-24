#include <iostream>
#include <vector>
using namespace std;

// xのi桁目のbitを取得（0 or 1）
#define bit(x,i)(((x)>>(i))&1)


/**
 * https://atcoder.jp/contests/abc261/tasks/abc261_e
 *
 * 操作はbitごとに独立（和や差のように他のbitに影響しない)であるため、bitごとに分けて考えて良い
 * → Aの各bitでループすることで、O(logA)に計算量を落とす
 */
int main()
{
  int N, C;
  cin >> N >> C;

  vector<int> T(N), A(N);
  for (int i=0; i<N; i++) cin >> T[i] >> A[i];

  vector<int> ans(N);

  // A,C < 2^30 => 30桁のbitを考えればよい
  for (int k=0; k<30; k++) {
    vector<int> func = {0, 1}; // 操作の合成関数の結果を保持する必要がある
    int current_bit = bit(C, k);
    for (int i=0; i<N; i++) {
      vector<int> f(2);
      int operation_bit = bit(A[i], k);
      if (T[i] == 1) f = {0 & operation_bit, 1 & operation_bit};
      if (T[i] == 2) f = {0 | operation_bit, 1 | operation_bit};
      if (T[i] == 3) f = {0 ^ operation_bit, 1 ^ operation_bit};

      func = {f[func[0]], f[func[1]]};
      current_bit = func[current_bit];
      ans[i] |= current_bit << k;
    }
  }

  for (int i=0; i<N; i++) {
    cout << ans[i] << endl;
  }
}
