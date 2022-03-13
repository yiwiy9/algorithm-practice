#include <iostream>
#include <string>
using namespace std;

const long long INF = 1ll << 60;

int main()
{
  int N;
  long long X;
  string S;
  cin >> N >> X >> S;

  int over_cnt = 0;
  for (auto c : S) {
    if (over_cnt > 0) {
      if (c == 'U') over_cnt--;
      else over_cnt++;
      continue;
    }


    if (c == 'U') {
      if (X % 2 == 0) {
        X /= 2;
      } else {
        X--;
        X /= 2;
      }
    }

    if (X > INF / 2) {
      over_cnt = 1;
      continue;
    }

    if (c == 'R') {
      X *= 2;
      X++;
    }

    if (c == 'L') {
      X *= 2;
    }
  }
  cout << X << endl;
}
