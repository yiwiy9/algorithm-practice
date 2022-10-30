#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;
long long rec(long long n)
{
  if (n==0) return 1;

  if (m.find(n) != m.end()) return m[n];

  return rec(n/2) + rec(n/3);
}

int main()
{
  long long N;
  cin >> N;

  cout << rec(N) << endl;
}
