#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int loop = 6 / S.size();

  for (int i=0; i<loop; i++) {
    cout << S;
  }
  cout << endl;
}
