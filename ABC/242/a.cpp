#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double A, B, C, X;
  cin >> A >> B >> C >> X;

  double res;
  if (X <= A) {
    res = 1;
  } else if (X > B) {
    res = 0;
  } else {
    res = C / (B - A);
  }

  cout << fixed << setprecision(10) << res << endl;
}
