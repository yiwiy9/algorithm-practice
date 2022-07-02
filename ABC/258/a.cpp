#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int K;
  cin >> K;

  int hour, minute;
  hour = K / 60;
  minute = K % 60;

  cout << 21+hour;
  cout << ':';
  if (minute < 10) cout << 0 << minute << endl;
  else cout << minute << endl;
}
