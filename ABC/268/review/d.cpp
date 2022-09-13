#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

set<string> T;
void func(int cur, vector<string> &S, int remain, string ans)
{
  if (remain < 0) return;

  // 終了条件 := 全てのS[i]を結合済み
  if (cur == S.size()) {
    if (ans.size() >= 3 && T.find(ans) == T.end()) {
      cout << ans << endl;
      exit(0);
    }
    return;
  }

  if (ans.size() > 0 && ans.back() != '_') {
    // S[i]の後ろに`_`を１つ挿入
    func(cur, S, remain, ans+"_");
  } else {
    // 末尾ににS[i+1]を挿入
    func(cur+1, S, remain, ans+S[cur]);

    if (ans.size() > 0) {
      // `_`の後ろに`_`を１つ挿入
      func(cur, S, remain-1, ans+"_");
    }
  }
}

/**
 * https://atcoder.jp/contests/abc268/tasks/abc268_d
 */
int main()
{
  int N, M;
  cin >> N >> M;

  vector<string> S(N);
  for (int i=0; i<N; i++) cin >> S[i];
  sort(S.begin(), S.end());

  for (int i=0; i<M; i++) {
    string t;
    cin >> t;
    T.insert(t);
  }

  // 余分に追加できる`_`の数
  int remain = 16 - S[0].size();
  for (int i=1; i<N; i++) remain -= (S[i].size()+1);

  do {
    func(0, S, remain, "");
  } while (next_permutation(S.begin(), S.end()));

  cout << -1 << endl;
}
