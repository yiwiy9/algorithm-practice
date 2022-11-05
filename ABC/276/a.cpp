#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int ans = -1;
  for (int i=(int)S.size()-1; i>=0; i--) {
    if (S[i] == 'a') {
      ans = i+1;
      break;
    }
  }
  cout << ans << endl;
}
