#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  long long N;
  cin >> N;

  if (pow(2, N) > pow(N, 2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
