#include <iostream>
using namespace std;

bool ok(int H, int M)
{
  int A, B, C, D;

  A = H / 10;
  B = H % 10;
  C = M / 10;
  D = M % 10;

  int h, m;
  h = 10 * A + C;
  m = 10 * B + D;

  if (h >= 24) return false;
  if (m >= 60) return false;
  return true;
}

int main()
{
  int H, M;
  cin >> H >> M;

  while (true)
  {
    if (ok(H, M)) break;

    if (M == 59) {
      if (H == 23) {
        H = 0;
        M = 0;
      } else {
        H++;
        M = 0;
      }
    } else {
      M++;
    }
  }

  cout << H << ' ' << M << endl;
}
