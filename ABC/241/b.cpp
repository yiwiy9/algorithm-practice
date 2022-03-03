#include <iostream>
#include <map>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  map<int, int> A;
  int a;
  for (int i=0; i<N; i++) {
    cin >> a;
    A[a]++;
  }

  bool ok = true;
  int b;
  for (int i=0; i<M; i++) {
    cin >> b;
    if (A[b] == 0)
    {
      ok = false;
      break;
    }
    A[b]--;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
