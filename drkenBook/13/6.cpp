#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen, finished;

// サイクル復元のための情報
int pos = -1; // サイクル中に含まれる頂点 pos
stack<int> history; // 訪問履歴

void dfs(const Graph &G, int v, int p = -1)
{
  seen[v] = true;
  history.push(v);

  for (auto next_v : G[v]) {
    if (next_v == p) continue; // 逆流

    if (finished[next_v]) continue; // 完全終了

    if (seen[next_v] && !finished[next_v]) { // サイクル検出
      pos = next_v;
      return;
    }

    dfs(G, next_v, v);

    // サイクル検出したならば真っ直ぐに抜けていく
    if (pos != -1) return;
  }

  history.pop();
  finished[v] = true;
}

/**
 * https://qiita.com/drken/items/a803d4fc4a727e02f7ba
 * seen[v] ← 行きがけ順の意味で v が訪問済みであることを表す (帰りがけ順の意味で v が訪問済みかどうかは定かではない)
 * finished[v] ← 帰りがけ順の意味で v が訪問済みであることを表す
 *
 * 「seen[v] = true && finished[v] = false」の状態で頂点 v に戻るような状況が発生したならば、
 * 「グラフはサイクルを含み、v はサイクル内の頂点である」ということが確定
 */
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

  seen.assign(N, false);
  finished.assign(N, false);
  for (int v=0; v<N; v++) {
    if (seen[v]) continue;
    dfs(G, v);
    if (pos != -1) break;
  }

  if (pos != -1) {
    cout << "Yes" << endl;
    while (!history.empty()) {
      int t = history.top();
      history.pop();
      cout << t << endl;
      if (t == pos) break;;
    }
  } else {
    cout << "No" << endl;
  }
}
