#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int sum = 0;
  for (int bit=0; bit < (1 << (S.size()-1)); bit++) {
    int before_i = 0;
    for (int i = 0; i < S.size(); i++)
    {
      if (bit & (1<<i)) {
        int len = i + 1 - before_i;
        sum += stoi(S.substr(before_i, len));
        before_i = i + 1;
      }
    }
    sum += stoi(S.substr(before_i));
  }

  cout << sum << endl;
}
