#include <iostream>
#include <set>
using namespace std;

int main()
{
  set<int> s;
  for (int i=0; i<5; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }

  cout << s.size() << endl;
}
