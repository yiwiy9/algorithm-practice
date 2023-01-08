#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            if (a % 2 != 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
