#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int size = (int) S.size();
  if (size != 8) {
    cout << "No" << endl;
    return 0;
  }

  if (S[0] < 'A' || S[0] > 'Z') {
    cout << "No" << endl;
    return 0;
  }

  if (S[size-1] < 'A' || S[size-1] > 'Z') {
    cout << "No" << endl;
    return 0;
  }

  if (S[1] == '0') {
    cout << "No" << endl;
    return 0;
  }

  for (int i=1; i < size-1; i++) {
    if (S[i] < '0' || S[i] > '9') {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
