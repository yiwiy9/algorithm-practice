#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int inf = 1 << 30;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> h(N);
  for (int i=0; i<N; i++) cin >> h[i];

  vector<int> dp(N, inf);
  dp[0] = 0;

  for (int i=0; i<N; i++) {
    for (int j=1; j<=K; j++) {
      if (i+j<N) chmin(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
    }
  }

  cout << dp[N-1] << endl;
}
