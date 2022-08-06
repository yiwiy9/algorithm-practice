#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL<<60;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * https://atcoder.jp/contests/abc263/tasks/abc263_d
 */
int main()
{
  long long N, L, R;
  cin >> N >> L >> R;

  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  vector<long long> ldp(N+1, INF), rdp(N+1, INF);

  ldp[0] = 0;
  for (int i=0; i<N; i++) {
    chmin(ldp[i+1], ldp[i] + A[i]);
    chmin(ldp[i+1], L * (i+1));
  }

  rdp[0] = 0;
  for (int i=0; i<N; i++) {
    chmin(rdp[i+1], rdp[i] + A[N-i-1]);
    chmin(rdp[i+1], R * (i+1));
  }

  long long min = INF;
  for (int i=0; i<=N; i++) {
    chmin(min, ldp[i] + rdp[N-i]);
  }

  cout << min << endl;
}
