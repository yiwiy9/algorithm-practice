#include <iostream>
using namespace std;

int func(int num)
{
  if (num == 0) return 1;
  return num * func(num - 1);
}

int main()
{
  int N;
  cin >> N;
  cout << func(N) << endl;
}
