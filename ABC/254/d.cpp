#include <iostream>
using namespace std;

int main()
{
  long long N;
  cin >> N;

  long long res = 0;
  for (long long i=1; i<=N; i++) {
    long long k = i*i;

    for (long long j=i; j>=1; j--) {

      if (k % j == 0) {
        long long r = k/j;
        if (r > N) break;

        res++;
        if (r != j) res++;
      }
    }
  }

  cout << res << endl;
}
