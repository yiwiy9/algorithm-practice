#include <iostream>
#include <list>
using namespace std;

int main()
{
  int N;
  cin >> N;
  list<int> A;
  for (int i=0; i<N; i++) {
    int a;
    cin >> a;
    A.push_front(a);
    cout << "push: " << a << endl;
  }

  for (int i=0; i<N; i++) {
    int a;
    a = A.front();
    A.pop_front();
    cout << "pop: " << a << endl;
  }
}
