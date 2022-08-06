#include <iostream>
#include <map>
using namespace std;

int main()
{
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;

  map<int, int> m;
  m[A]++;
  m[B]++;
  m[C]++;
  m[D]++;
  m[E]++;

  if (m.size() != 2) cout << "No" << endl;
  else if (m[A] == 1 || m[A] == 4) cout << "No" << endl;
  else  cout << "Yes" << endl;
}
