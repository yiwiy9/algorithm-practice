#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  long long N;
  cin >> N;

  long long a;
  map<long long, long long> map_num;
  for (long long i=0; i<N; i++) {
    cin >> a;
    map_num[a]++;
  }

  long long ans = N * (N-1) * (N-2) / 6;
  for (const auto& [num, cnt] : map_num) {
    long long sub_2 = cnt * (cnt-1) / 2 * (N-cnt);
    ans -= sub_2;
    long long sub_3 = cnt * (cnt-1) * (cnt-2) / 6;
    ans -= sub_3;
  }

  cout << ans << endl;
}
