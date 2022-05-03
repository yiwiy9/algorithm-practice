#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  string s, t;
  cin >> s >> t;

  vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));

  for (int i=1; i<=s.size(); i++) {
    for (int j=1; j<=t.size(); j++) {
      if (s[i-1] == t[j-1]) {
        chmax(dp[i][j], dp[i-1][j-1]+1);
      }
      chmax(dp[i][j], dp[i-1][j]);
      chmax(dp[i][j], dp[i][j-1]);
    }
  }

  int len = dp[s.size()][t.size()];
  int i = s.size();
  int j = t.size();
  vector<char> ans(len);

  while (len > 0) {
    if (s[i-1] == t[j-1]) {
      len--;
      i--;
      j--;
      ans[len] = s[i];
    } else if (dp[i][j] == dp[i-1][j]) {
      i--;
    } else {
      j--;
    }
  }

  for (auto c : ans) cout << c;
  cout << endl;
}

/**
 * このやり方は、stringのコピーがvectorのコピーのように振る舞うので遅い
 */
// using dp_v = pair<int, string>;
// int main()
// {
//   string s, t;
//   cin >> s >> t;

//   int s_size, t_size;
//   s_size = s.size();
//   t_size = t.size();

//   vector<vector<dp_v>> dp(s_size+1, vector<dp_v>(t_size+1, {0, ""}));

//   for (int i=0; i<=s_size; i++) {
//     for (int j=0; j<=t_size; j++) {
//       if (i<s_size && j<t_size && s[i] == t[j]) {
//         if (dp[i+1][j+1].first < dp[i][j].first + 1) {
//           dp[i+1][j+1].first = dp[i][j].first + 1;
//           dp[i+1][j+1].second = dp[i][j].second + s[i];
//         }
//       }
//       if (i<s_size && dp[i+1][j].first < dp[i][j].first) {
//         dp[i+1][j] = dp[i][j];
//       }
//       if (j<t_size && dp[i][j+1].first < dp[i][j].first) {
//         dp[i][j+1] = dp[i][j];
//       }
//     }
//   }

//   cout << dp[s_size][t_size].second << endl;
// }
