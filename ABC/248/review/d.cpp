#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * https://atcoder.jp/contests/abc248/tasks/abc248_d
 * B = A[X]; これは O(N)
 * メモリのコピー
 * 一つ一つコピーされていくよ！メモリの気持ちに！
 */
int main()
{
  int N;
  cin >> N;

  int a;
  vector<vector<int>> A(N+1);
  for (int i=1; i<=N; i++) {
    cin >> a;
    A[a].push_back(i);
  }

  int Q, L, R, X;
  cin >> Q;

  for (int i=0; i<Q; i++) {
    cin >> L >> R >> X;

    cout << upper_bound(A[X].begin(), A[X].end(), R) - lower_bound(A[X].begin(), A[X].end(), L) << endl;
  }
}
