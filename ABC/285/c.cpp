#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;

    long long ans = 0;
    long long pow = 1;
    for (int i = (int)S.size() - 1; i >= 0; i--)
    {
        ans += pow * (long long)(S[i] - 'A' + 1);
        pow *= 26;
    }
    cout << ans << endl;
}
