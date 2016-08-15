#include <iostream>

using namespace std;

int main()
{
    const auto e = 3; // Number of elements
    int a[e], b[e]; // Alice and Bob
    auto scoreA = 0, scoreB = 0; // Alice's and Bob's scores

    for (auto i = 0; i < e; ++i)
    {
        cin >> a[i];
    }

    for (auto i = 0; i < e; ++i)
    {
        cin >> b[i];
    }

    for (auto i = 0; i < e; ++i)
    {
        if (a[i] > b[i])
        {
            scoreA++;
        }
        else if (a[i] < b[i])
        {
            scoreB++;
        }
    }

    cout << scoreA << " " << scoreB << endl;

    return 0;
}
