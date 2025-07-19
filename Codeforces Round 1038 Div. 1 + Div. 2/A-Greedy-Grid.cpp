#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
     if (min(n, m) >= 2 && (n >= 3 || m >= 3)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}