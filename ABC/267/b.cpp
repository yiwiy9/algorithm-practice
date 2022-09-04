#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string S;
  cin >> S;

  if (S[0] == '1') {
    cout << "No" << endl;
    return 0;
  }

  vector<bool> line(7);
  line[0] = S[6]=='1';
  line[1] = S[3]=='1';
  line[2] = (S[1]=='1' || S[7]=='1');
  line[3] = S[4]=='1';
  line[4] = (S[2]=='1' || S[8]=='1');
  line[5] = S[5]=='1';
  line[6] = S[9]=='1';

  bool ok = false;
  bool split = false;
  for (int i=0; i<7; i++) {
    if (line[i]) {
      if (!split) {
        split = true;
        continue;
      }
      if (!line[i-1]) {
        ok = true;
        break;
      }
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
