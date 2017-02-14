#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (auto i = 0; i < n; ++i)
    {
        for (auto u = 0; u < n; ++u)
        {
            // Left padding
            // i = number of spaces
            // Example: i == 2
            // _ _ # (2 space left padding)
            if (u < (n - 1) - i)
            {
                cout << " ";
            } else
            {
                cout << "#";
            }
        }

        cout << endl;
    }

    return 0;
}