#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    P--, Q--, R--, S--;

    int sub = R - P;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;

        if (i >= P && i <= Q)
        {
            A[i + sub] = a;
        }
        else if (i >= R && i <= S)
        {
            A[i - sub] = a;
        }
        else
        {
            A[i] = a;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
            cout << A[i] << ' ';
        else
            cout << A[i] << endl;
    }
}
