#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int A, B, C, D, E, F, X;
  cin >> A >> B >> C >> D >> E >> F >> X;

  long long takahashi = 0;
  long long aoki = 0;

  takahashi += (X / (A+C)) * B * A;
  aoki += (X / (D+F)) * E * D;

  takahashi += min(X % (A+C), A) * B;
  aoki += min(X % (D+F), D) * E;


  if (takahashi == aoki) cout << "Draw" << endl;
  else if (takahashi > aoki) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}
