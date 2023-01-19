#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    for (int i = 1; i < N; i++)
    {
        int l = 0;
        for (; l + i < N; l++)
        {
            if (S[l] == S[l + i])
            {
                break;
            }
        }
        cout << l << endl;
    }
}
