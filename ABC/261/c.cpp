#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  int N;
  cin >> N;

  map<string, int> m;
  for (int i=0; i<N; i++) {
    string s;
    cin >> s;

    if (m.find(s) == m.end()) {
      cout << s << endl;
    } else {
      cout << s+'(' << m[s] << ')' << endl;
    }

    m[s]++;
  }
}
