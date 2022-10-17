#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string X;
  int K;
  cin >> X >> K;

  reverse(X.begin(), X.end());

  for (int i=0; i<K; i++) {
    if ((int)(X[i] - '0') < 5){
      X[i] = '0';
      continue;
    }

    X[i] = '0';

    while(true) {
      if (i+1 == X.size()) X += "0";
      int next = (int)(X[i+1] - '0') + 1;
      if (next != 10) {
        X[i+1] = (char)(next + '0');
        break;
      } else {
        X[i+1] = '0';
        i++;
      }
    }
  }

  reverse(X.begin(), X.end());

  bool all_zero = true;
  for (auto d : X) {
    if (d != '0') {
      all_zero = false;
      break;
    }
  }

  if (all_zero) cout << '0' << endl;
  else cout << X << endl;
}
