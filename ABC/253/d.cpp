#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
  return a * b / GCD(a, b);
}

int main()
{
  long long N, A, B, AB_lcm;
  cin >> N >> A >> B;
  AB_lcm = LCM(A, B);

  long long A_m, B_m, AB_m;
  A_m = N / A;
  B_m = N / B;
  AB_m = N / AB_lcm;

  long long ans = 0;
  ans += N * (N+1) / 2;
  ans -= A * A_m * (A_m+1) / 2;
  ans -= B * B_m * (B_m+1) / 2;
  ans += AB_lcm * AB_m * (AB_m+1) / 2;

  cout << ans << endl;
}
