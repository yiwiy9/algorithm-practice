#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://atcoder.jp/contests/abc121/tasks/abc121_c
int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<long long, int>> A(N);
  for (int i=0; i<N; i++) cin >> A[i].first >> A[i].second;

  sort(A.begin(), A.end());

  long long ans = 0;
  for (int i=0; i<N; i++) {
    if (A[i].second >= M) {
      ans += A[i].first * M;
      M -= M;
      break;
    }
    ans += A[i].first * A[i].second;
    M -= A[i].second;
  }

  cout << ans << endl;
}
