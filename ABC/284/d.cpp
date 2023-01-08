#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        long long N;
        cin >> N;

        long long a = 2;
        for (; a * a <= N; a++)
        {
            if (N % a == 0)
            {
                N /= a;
                break;
            }
        }

        if (N % a == 0)
        {
            cout << a << ' ' << N / a << endl;
        }
        else
        {
            cout << (int)sqrt(N) << ' ' << a << endl;
        }
    }
}
