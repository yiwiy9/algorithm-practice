#include <iostream>
#include <string>
using namespace std;

int main()
{
  string N;
  cin >> N;

  int digits = N.size();
  cout << N[digits-2];
  cout << N[digits-1] << endl;
}
