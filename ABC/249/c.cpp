#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  int N, K;
  cin >> N >> K;

  vector<string> S(N);
  for (int i=0; i<N; i++ ) cin >> S[i];

  int max = 0;
  for (long long bit=0; bit<(1 << N); bit++) {
    map<char, int> map;
    for (int i=0; i<N; i++) {
      if (bit & (1 << i)) {
        for (auto c : S[i]) {
          map[c]++;
        }
      }
    }

    int count = 0;
    for (const auto& [key, value] : map){
      if (value == K) count++;
    }
    chmax(max, count);
  }

  cout << max << endl;
}
