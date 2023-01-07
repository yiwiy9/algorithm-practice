#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    string S;
    set<string> s;
    for (int i = 1; i <= N; i++)
    {
        cin >> S;
        if (s.find(S) == s.end())
        {
            s.insert(S);
            cout << i << endl;
        }
    }
}
