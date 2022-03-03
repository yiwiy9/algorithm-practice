#include <iostream>
using namespace std;

long long K;
int count = 0;

void rec(long long num, int digit, int selected_bit)
{
  if (num > K) return;

  if (selected_bit == 7) count++;

  rec(num + (3*digit), digit*10, selected_bit | 1 << 0);
  rec(num + (5*digit), digit*10, selected_bit | 1 << 1);
  rec(num + (7*digit), digit*10, selected_bit | 1 << 2);
}

int main()
{
  cin >> K;
  rec(0, 1, 0);
  cout << count << endl;
}
