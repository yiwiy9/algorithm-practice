#include <iostream>
#include <vector>
using namespace std;

// 重み付き Union-Find
template<class Abel> struct UnionFind {
  vector<int> parent, size;
  vector<Abel> diff_weight; // 親ノードとの重みの差分

  // コンストラクタ
  UnionFind(int n, Abel SUM_UNITY = 0) : parent(n, -1) , size(n, 1), diff_weight(n, SUM_UNITY) {}

  // 根を求める（経路圧縮の工夫あり）
  int root(int x) {
    // x が根の場合は x を直接返す
    if (parent[x] == -1) return x;

    // 経路圧縮
    int r = root(parent[x]);
    // 累積和をとる（親が根になるので、欲しいのは根までの重みの和）
    diff_weight[x] += diff_weight[parent[x]];
    // x の親を parent[x] を根に設定する => 再帰的にすべての親の親が根に張り替えられる
    return parent[x] = r;
  }

  // x と y が同じグループに属するかどうか <=> 根が一致するかどうか
  bool is_same(int x, int y) {
    return root(x) == root(y);
  }

  // x を含むグループのサイズ
  int group_size(int x) {
    return size[root(x)];
  }

  Abel weight(int x) {
    root(x); // 経路圧縮
    return diff_weight[x];
  }

  // x と y が同じグループにいるときに使える
  Abel diff(int x, int y) {
    return weight(y) - weight(x);
  }

  // weight(y) - weight(x) = w となるように併合する
  bool unite(int x, int y, Abel w) {
    // x と y それぞれについて、 root との重み差分を補正
    w += weight(x); w -= weight(y);

    // グループを判断するために根に移動する
    int root_x = root(x), root_y = root(y);

    // すでに同じグループのときは何もしない
    if (root_x == root_y) return false;

    // union by size (y 側のサイズが小さくなるようにする) (それに合わせて w も符号反転する)
    if (size[root_x] < size[root_y]) swap(root_x, root_y), w = -w;

    // y (サイズが小さい方)を x (サイズが大きい方)の子とする => 増える深さが 0 or 1 で最小限（root() が速くなる）
    parent[root_y] = root_x;
    size[root_x] += size[root_y];

    // x が y の親になるので、x と y の差分を diff_weight[root_y] に記録
    diff_weight[root_y] = w;

    return true;
  }
};

// https://atcoder.jp/contests/abc087/tasks/arc090_b
int main()
{
  int N, M;
  cin >> N >> M;

  UnionFind<long long> uf(N);
  bool ok = true;
  for (int i=0; i<M; i++) {
    int l, r;
    long long d;
    cin >> l >> r >> d;
    l--, r--;

    if (uf.is_same(l, r) && uf.diff(l, r) != d) {
      ok = false;
      break;
    }

    uf.unite(l, r, d);
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
