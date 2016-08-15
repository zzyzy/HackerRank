#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n, 0);
    auto nve = 0, pve = 0, zero = 0;

    for (auto i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            nve++;
        } else if (a[i] > 0)
        {
            pve++;
        } else
        {
            zero++;
        }
    }

    cout << pve / static_cast<float>(n) << endl;
    cout << nve / static_cast<float>(n) << endl;
    cout << zero / static_cast<float>(n) << endl;

    return 0;
}