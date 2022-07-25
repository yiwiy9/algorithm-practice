#include <iostream>
#include <vector>
#include <map>
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

// https://atcoder.jp/contests/abc049/tasks/arc065_b
int main()
{
  int N, K, L;
  cin >> N >> K >> L;

  UnionFind uf_rail(N);
  for (int i=0; i<K; i++) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    uf_rail.unite(p, q);
  }
  UnionFind uf_road(N);
  for (int i=0; i<L; i++) {
    int r, s;
    cin >> r >> s;
    r--, s--;
    uf_road.unite(r, s);
  }

  // uf_rail.root(a) == uf_rail.root(b) かつ uf_road.root(a) == uf_road.root(b) の数を求める
  // 頂点１つずつ求めていくのではなく、根の組み合わせが共通(=題意)のグループとしてmapで管理する
  map<pair<int, int>, int> m;
  for (int i=0; i<N; i++) {
    int root_rail = uf_rail.root(i);
    int root_road = uf_road.root(i);
    m[{root_rail, root_road}]++;
  }

  for (int i=0; i<N; i++) {
    int root_rail = uf_rail.root(i);
    int root_road = uf_road.root(i);
    cout << m[{root_rail, root_road}] << ' ';
  }
  cout << endl;
}
