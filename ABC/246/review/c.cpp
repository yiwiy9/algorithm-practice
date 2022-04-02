#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N, K, X;
  cin >> N >> K >> X;

  vector<int> A(N), B(N);
  for (int i=0; i<N; i++) cin >> A[i];

  sort(A.begin(), A.end(), greater<int>());

  int use_cnt;
  for (int i=0; i<N; i++) {
    if (K == 0) {
      B[i] = A[i];
      continue;
    }

    use_cnt = A[i] / X;
    if (use_cnt > K) use_cnt = K;

    K -= use_cnt;
    B[i] = A[i] - (X * use_cnt);
  }

  sort(B.begin(), B.end(), greater<int>());

  // K != 0 => B[i] < X
  long long ans = 0; // <= 型に注意！！
  for (int i=K; i<N; i++) ans += B[i];
  cout << ans << endl;
}
