#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> swords;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        swords.insert(a);
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    vector<pair<int, int>> transformers; 
    vector<int> terminators;           

    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        if (c == 0) terminators.push_back(b[i]);
        else transformers.push_back({b[i], c});
    }

    sort(transformers.begin(), transformers.end());
    sort(terminators.begin(), terminators.end());

    int killed = 0;

    for (auto it = transformers.begin(); it != transformers.end(); ++it) {
        int health = it->first;
        int reward = it->second;

        auto sword_it = swords.lower_bound(health);
        if (sword_it == swords.end()) break;

        int sword = *sword_it;
        swords.erase(sword_it);
        swords.insert(max(sword, reward));
        killed++;
    }
    for (int health : terminators) {
        auto it = swords.lower_bound(health);
        if (it != swords.end()) {
            swords.erase(it);
            killed++;
        }
    }

    cout << killed << endl;
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
