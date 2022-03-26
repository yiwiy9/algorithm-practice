#include <iostream>
using namespace std;

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  if (A > C) {
    cout << "Aoki" << endl;
  } else if (A == C && B > D) {
    cout << "Aoki" << endl;
  } else {
    cout << "Takahashi" << endl;
  }
}
