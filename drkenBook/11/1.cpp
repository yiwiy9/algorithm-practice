#include <iostream>
#include <vector>
using namespace std;

using Edge = pair<int, int>;

struct UnionFind {
  vector<int> parent, size;

  // コンストラクタ
  UnionFind(int n) : parent(n, -1) , size(n, 1) {}

  // 根を求める（経路圧縮の工夫あり）
  int root(int x) {
    // x が根の場合は x を直接返す
    if (parent[x] == -1) return x;

    // x の親を parent[x] を根に設定する => 再帰的にすべての親の親が根に張り替えられる
    return parent[x] = root(parent[x]);
  }

  // x と y が同じグループに属するかどうか <=> 根が一致するかどうか
  bool is_same(int x, int y) {
    return root(x) == root(y);
  }

  // x を含むグループのサイズ
  int group_size(int x) {
    return size[root(x)];
  }

  // x を含むグループと y を含むグループとを併合する
  bool unite(int x, int y) {
    // グループを判断するために根に移動する
    int root_x = root(x), root_y = root(y);

    // すでに同じグループのときは何もしない
    if (root_x == root_y) return false;

    // union by size (y 側のサイズが小さくなるようにする)
    if (size[root_x] < size[root_y]) swap(root_x, root_y);

    // y (サイズが小さい方)を x (サイズが大きい方)の子とする => 増える深さが 0 or 1 で最小限（root() が速くなる）
    parent[root_y] = root_x;
    size[root_x] += size[root_y];
    return true;
  }
};

// https://atcoder.jp/contests/abc075/tasks/abc075_c
int main()
{
  int N, M;
  cin >> N >> M;

  vector<Edge> e(M);
  for (int i=0; i<M; i++) cin >> e[i].first >> e[i].second;

  int ans = 0;
  for (int i=0; i<M; i++) {
    UnionFind uf(N+1);
    for (int j=0; j<M; j++) {
      if (i == j) continue;
      uf.unite(e[j].first, e[j].second);
    }

    int cnt = 0;
    for (int x=1; x<=N; x++) {
      if (uf.root(x) == x) cnt++;
    }

    if (cnt != 1) ans++;
  }

  cout << ans << endl;
}
