// https://qiita.com/drken/items/a14e9af0ca2d857dad23
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 素数判定
// 2 ~ sqrt(N)の整数で割れるかだけを見ればよい
bool is_prime(long long N) {
  if (N == 1) return false;
  for (long long i = 2; i * i <= N; i++) {
    if (N % i == 0) return false;
  }
  return true;
}

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

// 素因数分解
// 小さい数字から割り続けていくことがミソ
vector<pair<long long, long long>> prime_factorize(long long N) {
  vector<pair<long long, long long>> res;
  for (long long a = 2; a * a <= N; a++) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ex++;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

// エラトステネスのふるい
// 1 以上 N 以下の整数が素数かどうかを返す
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




int main() {
  long long a = 97;
  if (is_prime(a)) cout << "is_prime: Yes" << endl;
  else cout << "is_prime: No" << endl;

  long long b = 12;
  const auto &res_b = enum_divisors(b);
  cout << b << ":";
  for (auto d : res_b) cout << d << " ";
  cout << endl;

  long long c = 2020;
  const auto &res_c = prime_factorize(c);
  cout << c << ":";
  for (auto p : res_c) {
    for (int i = 0; i < p.second; i++) cout << " " << p.first;
  }
  cout << endl;

  long long n = 30;
  vector<bool> isprime = Eratosthenes(n);
  for (int v = 2; v <= n; v++) {
    cout << v << ": "
          << (isprime[v] ? "prime" : "not") << endl;
  }
}
