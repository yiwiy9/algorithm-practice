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

vector<bool> isprime = Eratosthenes(1000000);

int main()
{
  long long N;
  cin >> N;

  vector<int> prime;
  for (int i=1; i<=1000000; i++)
  {
    if (isprime[i]) prime.push_back(i);
  }

  int ans = 0;
  int prime_size = prime.size();
  for (int i=0; i<prime_size; i++)
  {
    int p = prime[i];
    if (p==0) break;
    for (int j=i+1; j<prime_size; j++)
    {
      int q = prime[j];
      if ((long long)p*q*q*q <= N) {
        ans++;
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
