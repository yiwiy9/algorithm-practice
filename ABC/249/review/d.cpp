#include <iostream>
#include <vector>
using namespace std;

// 約数の列挙
vector<long long> enum_divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      res.push_back(i);
      // 重複しないならば（sqrt(N)が整数以外の場合）i の相方である N/i も push
      if (N/i != i) res.push_back(N/i);
    }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

/**
 * https://atcoder.jp/contests/abc249/tasks/abc249_d
 *
 * A[i]/A[j] = A[k] の個数を求める
 * => A[i]を固定して考える
 * => A[k]が整数であることを考えると、A[j]はA[i]の約数であることがわかる
 * => A[j]が決まれば、自動的にA[k](=A[i]/A[j])が決まる
 * => よって、A[i]の線形全探索においてA[i]の約数(=A[j])を全探索し、
 *    その中でjとkの組はどんな組でも問題ないので、cnt[A[j]]*cnt[A[i]/A[j]]を足し上げていけば良い
 */
int main()
{
  int N;
  cin >> N;

  vector<int> A(N), cnt(200001);
  for (int i=0; i<N; i++) {
    cin >> A[i];
    cnt[A[i]]++;
  }

  long long ans = 0;
  for (int i=0; i<N; i++) {
    vector<long long> divs = enum_divisors((long long)A[i]);
    for (auto a_j : divs) {
      int cnt_j = cnt[a_j];
      int cnt_k = cnt[A[i]/a_j];
      ans += 1LL * cnt_j * cnt_k;
    }
  }

  cout << ans << endl;
}
