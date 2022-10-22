#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, x, y;
  cin >> N >> x >> y;

  vector<int> X(11), Y(11);
  int A;
  cin >> A;
  x -= A;
  for (int i=1; i<=N; i++) {
    cin >> A;
    if (i%2 == 0) X[A]++;
    else Y[A]++;
  }

  vector<vector<bool>> dpX(11, vector<bool>(20001, false));
  dpX[0][10000] = true;
  for (int i=1; i<=10; i++) {
    for (int j=0; j<20001; j++) {
      if (dpX[i-1][j] == false) continue;

      for (int k=(X[i]%2); k<=X[i]; k+=2) {
        dpX[i][j-k] = true;
        dpX[i][j+k] = true;
      }
    }
  }

  vector<vector<bool>> dpY(11, vector<bool>(20001, false));
  dpY[0][10000] = true;
  for (int i=1; i<=10; i++) {
    for (int j=0; j<20001; j++) {
      if (dpY[i-1][j] == false) continue;

      for (int k=(Y[i]%2); k<=Y[i]; k=k+2) {
        dpY[i][j-k] = true;
        dpY[i][j+k] = true;
      }
    }
  }

  if (dpX[10][x+10000] && dpY[10][y+10000]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
