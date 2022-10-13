#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> bfs(const Graph &G, int s)
{
  int N = (int) G.size();
  vector<int> dist(N, -1);
  queue<int> que;

  dist[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int next_v : G[v]) {
      if (dist[next_v] != -1) continue;

      dist[next_v] = dist[v] + 1;
      que.push(next_v);
    }
  }

  return dist;
}

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_c
 *
 * https://twitter.com/e869120/status/1377752658149175299/photo/1
 * 木の直径（単純パスの長さの最大値）は最短距離の計算を２回やる
 * 1. 適当な点を一つ決めて、最短距離の計算をする
 * 2. 1.で求めた距離の中で最大の点からの最短距離を計算する
 * 3. 2.で求めた距離の中の最大値が木の直径
 * => 計算量：O(N)
 */
int main()
{
  int N;
  cin >> N;

  Graph G(N);
  for (int i=0; i<N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> dist = bfs(G, 0);

  int longest_dist = -1;
  int longest_point = -1;
  for (int i=0; i<N; i++) {
    if (dist[i] > longest_dist) {
      longest_dist = dist[i];
      longest_point = i;
    }
  }

  dist = bfs(G, longest_point);
  longest_dist = -1;
  for (int i=0; i<N; i++) {
    if (dist[i] > longest_dist) {
      longest_dist = dist[i];
    }
  }

  cout << longest_dist + 1 << endl;
}
