#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}
template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

vector<int> leaf;
int id = 1;
void set_leaf_id_dfs(const Graph &G, int v, int par_v)
{
  if (v != 0 && G[v].size() == 1) {
    // 葉であるならば
    leaf[v] = id++;
    return;
  }

  for (auto next_v : G[v]) {
    if (next_v == par_v) continue;
    set_leaf_id_dfs(G, next_v, v);
  }
}

vector<int> L, R;
void set_LR_dfs(const Graph &G, int v, int par_v)
{
  if (leaf[v] != -1) {
    // 葉であるならば
    L[v] = R[v] = leaf[v];
    return;
  }

  for (auto next_v : G[v]) {
    if (next_v == par_v) continue;
    set_LR_dfs(G, next_v, v);
    chmin(L[v], L[next_v]);
    chmax(R[v], R[next_v]);
  }
}

/*
 https://atcoder.jp/contests/abc240/tasks/abc240_e

 葉に着目する
 葉に1~Mの整数を振っていき、それがL(i), R(i)に対応する → 最大値の最小値がM
*/
int main()
{
  int N;
  cin >> N;

  Graph G(N);
  for (int i=0; i<N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  leaf.assign(N, -1);
  set_leaf_id_dfs(G, 0, -1);

  L.assign(N, 1e9);
  R.assign(N, -1e9);
  set_LR_dfs(G, 0, -1);

  for (int i=0; i<N; i++) {
    cout << L[i] << " " << R[i] << endl;
  }
}
