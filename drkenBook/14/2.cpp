#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

struct Edge {
  int to; // 隣接頂点番号
  long long w; // 重み
  Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * https://atcoder.jp/contests/abc061/tasks/abc061_d
 * 0-Nウォーク以外に0から到達できる正閉路があるとき、
 * 通常のベルマン・フォード法では正閉路ありと判定してしまう
 */
int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i=0; i<M; i++) {
    int a, b;
    long long w;
    cin >> a >> b >> w;
    a--, b--;
    G[a].push_back(Edge(b, w));
  }

  // ベルマン・フォード法（最短路ではなく最長路）
  vector<long long> dist(N, -INF);
  dist[0] = 0;
  for (int iter=0; iter<2*N; iter++) { // N回目の反復で正閉路にINFを入れて、もうN回反復する
    for (int v=0; v<N; v++) {
      if (dist[v] == -INF) continue;

      for (auto e : G[v]) {
        long long relaxation = dist[v] + e.w;
        if (dist[v] == INF) relaxation = INF;
        if (chmax(dist[e.to], relaxation)) {
          if (iter == N-1) dist[e.to] = INF; // N回目の反復で正閉路にINFを入れる
        }
      }
    }
  }
  if (dist[N-1] == INF) cout << "inf" << endl;
  else cout << dist[N-1] << endl;
}
