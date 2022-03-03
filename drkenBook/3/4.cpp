#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  long long min = INF;
  long long max = INF * (-1);
  for (int i=0; i<N; i++) {
    if (a[i] < min) {
      min = a[i];
    }
    if (a[i] > max) {
      max = a[i];
    }
  }

  cout << max - min << endl;
}
