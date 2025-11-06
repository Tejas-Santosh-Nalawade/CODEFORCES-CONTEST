#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

void solve() {
    int n, k_max;
    cin >> n >> k_max;
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << endl;
        return;
    }

    if (s[0] != t[0]) {
        cout << -1 << endl;
        return;
    }

    int max_k = 0;
    vector<int> sources(n);
    map<char, int> last_seen;
    bool possible = true;

    for (int i = 0; i < n; i++) {
        last_seen[s[i]] = i; 

        char target = t[i];
        if (last_seen.find(target) == last_seen.end()) {
            possible = false;
            break;
        }

        int j = last_seen[target];
        sources[i] = j;
        int dist = i - j;
        max_k = max(max_k, dist);
    }

    if (!possible || max_k > k_max) {
        cout << -1 << endl;
        return;
    }
    cout << max_k << endl;
    string current_s = s;

    for (int k = 1; k <= max_k; k++) {
        string new_s(n, ' ');
        new_s[0] = current_s[0];

        for (int i = 1; i < n; ++i) {
            int j = sources[i];
            int dist = i - j;

            if (k <= dist)
                new_s[i] = current_s[i - 1]; 
            else
                new_s[i] = current_s[i];
        }

        cout << new_s << endl;
        current_s = new_s;
    }
}

int32_t main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
