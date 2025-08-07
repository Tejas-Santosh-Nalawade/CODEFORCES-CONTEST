#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int x;
    cin >> n >> x;
    string s;
    cin >> s;

    int walls_left = 0;
    for (int i = 0; i < x - 1; ++i) {
        if (s[i] == '#') {
            walls_left++;
        }
    }

    int walls_right = 0;
    for (int i = x; i < n; ++i) {
        if (s[i] == '#') {
            walls_right++;
        }
    }
    int cost_l = (x - 1) + walls_right;

    int cost_r = (n - x) + walls_left;
    cout << min(cost_l, cost_r) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}