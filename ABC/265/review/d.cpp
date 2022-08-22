#include <iostream>
#include <set>
using namespace std;

/**
 * https://atcoder.jp/contests/abc265/tasks/abc265_d
 *
 * 累積和 S が単調増加であることに着目する
 * => set で管理
 *
 * Sy - Sx = P
 * Sz - Sy = Q
 * Sw - Sz = R
 *
 * xで全探索
 * => Sx を set 順で全探索
 * => Sy = P + Sx が決まる
 *   => Sz = Q + Sy, Sw = R + Sz まで全て決まれば、Yes
 */
int main()
{
  long long N, P, Q, R;
  cin >> N >> P >> Q >> R;

  long long sum = 0;
  set<long long> S;
  S.insert(sum);
  for (int i=0; i<N; i++) {
    long long a;
    cin >> a;
    sum += a;
    S.insert(sum);
  }

  bool ok = false;
  for (auto Sx : S) {
    if (S.find(Sx + P) != S.end() && S.find(Sx + P + Q) != S.end() && S.find(Sx + P + Q + R) != S.end()) {
      ok = true;
      break;
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
