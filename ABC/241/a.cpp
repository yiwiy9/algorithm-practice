#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> a(10);
  for (int i=0; i<10; i++) {
    cin >> a[i];
  }

  int res = a[0];
  res = a[res];
  res = a[res];
  cout << res << endl;
}
