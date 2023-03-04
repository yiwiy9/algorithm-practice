#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> divisors(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            divisors[j]++;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N / 2; i++)
    {
        int j = N - i;

        if (i == j)
        {
            ans += divisors[i] * divisors[j];
        }
        else
        {
            ans += divisors[i] * divisors[j] * 2;
        }
    }

    cout << ans << endl;
}
