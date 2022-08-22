#include <iostream>
using namespace std;

int main()
{
  int X, Y, N;
  cin >> X >> Y >> N;

  if (N < 3 || 3*X < Y) {
    cout << X * N << endl;
  } else {
    int div = N / 3;
    int amari = N % 3;
    cout << X * amari + Y * div << endl;
  }
}
