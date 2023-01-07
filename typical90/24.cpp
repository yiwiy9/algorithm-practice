#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++)
  {
    cin >> B[i];
  }

  int diff_sum = 0;
  for (int i = 0; i < N; i++)
  {
    diff_sum += abs(A[i] - B[i]);
  }

  if (diff_sum > K)
  {
    cout << "No" << endl;
  }
  else if ((diff_sum - K) % 2 != 0)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}
