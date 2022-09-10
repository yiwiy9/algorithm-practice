#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * https://atcoder.jp/contests/abc268/tasks/abc268_c
 *
 * cnt[k] := 操作を k 回行った場合に喜ぶ人数
 * => 料理iごとに、喜ぶ人に渡る操作回数をカウントアップしていく
 */
int main()
{
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i=0; i<N; i++) cin >> p[i];

  vector<int> cnt(N);
  for (int i=0; i<N; i++) {
    cnt[(p[i]-(i-1)+N)%N]++;
    cnt[(p[i]-i+N)%N]++;
    cnt[(p[i]-(i+1)+N)%N]++;
  }

  int max = 0;
  for (int i=0; i<N; i++) chmax(max, cnt[i]);

  cout << max << endl;
}
