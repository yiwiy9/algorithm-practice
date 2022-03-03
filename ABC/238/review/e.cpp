#include <iostream>
#include <vector>
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
  bool groupsize(int x) {
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

/*
 https://atcoder.jp/contests/abc238/tasks/abc238_e

 累積和は配列 B = (B[0],B[1],...,B[N])を考える。
 => B[j] は A の先頭j項の和を表す（0<=j<=n）
 これは、B[0]=0, Aに含まれる要素の総和=B[N]であることがわかる

 ここで、与えられる情報を以下のように読み替えることができる
 i(1<=i<=Q)個目の情報: A[li] + A[li+1] + ... + A[ri] = B[ri] - B[li-1]

 問題の性質（累積和）から、B[0]から情報を辿ってB[N]に辿り着くことができれば、B[N]を求められることになる
 <=> 頂点0 と 頂点N が連結である => Union-Find 使う（幅優先などのその他グラフ探索でもOK）
*/
int main()
{
  int N, Q;
  cin >> N >> Q;

  UnionFind uf(N+1);
  for (int i = 0; i < Q; i++)
  {
    int l, r;
    cin >> l >> r;
    uf.unite(r, l-1);
  }

  if (uf.is_same(0, N)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
