#include <iostream>
#include <vector>
using namespace std;

int N;
vector<char> dp;
void func(vector<char> &dp) {
  bool ok = true;
  int left_cnt = 0;
  for (int i=0; i<N; i++) {
    if (dp[i] == '(') left_cnt++;
    else left_cnt--;
    if (left_cnt < 0) {
      ok = false;
      break;
    }
  }
  if (left_cnt > 0) ok = false;

  if (!ok) return;

  for (int i=0; i<N; i++) cout << dp[i];
  cout << endl;
}

void dfs(char bracket, int depth) {
  dp[depth] = bracket;

  if (depth == N-1) {
    func(dp);
    return;
  }

  dfs('(', depth+1);
  dfs(')', depth+1);
}

int main()
{
  cin >> N;
  dp.assign(N, ' ');

  dfs('(', 0);
}
