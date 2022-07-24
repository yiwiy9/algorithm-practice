#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<vector<char>> A(N, vector<char>(N));
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
    }
  }

  bool ok = true;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      auto current = A[i][j];

      if (current == '-') continue;

      if (current == 'W') {
        if (A[j][i] != 'L') {
          ok = false;
          break;
        }
      }

      if (current == 'D') {
        if (A[j][i] != 'D') {
          ok = false;
          break;
        }
      }

      if (current == 'L') {
        if (A[j][i] != 'W') {
          ok = false;
          break;
        }
      }
    }
    if (!ok) break;
  }

  if (ok) cout << "correct" << endl;
  else cout << "incorrect" << endl;
}
