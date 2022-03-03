#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  string S, T;
  cin >> S >> T;

  vector<vector<int>> dp(S.size()+1, vector<int>(T.size()+1, -1));
  dp[0][0] = 0;

  for (int i=0; i<=S.size(); i++) {
    for (int j=0; j<=T.size(); j++) {
      if (i > 0 && j > 0 && S[i-1] == T[j-1]) chmax(dp[i][j], dp[i-1][j-1]+1);
      if (i > 0) chmax(dp[i][j], dp[i-1][j]);
      if (j > 0) chmax(dp[i][j], dp[i][j-1]);
    }
  }

  cout << dp[S.size()][T.size()] << endl;
}
