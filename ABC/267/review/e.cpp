#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;

/**
 * https://atcoder.jp/contests/abc267/tasks/abc267_e
 *
 * 問題文に書かれている操作を N 回行う。しかし、全ての操作のコストは X 以下である必要がある。N 回の操作を全て行うことは可能か？
 *
 * という判定問題（二分探索）
 * 操作する順番というのは、コストがX以下である点であればどの順番で操作しても良い
 * → スタックに入れる
 *
 * https://twitter.com/yiwiy9/status/1566289189779705856?s=20&t=dj5K8UdFFFTLQLnSAWuMqA
 */
int main()
{
  int N, M;
  cin >> N >> M;
  vector<long long> A(N), B(N);
  for (int v=0; v<N; v++) cin >> A[v];

  Graph G(N);
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
    B[a] += A[b];
    B[b] += A[a];
  }

  long long left = -1, right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2;

    vector<long long> C = B;
    stack<int> st;

    for (int v=0; v<N; v++) {
      if (C[v] <= mid) st.push(v);
    }

    int del_cnt = 0;
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      del_cnt++;

      for (auto next_v : G[v]) {
        if (C[next_v] <= mid) continue;
        C[next_v] -= A[v];
        if (C[next_v] <= mid) st.push(next_v);
      }
    }

    if (del_cnt == N) {
      // mid は条件を十分に満たす
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << right << endl;
}
