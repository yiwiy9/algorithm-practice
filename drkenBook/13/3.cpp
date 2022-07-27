#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;
bool bfs(const Graph &G, int s)
{
  queue<int> que;

  // 始点をキューに入れる
  color[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto next_v : G[v]) {
      if (color[next_v] != -1) {
        if (color[next_v] == color[v]) return false;
        continue;
      }
      color[next_v] = 1 - color[v];
      que.push(next_v);
    }
  }

  return true;
}

int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  color.assign(N, -1);
  bool ok = true;
  for (int v=0; v<N; v++) {
    if (color[v] != -1) continue;
    ok = bfs(G, v);
    if (!ok) break;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
