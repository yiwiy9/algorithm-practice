#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
using Point = pair<int, int>;
const int INF = 1 << 30;

int main()
{
  int N;
  cin >> N;

  vector<Point> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i].first;
    cin >> a[i].second;
  }

  string S;
  cin >> S;

  // y, (L MAX, R MIN)
  unordered_map<int, Point> map;
  bool OK = false;
  for (int i=0; i<N; i++) {
    if (map.find(a[i].second) == map.end()) {
      if (S[i] == 'L') {
        map[a[i].second] = {a[i].first, INF};
      } else {
        map[a[i].second] = {-INF, a[i].first};
      }
      continue;
    }

    if (S[i] == 'L') {
      if (a[i].first > map[a[i].second].second) {
        OK = true;
        break;
      }
      if (a[i].first > map[a[i].second].first) {
        map[a[i].second].first = a[i].first;
      }
    }

    if (S[i] == 'R') {
      if (a[i].first < map[a[i].second].first) {
        OK = true;
        break;
      }
      if (a[i].first < map[a[i].second].second) {
        map[a[i].second].second = a[i].first;
      }
    }
  }


  if (OK) cout << "Yes" << endl;
  else cout << "No" << endl;
}
