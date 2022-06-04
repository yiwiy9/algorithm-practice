#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<vector<int>> A(30, vector<int>(30));
  for (int i=0; i<N; i++) {
    for (int j=0; j<=i; j++) {
      if (j==i) {
        A[i][j] = 1;
        cout << A[i][j] << endl;
      } else if (j==0) {
        A[i][j] = 1;
        cout << A[i][j] << " ";
      } else {
        A[i][j] = A[i-1][j-1] + A[i-1][j];
        cout << A[i][j] << " ";
      }
    }
  }
}
