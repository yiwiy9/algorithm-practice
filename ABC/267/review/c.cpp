#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1LL << 60;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * https://atcoder.jp/contests/abc267/tasks/abc267_c
 *
 * 1. 1 ~ M までの Σ(i * A[i]) を求める
 * 2. 添字を上げる際
 *   * 累積和: A[1]+A[2]+...+A[M] を前回の値から引く（*iの部分を乗数を減らす）
 *   * 新たに上がった添字分: A[M+1]*M+1 を足す
 * 3. 2.を繰り返す
 */
int main()
{
  long long N, M;
  cin >> N >> M;

  vector<long long> A(N+1), S(N+2);
  for (long long i=1; i<=N; i++) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }

  long long max = -INF;
  long long cur = 0;
  for (long long i=1; i<=N; i++) {
    if (i > M) {
      cur -= S[i] - S[i-M];
      cur += A[i] * M;
    } else {
      cur += A[i] * i;
    }

    if (i >= M) chmax(max, cur);
  }

  cout << max << endl;
}
