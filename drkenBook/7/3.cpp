#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using Work = pair<long long, long long>;

bool cmp(const Work &a, const Work &b) {
  return a.second < b.second;
}

// https://atcoder.jp/contests/abc131/tasks/abc131_d
// ソート後の順序を保持したければ、Pairを使う
int main()
{
  int N;
  cin >> N;
  vector<Work> W(N);
  for (int i=0; i<N; i++) cin >> W[i].first >> W[i].second;

  sort(W.begin(), W.end(), cmp);

  bool ok = true;
  long long time = 0;
  for (int i=0; i<N; i++) {
    if (time + W[i].first > W[i].second) {
      ok = false;
      break;
    }
    time += W[i].first;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
