#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> bfs(const Graph &G, int s)
{
  int N = (int)G.size();
  vector<int> dist(N, -1);
  queue<int> que;

  // 始点をキューに入れる
  dist[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto next_v : G[v]) {
      if (dist[next_v] != -1) continue;
      dist[next_v] = dist[v] + 1;
      que.push(next_v);
    }
  }

  return dist;
}

int main()
{
  int N, M, s, t;
  cin >> N >> M >> s >> t;

  Graph G(N);
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  auto dist = bfs(G, s);

  if (dist[t] != -1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
