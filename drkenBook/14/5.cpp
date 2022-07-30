#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1 << 30;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

/**
 * https://atcoder.jp/contests/arc084/tasks/arc084_b
 * → https://drken1215.hatenablog.com/entry/2021/07/30/160000
 *
 * "12003212..." のように、数字を並べて行ったときに、その数字の和がなるべく小さくなるようにしつつ、K で割ったあまりがちょうど 0 となるようにせよ
 * ・dp[r] ← あまりが r になるような数字の作り方のうちの、各桁の和の最小値
 * ・遷移（整数の作り方）
 *   ・「+1」する
 *   ・「×10」する
 */
int main()
{
  int K;
  cin >> K;

  vector<int> dist(K, INF);
  deque<int> que;

  // 整数1からスタートする
  dist[1] = 1;
  que.push_front(1);

  // 0-1 BFS
  while(!que.empty()) {
    // deque の先頭要素を取り出す
    int v = que.front();
    que.pop_front();

    // 「×10」を試す（桁数の和が不変）
    // コスト 0 なので deque の先頭に push
    int nv = (v*10) % K;
    if (chmin(dist[nv], dist[v])) {
      que.push_front(nv);
    }

    // 「+1」を試す（桁数の和が＋1）
    // コスト 1 なので deque の末尾に push
    nv = (v+1) % K;
    if (chmin(dist[nv], dist[v]+1)) {
      que.push_back(nv);
    }
  }

  cout << dist[0] << endl;
}
