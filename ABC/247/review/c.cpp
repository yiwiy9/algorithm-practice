#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> memo;

string S(int n)
{
  if (memo[n] != "none") return memo[n];
  if (n == 1) return memo[n] = "1";
  return memo[n] = S(n-1) + ' ' + to_string(n) + ' ' + S(n-1);
}

/**
 * https://atcoder.jp/contests/abc247/tasks/abc247_c
 *
 * 再帰関数の発想をちゃんと持つ
 */
int main()
{
  int N;
  cin >> N;

  memo.assign(N+1, "none");
  S(N);

  for (auto num_or_emp : memo[N])
  {
    cout << num_or_emp;
  }
  cout << endl;
}
