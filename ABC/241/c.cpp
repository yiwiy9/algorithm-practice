#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

using Point = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  set<Point> black_points;
  string row;
  for (int i=0; i<N; i++) {
    cin >> row;
    for (int j=0; i<N; i++) {
      if (row[j] == '#') {
        black_points.insert({i, j});
      }
    }
  }

  bool ok = false;
  int count, add_cnt;
  Point cur_p;
  for (auto p : black_points) {
    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 右
      cur_p = {cur_p.first, cur_p.second+1};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }

    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 左
      cur_p = {cur_p.first, cur_p.second-1};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }

    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 上
      cur_p = {cur_p.first-1, cur_p.second};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }

    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 下
      cur_p = {cur_p.first+1, cur_p.second};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }

    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 右上
      cur_p = {cur_p.first-1, cur_p.second+1};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }

    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 右下
      cur_p = {cur_p.first+1, cur_p.second+1};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }

    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 左上
      cur_p = {cur_p.first-1, cur_p.second-1};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }

    count = 1;
    add_cnt = 0;
    cur_p = p;
    while (true)
    { // 左下
      cur_p = {cur_p.first+1, cur_p.second-1};
      if (black_points.find(cur_p) == black_points.end()) {
        add_cnt++;
        if (add_cnt > 2) {
          break;
        }
      }
      count++;
      if (count >= 6) {
        ok = true;
        break;
      }
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
