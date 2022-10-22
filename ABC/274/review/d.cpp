#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, x, y;
  cin >> N >> x >> y;

  vector<int> X, Y;
  int A;
  cin >> A;
  x -= A;
  for (int i=1; i<=N-1; i++) {
    cin >> A;
    if (i%2 == 0) X.push_back(A);
    else Y.push_back(A);
  }

  vector<vector<bool>> dpX((int)X.size()+1, vector<bool>(20001, false));
  dpX[0][10000] = true;
  for (int i=0; i<(int)X.size(); i++) {
    for (int j=0; j<20001; j++) {
      if (dpX[i][j] == false) continue;
      if (j+X[i] < 20001) dpX[i+1][j+X[i]] = true;
      if (j-X[i] >= 0) dpX[i+1][j-X[i]] = true;
    }
  }

  vector<vector<bool>> dpY((int)Y.size()+1, vector<bool>(20001, false));
  dpY[0][10000] = true;
  for (int i=0; i<(int)Y.size(); i++) {
    for (int j=0; j<20001; j++) {
      if (dpY[i][j] == false) continue;
      if (j+Y[i] < 20001) dpY[i+1][j+Y[i]] = true;
      if (j-Y[i] >= 0) dpY[i+1][j-Y[i]] = true;
    }
  }

  if (dpX[(int)X.size()][x+10000] && dpY[(int)Y.size()][y+10000]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
