#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

/**
 * https://atcoder.jp/contests/abc132/tasks/abc132_e
 * vを
 * (v, 0)
 * (v, 1)
 * (v, 2)
 * とする
 *
 * u -> vを
 * (u, 0) -> (v, 1)
 * (u, 1) -> (v, 2)
 * (u, 2) -> (v, 0)
 * として、
 * (s, 0) -> (t, 0)の最短経路を求める
 */
int bfs(const Graph &G, int s, int t)
{
  int N = (int)G.size();
  vector<vector<int>> dist(N, vector<int>(3, -1));
  queue<pair<int, int>> que;

  // 始点をキューに入れる
  dist[s][0] = 0;
  que.push({s, 0});

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    int v = cur.first;
    int parity = cur.second;
    int next_parity = (parity + 1) % 3;

    for (auto next_v : G[v]) {
      if (dist[next_v][next_parity] != -1) continue;
      dist[next_v][next_parity] = dist[v][parity] + 1;
      que.push({next_v, next_parity});
    }
  }

  if (dist[t][0] == -1) return -1;
  else return dist[t][0] / 3;
}

int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
  }

  int s, t;
  cin >> s >> t;
  s--, t--;

  cout << bfs(G, s, t) << endl;
}
