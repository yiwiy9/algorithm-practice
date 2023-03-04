#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> point(N + 1);

    for (int i = 0; i < Q; i++)
    {
        int c, x;
        cin >> c >> x;

        if (c == 1)
        {
            point[x] += 1;
        }
        else if (c == 2)
        {
            point[x] += 2;
        }
        else
        {
            if (point[x] >= 2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    cout << endl;
}
