#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  cout << fixed << setprecision(3) << (double)B / A << endl;
}
