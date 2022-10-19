#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main()
{
  int N;
  string S;
  cin >> N >> S;

  string A = "atcoder";

  vector<int> dp(A.size()+1);
  dp[0] = 1;

  for (int i=0; i<N; i++) {
    for (int j=0; j<A.size(); j++) {
      if (S[i] == A[j]) {
        dp[j+1] += dp[j];
        dp[j+1] %= MOD;
      }
    }
  }

  cout << dp[A.size()] << endl;
}
