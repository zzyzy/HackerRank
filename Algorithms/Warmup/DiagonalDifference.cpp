#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> m(n);

    for (auto i = 0; i < n; ++i)
    {
        vector<int> r(n, 0);

        for (auto u = 0; u < n; ++u)
        {
            cin >> r[u];
        }

        m[i] = r;
    }

    auto sum1 = 0, sum2 = 0;

    for (auto i = 0; i < n; ++i)
    {
        sum1 += m[i][i];
        sum2 += m[i][n - 1 - i];
    }

    if (sum1 > sum2)
    {
        cout << sum1 - sum2;
    }
    else
    {
        cout << sum2 - sum1;
    }

    cout << endl;

    return 0;
}
