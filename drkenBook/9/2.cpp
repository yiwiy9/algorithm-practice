#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int N;
  cin >> N;

  stack<double> st;
  for (int i=0; i<N; i++) {
    char c;
    cin >> c;

    if (c >= '0' && c <= '9') { // 数字の場合
      double num = c - '0';
      st.push(num);
    } else { // 演算子の場合
      double a = st.top();
      st.pop();
      double b = st.top();
      st.pop();

      if (c == '+') st.push(b+a);
      else if  (c == '-') st.push(b-a);
      else if  (c == '*') st.push(b*a);
      else st.push(b/a);
    }
  }

  cout << st.top() << endl;
}
