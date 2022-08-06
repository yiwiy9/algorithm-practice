#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  long long N, L, R;
  cin >> N >> L >> R;

  vector<long long> A(N), S(N+1), RS(N+1);
  for (long long i=0; i<N; i++) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }

  long long min = S[N] - S[0];
  long long min_iter = -1;
  for (long long i=0; i<N; i++) {
    long long sum_l = L * (i+1) + S[N] - S[i+1];
    if (chmin(min, sum_l)) min_iter = i;
  }

  for (long long i=0; i<=min_iter; i++) A[i] = L;

  for (long long i=0; i<N; i++) RS[i+1] = RS[i] + A[N-1-i];

  min = RS[N] - RS[0];
  min_iter = -1;
  for (long long i=0; i<N; i++) {
    long long sum_r = R * (i+1) + RS[N] - RS[i+1];
    if (chmin(min, sum_r)) min_iter = i;
  }

  cout << min << endl;
}
