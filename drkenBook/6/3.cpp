#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;
template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  int N;
  long long M;
  cin >> N >> M;
  vector<long long> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  vector<long long> S;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      S.push_back(a[i] + a[j]);
    }
  }
  sort(S.begin(), S.end());

  long long res = -1;
  for (auto s : S) {
    auto iter = lower_bound(S.begin(), S.end(), M - s);
    if (iter == S.begin()) continue; // どの要素を足しても、M以上になる場合
    iter--;
    chmax(res, s + *iter);
  }

  cout << res << endl;
}
