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

// https://atcoder.jp/contests/abc120/tasks/abc120_d
int main()
{
  long long N, M;
  cin >> N >> M;

  vector<Edge> e(M);
  for (int i=0; i<M; i++) {
    cin >> e[i].first >> e[i].second;
    e[i].first--;
    e[i].second--;
  }

  // 逆から考える（橋を架けていく）
  UnionFind uf(N);

  long long cnt = N * (N-1) / 2; // nC2 (NOTE: 右辺の段階でlong longじゃないとダメ)
  vector<long long> ans;
  for (int i=M-1; i>=0; i--) { // e[0]がある状態は答えに影響しないので考えなくて良い
    ans.push_back(cnt);

    if (uf.is_same(e[i].first, e[i].second)) continue;

    long long a_size = uf.group_size(e[i].first);
    long long b_size = uf.group_size(e[i].second);
    cnt -= a_size * b_size;

    uf.unite(e[i].first, e[i].second);
  }

  for (int i=ans.size()-1; i>=0; i--) {
    cout << ans[i] << endl;
  }
}
