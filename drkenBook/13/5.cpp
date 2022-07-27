#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

/**
 * https://qiita.com/drken/items/996d80bcae64649a6580
 * 出次数 deg[v]： 頂点 vv を始点とする辺の個数
 * シンク： 出次数が 0 であるような頂点
 */
int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  vector<int> deg(N, 0); // 各頂点の出次数
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    G[b].push_back(a); // シンクから遡って行きたいので、逆向きに辺を張る
    deg[a]++;
  }

  queue<int> que;

  // 全てのシンクをキューに入れる
  for (int v=0; v<N; v++) if (deg[v] == 0) que.push(v);

  vector<int> order;
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    order.push_back(v);

    for (auto prev_v : G[v]) {
      deg[prev_v]--; // vをグラフから取り除く（vへ向かう頂点の出次数を減らす）
      if (deg[prev_v] == 0) que.push(prev_v);
    }
  }

  reverse(order.begin(), order.end());
  for (auto v : order) cout << v << endl;
}
