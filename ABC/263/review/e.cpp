#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 998244353;

long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
      x = 1;
      y = 0;
      return a;
  }
  long long d = extGCD(b, a%b, y, x);
  y -= a / b * x;
  return d;
}

inline long long mod(long long a, long long m) {
  return (a % m + m) % m;
}

long long modinv(long long a, long long m) {
  long long x, y;
  extGCD(a, m, x, y);
  return mod(x, m);
}

/**
 * https://atcoder.jp/contests/abc263/tasks/abc263_e
 *
 * dp[i] := マス i からマス N にたどり着くまでにサイコロを振る回数の期待値)
 * dp[N] = 0
 *
 * i からサイコロを一回振ると、i, i+1, ... , i+A[i]のいずれかに等確率で進む
 * dp[i] = 1/(A[i]+1) * (Σdp[i+j]) + 1 (0<=j<=A[i])
 *       = 1/(A[i]+1) * dp[i] + 1/(A[i]+1) * (Σdp[i+j]) + 1 (1<=j<=A[i])
 *
 * このままだとこのままだと遷移が出来ないので、dp[i]をまとめると、
 * A[i]/(A[i]+1) * dp[i] = 1/(A[i]+1) * (Σdp[i+j]) + 1 (1<=j<=A[i])
 *
 * よって遷移式は、
 * dp[i] = 1/A[i] * (Σdp[i+j]) + (A[i]+1)/A[i] (1<=j<=A[i])
 */
int main()
{
  int N;
  cin >> N;

  vector<long long> A(N);
  for (int i=1; i<N; i++) cin >> A[i];

  vector<long long> dp(N+1), S(N+1);

  dp[N] = 0;
  for (int i=N-1; i>0; i--) {
    S[i] = S[i+1] + dp[i+1];
    long long invA = modinv(A[i], MOD);
    dp[i] = invA * ((S[i]-S[i+A[i]] + MOD) % MOD); // ココ、MODを細かくとらないとダメ
    dp[i] %= MOD;
    dp[i] += (A[i]+1) * invA;
    dp[i] %= MOD;
  }

  cout << dp[1] << endl;
}
