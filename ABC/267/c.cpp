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

int main()
{
  long long N, M;
  cin >> N >> M;

  vector<long long> A(N+1), B(N+1, 0);
  for (long long i=1; i<=N; i++) cin >> A[i];

  for (long long i=1; i<=N; i++) {
    for (long long j=i; j>=1; j--) {
      B[j] += A[i]*j;
    }
  }

  long long max = -INF;
  for (long long i=1; i<=N; i++) chmax(max, B[i]);

  cout << max << endl;
}
