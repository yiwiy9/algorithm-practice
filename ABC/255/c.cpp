#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long inf = 1 << 30;

int main()
{
  long long X, A, D, N;
  cin >> X >> A >> D >> N;

  if (X > inf && A < -inf) {
    long long use_N = min(inf/D, N);
    X -= D*use_N;
    N -= use_N;
  }
  if (X < -inf && A > inf) {
    long long use_N = min(abs(-inf/D), N);
    X += abs(D*use_N);
    N -= use_N;
  }

  long long B = X - A;
  if (B == 0) {
    cout << 0 << endl;
    exit(0);
  }
  if (D == 0 || D*B < 0) {
    cout << abs(B) << endl;
    exit(0);
  }

  B = abs(B);
  D = abs(D);
  if (B/D <= N) {
    long long amari = B%D;
    long long amari_i = D-amari;
    cout << min(amari, amari_i) << endl;
    exit(0);
  }

  cout << B - (D*N) << endl;
}
