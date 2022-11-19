#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

int main()
{
  long long A, B, C;
  cin >> A >> B >> C;

  long long gcd = GCD(A, B);
  gcd = GCD(gcd, C);

  long long ans = 0;
  ans += A / gcd - 1;
  ans += B / gcd - 1;
  ans += C / gcd - 1;

  cout << ans << endl;
}
