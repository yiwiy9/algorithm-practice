#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> ans_line;

  for (int i=1; i<=N; i++) {
    cout << i << ' ';
    ans_line.push_back(i);

    int ni = pow(2, i-1) - 2; // 2^1 - 1 (before) - 1 (index)
    for (int j=ni; j>=0; j--) {
      cout << ans_line[j] << ' ';
      ans_line.push_back(ans_line[j]);
    }
  }
  cout << endl;
}
