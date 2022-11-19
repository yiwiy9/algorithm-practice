#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> order;
void dfs1(const Graph &G, int v)
{
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs1(G, next_v);
  }
  order.push_back(v);
}

long long dfs2(const Graph &G, int v)
{
  seen[v] = true;

  long long cnt = 1;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    cnt += dfs2(G, next_v);
  }

  return cnt;
}

/**
 * https://twitter.com/e869120/status/1385363292739104775/photo/1
 * 強連結成分分解（SCC）をしよう
 *   強連結: 頂点x,yが互いに到達可能
 *
 * サイクルを含むグラフでトポロジカルソートをすれば、強連結のグループに分かれる
 * 手順
 *   1. DFSをして、帰りがけ順に番号を記録
 *   2. 辺の向きを全て反転させ（サイクルがあるから）、番号の大きい大きい順にDFSする
 **/
int main()
{
  int N, M;
  cin >> N >> M;

  Graph G1(N), G2(N);
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G1[a].push_back(b);
    G2[b].push_back(a);
  }

  seen.assign(N, false);
  order.clear();
  for (int v=0; v<N; v++) {
    if (seen[v]) continue;
    dfs1(G1, v);
  }

  seen.assign(N, false);
  reverse(order.begin(), order.end());
  long long ans = 0;
  for (auto v : order) {
    if (seen[v]) continue;
    long long cnt = dfs2(G2, v);
    ans += cnt * (cnt-1) / 2;
  }

  cout << ans << endl;
}
