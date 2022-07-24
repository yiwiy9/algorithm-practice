#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
  int N;
  string S;
  cin >> N >> S;

  vector<pair<int, int>> ans;
  stack<pair<char, int>> st;
  for (int i=0; i<(int)S.size(); i++) {
    if (st.empty()) {
      st.push({S[i], i+1});
      continue;
    }

    if (st.top().first == '(' && S[i] == ')') {
      ans.push_back({st.top().second, i+1});
      st.pop();
      continue;
    }

    st.push({S[i], i+1});
  }

  if (!st.empty()) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (auto a: ans) {
      cout << a.first << "番目と" << a.second << "番目" << endl;
    }
  }
}
