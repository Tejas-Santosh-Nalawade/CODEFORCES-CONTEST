#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (a.back() != b.back()) {
        cout << "NO\n";
        return;
    }

    vector<long long> prefixXOR(n + 1, 0);
    for (int i = 0; i < n; i++) prefixXOR[i + 1] = prefixXOR[i] ^ b[i];

    map<long long, vector<int>> pos;
    for (int i = 0; i <= n; i++) pos[prefixXOR[i]].push_back(i);

    bool canTransform = true;
    for (int i = n - 2; i >= 0; i--) {
        long long need = a[i] ^ b[i] ^ prefixXOR[i];
        if (pos.find(need) == pos.end() || pos[need].empty()) {
            canTransform = false;
            break;
        }
        int idx = pos[need].back();
        pos[need].pop_back();
        if (idx <= i) {
            canTransform = false;
            break;
        }
    }

    cout << (canTransform ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
