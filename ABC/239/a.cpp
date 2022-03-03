#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double a = 12800000;

int main()
{
  double H;
  cin >> H;

  double ans = sqrt(H*(a+H));

  cout << setprecision(7) << ans << endl;
}
