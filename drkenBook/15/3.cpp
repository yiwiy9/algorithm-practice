#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


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

// 辺 e = (u, v) を {w(e), {u, v}} で表す
using Edge = pair<long long, pair<int,int>>;


int main() {
  // 入力
  int N, M; // 頂点数と辺数
  cin >> N >> M;
  vector<Edge> edges(M); // 辺集合
  for (int i = 0; i < M; ++i) {
    int u, v; long long w; // w は重み
    cin >> u >> v >> w;
    edges[i] = Edge(w, {u, v});
  }

  // 各辺を，辺の重みが小さい順にソートする
  // pair はデフォルトで (第一要素, 第二要素) の辞書順比較
  sort(edges.begin(), edges.end());

  // クラスカル法
  long long tree_weights = 0;
  vector<Edge> tree_edges;
  UnionFind uf(N);
  for (int i = 0; i < M; ++i) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    // 辺 (u, v) の追加によってサイクルが形成されるときは追加しない
    if (uf.is_same(u, v)) continue;

    // 辺 (u, v) を追加する
    uf.unite(u, v);
    tree_weights += w;
    tree_edges.push_back(edges[i]);
  }

  for (auto tree_edge : tree_edges) {
    long long current_weights = 0;
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
      if (edges[i] == tree_edge) continue;

      int w = edges[i].first;
      int u = edges[i].second.first;
      int v = edges[i].second.second;

      // 辺 (u, v) の追加によってサイクルが形成されるときは追加しない
      if (uf.is_same(u, v)) continue;

      // 辺 (u, v) を追加する
      uf.unite(u, v);
      current_weights += w;
    }
    if (current_weights != tree_weights) {
      cout << "u: " << tree_edge.second.first << ", ";
      cout << "v: " << tree_edge.second.second << ", ";
      cout << "w: " << tree_edge.first << endl;
    }
  }
}
