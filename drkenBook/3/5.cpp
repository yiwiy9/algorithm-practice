#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  int count = 0;
  bool can = true;
  while (can)
  {
    for (int i = 0; i < N; i++)
    {
      if (a[i] % 2 != 0) {
        can = false;
        break;
      }
      a[i] /= 2;
    }
    if (can) {
      count++;
    }
  }


  cout << count << endl;
}
