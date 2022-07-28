#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

vector<int> max_dist;
int dfs(const Graph &G, int v)
{
  max_dist[v] = 0;
  for (auto next_v : G[v]) {
    if (max_dist[next_v] != -1) {
      chmax(max_dist[v], max_dist[next_v]+1);
      continue;
    }
    chmax(max_dist[v], dfs(G, next_v)+1);
  }
  return max_dist[v];
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

  int ans = -1;
  max_dist.assign(N, -1);
  for (int v=0; v<N; v++) {
    if (max_dist[v] != -1) continue;
    dfs(G, v);
    chmax(ans, max_dist[v]);
  }

  cout << ans << endl;
}
