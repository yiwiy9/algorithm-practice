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
  int N;
  cin >> N;

  vector<int> h(N);
  for (int i=0; i<N; i++) cin >> h[i];

  vector<int> dp(N, inf);
  dp[0] = 0;

  for (int i=0; i<N; i++) {
    if (i+1<N) chmin(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
    if (i+2<N) chmin(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
  }

  cout << dp[N-1] << endl;
}
