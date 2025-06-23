#include <bits/stdc++.h>
using namespace std;

bool is_beautiful(const vector<int>& b) {
    if (b.size() < 2) {
        return false;
    }
    for (size_t i = 0; i + 1 < b.size(); ++i) {
        if (abs(b[i] - b[i+1]) <= 1) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = 1e9 + 7;
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        min_val = min(min_val, a[i]);
        max_val = max(max_val, a[i]);
    }
    if (is_beautiful(a)) {
        std::cout << 0 << "\n";
        return;
    }

    if (n == 2) {
        cout << -1 << "\n";
        return;
    }
    cout << 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}

