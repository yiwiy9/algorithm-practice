#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++)
    {
        if (i != N && S[i - 1] == 'n' && S[i] == 'a')
        {
            cout << "nya";
            i++;
        }
        else
        {
            cout << S[i - 1];
        }
    }
    cout << endl;
}
