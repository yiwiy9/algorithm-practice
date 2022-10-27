#include <iostream>
#include <vector>
#include <set>
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


int H, W;
int get_hash(int r, int c)
{
  return W*(r-1) + (c-1);
}

vector<int> get_surround_points(int r, int c)
{
  vector<int> vec;
  if (r != 1) {
    vec.push_back(get_hash(r-1, c));
  }
  if (r != H) {
    vec.push_back(get_hash(r+1, c));
  }
  if (c != 1) {
    vec.push_back(get_hash(r, c-1));
  }
  if (c != W) {
    vec.push_back(get_hash(r, c+1));
  }
  return vec;
}


int main() {
  cin >> H >> W;

  UnionFind uf(H*W);
  set<int> red_points;

  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int q;
    cin >> q;

    if (q == 2) {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      int point_a = get_hash(ra, ca);
      int point_b = get_hash(rb, cb);

      if (
        uf.is_same(point_a, point_b)
        && red_points.find(point_a) != red_points.end()
        && red_points.find(point_b) != red_points.end()
      ){
        cout << "Yes" << endl;
      } else cout << "No" << endl;
      continue;
    }

    int r, c;
    cin >> r >> c;
    int add_point = get_hash(r, c);
    auto surround_points = get_surround_points(r, c);
    for (auto point : surround_points) {
      if (red_points.find(point) != red_points.end()) {
        uf.unite(point, add_point);
      }
    }
    red_points.insert(add_point);
  }
}
