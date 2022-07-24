#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i=0; i<N; i++) cin >> A[i] >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int ans = 0;
  for (int i=0; i<N; i++) {
    auto iter = upper_bound(B.begin(), B.end(), A[i]);
    if (iter == B.end()) break;
    ans++;
    *iter = A[i];
  }

  cout << ans << endl;

  // 別解
  // // B を順に見ていく
  // int i = 0;
  // for (int j = 0; j < N; ++j) {
  //   if (A[i] < B[j]) ++i;
  // }

  // // i が答え
  // cout << i << endl;
}
