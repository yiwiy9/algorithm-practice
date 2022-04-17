#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string S;
  cin >> S;

  vector<bool> memo(10, false);

  for (auto c : S) {
    memo[int(c-'0')] = true;
  }

  for (int i=0; i<10; i++) {
    if (memo[i] == false) {
      cout << i;
    }
  }
  cout << endl;
}
