#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template<typename T>
size_t countDigits(T n)
{
    string tmp;

    tmp = to_string(n);
    return tmp.size();
}

long long calcAllByDigits(int digits) {
  long long sum = 0;
  long long before = 0;
  for (int i=1; i<=digits; i++) {
    long long current = pow(10, i) - 1;
    sum += (current * (current+1)) / 2 - (current * before) - (before * (before+1)) / 2 + (before * before);

    before = current;
  }
  return sum;
}

int main()
{
  long long N;
  cin >> N;

  int digits = countDigits(N);

  long long sum = calcAllByDigits(digits - 1);
  long long before = pow(10, digits - 1) - 1;
  sum += (N * (N+1)) / 2 - (N * before) - (before * (before+1)) / 2 + (before * before);

  cout << sum % 998244353 << endl;
}
