#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
using Graph = map<int, vector<int>>;

Graph G;
map<int, bool> dist;
int bfs(int s)
{
  queue<int> que;

  // 始点をキューに入れる
  dist[s] = true;
  que.push(s);
  int max_v = s;

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto next_v : G[v]) {
      if (dist[next_v]) continue;
      dist[next_v] = true;
      que.push(next_v);
      max_v = max(max_v, next_v);
    }
  }

  return max_v;
}

int main()
{
  int N;
  cin >> N;

  for (int i=0; i<N; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << bfs(1) << endl;
}
