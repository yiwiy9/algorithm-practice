#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  long long X, A, D, N;
  cin >> X >> A >> D >> N;

  long long B = X - A;
  N--;
  if (B == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (D == 0 || (D < 0 && B > 0) || (D > 0 && B < 0)) {
    cout << abs(B) << endl;
    return 0;
  }

  B = abs(B);
  D = abs(D);
  if (B <= D*N) {
    long long amari = B%D;
    long long amari_i = D-amari;
    cout << min(amari, amari_i) << endl;
    return 0;
  }

  cout << (B - (D*N)) << endl;
}
