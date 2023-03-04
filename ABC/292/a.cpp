#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string S;
    string T;
    cin >> S;
    for (char c : S)
    {
        T += toupper(c);
    }

    cout << T << endl;
}
