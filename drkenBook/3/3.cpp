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

  long long first_min  = INF;
  long long second_min = INF + 1;
  for (int i=0; i<N; i++) {
    if (a[i] < first_min) {
      second_min = first_min;
      first_min  = a[i];
      continue;
    }
    if (a[i] < second_min) {
      second_min  = a[i];
    }
  }

  cout << second_min << endl;
}
