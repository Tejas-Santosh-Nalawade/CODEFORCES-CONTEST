#include <bits/stdc++.h>
using namespace std;

const long long MOD = 676767677;

// Check if the constructed cape arrangement matches the visibility array
bool isArrangementValid(const vector<int>& vis, const vector<int>& cape) {
    int n = vis.size();

    // Compute prefix sums of L capes
    vector<int> prefixL(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixL[i + 1] = prefixL[i] + (cape[i] == 0);
    }

    // Compute suffix sums of R capes
    vector<int> suffixR(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffixR[i] = suffixR[i + 1] + (cape[i] == 1);
    }

    // Verify each position
    for (int i = 0; i < n; i++) {
        int L = prefixL[i + 1];
        int R = suffixR[i];
        if (L + R != vis[i]) return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) cin >> vis[i];

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    if (n == 1) {
        cout << (vis[0] == 1 ? 2 : 0) << "\n";
        return;
    }

    long long totalWays = 0;

    // Try both possibilities for the first cape
    for (int firstCape = 0; firstCape <= 1; firstCape++) {
        vector<int> cape(n);
        cape[0] = firstCape;
        bool valid = true;

        // Construct the rest based on differences in visibility
        for (int i = 0; i < n - 1; i++) {
            int diff = vis[i + 1] - vis[i];
            int curr = cape[i];

            if (abs(diff) > 1) {
                valid = false;
                break;
            }

            if (diff == 1) {       // Next must be L
                if (curr == 1) { valid = false; break; }
                cape[i + 1] = 0;
            } else if (diff == -1) { // Next must be R
                if (curr == 0) { valid = false; break; }
                cape[i + 1] = 1;
            } else {                // Toggle if diff == 0
                cape[i + 1] = 1 - curr;
            }
        }

        if (!valid) continue;

        if (isArrangementValid(vis, cape)) {
            totalWays = (totalWays + 1) % MOD;
        }
    }

    cout << totalWays << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) solve();

    return 0;
}
