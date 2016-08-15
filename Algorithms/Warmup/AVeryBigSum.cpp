#include <iostream>

using namespace std;

int main()
{
    int n;
    long sum = 0;
    cin >> n;

    for (auto i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        sum += t;
    }

    cout << sum << endl;

    return 0;
}