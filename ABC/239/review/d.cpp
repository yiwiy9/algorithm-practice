#include <iostream>
#include <vector>
using namespace std;

vector<bool> Eratosthenes(int N) {
  // テーブル
  vector<bool> isprime(N+1, true);

  // 1 は予めふるい落としておく
  isprime[1] = false;

  // ふるい
  for (int p = 2; p <= N; p++) {
    // すでに合成数であるものはスキップする
    if (!isprime[p]) continue;

    // p 以外の p の倍数から素数ラベルを剥奪
    for (int q = p * 2; q <= N; q += p) {
      isprime[q] = false;
    }
  }

  // 1 以上 N 以下の整数が素数かどうか
  return isprime;
}

/*
 https://atcoder.jp/contests/abc239/tasks/abc239_d
*/
int main()
{
  int A, B ,C, D;
  cin >> A >> B >> C >> D;

  vector<bool> is_prime = Eratosthenes(200);

  bool win_t;
  for (int i=A; i<=B; i++) {
    win_t = true;
    for (int j=C; j<=D; j++) {
      if (is_prime[i+j]) {
        win_t = false;
        break;
      }
    }
    if (win_t) break;
  }

  if (win_t) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}
