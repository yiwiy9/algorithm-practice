#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
  int H, W, rs, cs, N;
  cin >> H >> W >> rs >> cs >> N;

  map<int, vector<int>> rows;
  map<int, vector<int>> lines;
  for (int i=0; i<N; i++) {
    int r, c;
    cin >> r >> c;

    rows[r].push_back(c);
    lines[c].push_back(r);
  }
  for (auto &[i, r]: rows) {
    sort(r.begin(), r.end());
  }
  for (auto &[i, l]: lines) {
    sort(l.begin(), l.end());
  }

  int Q;
  cin >> Q;
  char d;
  int l;
  for (int i=0; i<Q; i++) {
    cin >> d >> l;

    if (d == 'U') {
      auto itr = lines.find(cs);
      int lb = 0; // 範囲外に壁を設定
      if (itr != lines.end()) {
        auto &vec = itr->second;
        auto itr2 = lower_bound(vec.begin(), vec.end(), rs);
        if (itr2 != vec.begin()) {
          // 上側に壁があれば壁を取得
          itr2--; // 値が小さい壁のイテレータを取得
          lb = *itr2;
        }
      }
      rs = max(rs-l, lb+1);
    }

    if (d == 'D') {
      auto itr = lines.find(cs);
      int ub = H+1; // 範囲外に壁を設定
      if (itr != lines.end()) {
        auto &vec = itr->second;
        auto itr2 = upper_bound(vec.begin(), vec.end(), rs);
        if (itr2 != vec.end()) {
          // 下側に壁があれば壁を取得
          ub = *itr2;
        }
      }
      rs = min(rs+l, ub-1);
    }

    if (d == 'L') {
      auto itr = rows.find(rs);
      int lb = 0; // 範囲外に壁を設定
      if (itr != rows.end()) {
        auto &vec = itr->second;
        auto itr2 = lower_bound(vec.begin(), vec.end(), cs);
        if (itr2 != vec.begin()) {
          // 左側に壁があれば壁を取得
          itr2--; // 値が小さい壁のイテレータを取得
          lb = *itr2;
        }
      }
      cs = max(cs-l, lb+1);
    }

    if (d == 'R') {
      auto itr = rows.find(rs);
      int ub = W+1; // 範囲外に壁を設定
      if (itr != rows.end()) {
        auto &vec = itr->second;
        auto itr2 = upper_bound(vec.begin(), vec.end(), cs);
        if (itr2 != vec.end()) {
          // 右側に壁があれば壁を取得
          ub = *itr2;
        }
      }
      cs = min(cs+l, ub-1);
    }

    cout << rs << ' ' << cs << endl;
  }
}
