#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int L1, R1, L2, R2;
  cin >> L1 >> R1 >> L2 >> R2;

  if (L1 >= R2 || L2 >= R1) cout << 0 << endl;
  else cout << min(R1,R2) - max(L1,L2) << endl;
}
