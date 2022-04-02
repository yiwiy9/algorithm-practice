#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double A, B;
  cin >> A >> B;

  double C = sqrt(A*A + B*B);
  double x = A / C;
  double y = B / C;
  cout << setprecision(7) << x << " ";
  cout << setprecision(7) << y << endl;
}
