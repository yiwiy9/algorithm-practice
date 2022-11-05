#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 30;

int GCD(int a, int b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  int min_a = inf;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    min_a = min(min_a, A[i]);
  }

  while (min_a % 2 == 0) min_a /= 2;
  while (min_a % 3 == 0) min_a /= 3;

  bool ok = true;
  for (int i=0; i<N; i++) {
    if (A[i] % min_a != 0) {
      ok = false;
      break;
    }
    A[i] /= min_a;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  int gcd = A[0];
  for (int i=1; i<N; i++) {
    gcd = GCD(gcd, A[i]);
  }

  int ans = 0;
  for (int i=0; i<N; i++) {
    int b = A[i] / gcd;
    while (b % 2 == 0) {
      b /= 2;
      ans++;
    }
    while (b % 3 == 0) {
      b /= 3;
      ans++;
    }
    if (b != 1) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  cout << ans << endl;
}
