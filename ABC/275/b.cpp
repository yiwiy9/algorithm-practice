#include <iostream>
using namespace std;

const long long MOD = 998244353;

int main()
{
  long long A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  long long l = (((A % MOD)*(B % MOD)%MOD)*(C % MOD)%MOD);
  long long r = (((D % MOD)*(E % MOD)%MOD)*(F % MOD)%MOD);

  long long ans = ((l-r)%MOD + MOD) % MOD;
  cout << ans << endl;
}
