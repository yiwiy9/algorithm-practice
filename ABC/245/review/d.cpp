#include <iostream>
#include <vector>
using namespace std;

/**
 * https://atcoder.jp/contests/abc245/tasks/abc245_d
 *
 * B[0]から考えると、A[0]==0のときにB[0]が一意に決まらないので帰納法が成立しない
 * → C[N+M], A[N] ≠ 0 であることに着目して、高次の項から求めていく
 *
 * C[N+M]   = A[N]B[M]
 * C[N+M-1] = A[N]B[M-1] + A[N-1]B[M]
 * C[N+M-2] = A[N]B[M-2] + A[N-1]B[M-1] + A[N-2]B[M]
 * ...
 * C[N+1]   = A[N]B[1] + A[N-1]B[2] + ... + A[1]B[N] + A[0]B[N+1]
 * C[N]     = A[N]B[0] + A[N-1]B[1] + ... + A[1]B[N-1] + A[0]B[N]
 *
 * M個の方程式を用意できた
 * ここで、N > M の場合、B[N] = 0 であることに留意
 */
int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> A(N+1), B(M+1), C(N+M+1);
  for (int i=0; i<N+1; i++) cin >> A[i];
  for (int i=0; i<N+M+1; i++) cin >> C[i];

  for (int i = M; i >= 0; i--) {
    B[i] = C[i + N] / A[N];
    for (int j = N; j >= 0; j--) {
      // 各方程式から B[i] が関わる項を引く
      C[i+j] -= B[i] * A[j];
    }
  }

  for (int i=0; i<M+1; i++) {
    cout << B[i] << " ";
  }
    cout << endl;
}
