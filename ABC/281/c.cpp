#include <iostream>
#include <vector>
using namespace std;

int main()
{
  long long N, T;
  cin >> N >> T;

  vector<long long> A(N+1);
  long long total = 0;
  for (long long i=1; i<=N; i++) {
    cin >> A[i];
    total += A[i];
  }

  T %= total;

  for (long long i=1; i<=N; i++) {
    if (T-A[i] < 0) {
      cout << i << ' ' << T << endl;
      return 0;
    }
    T -= A[i];
  }
}
