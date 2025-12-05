#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200005;
static bool flagp[MAXN];
static vector<int> primeset;

void build() {
    memset(flagp, 1, sizeof(flagp));
    flagp[0] = flagp[1] = 0;
    for (int i = 2; 1LL * i * i < MAXN; i++) {
        if (!flagp[i]) continue;
        for (long long j = 1LL * i * i; j < MAXN; j += i)
            flagp[j] = 0;
    }
    for (int i = 2; i < MAXN; i++)
        if (flagp[i]) primeset.push_back(i);
}

void work() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int m = v.size();

    for (auto x : v) {
        if (k / x > m) {
            cout << -1 << "\n";
            return;
        }
    }

    for (auto x : v) {
        for (auto p : primeset) {
            long long t = x * p;
            if (t > k) break;
            if (!binary_search(v.begin(), v.end(), t)) {
                cout << -1 << "\n";
                return;
            }
        }
    }

    vector<char> keep(m, 1);

    for (int i = 0; i < m; i++) {
        long long base = v[i];
        for (auto p : primeset) {
            long long t = base * p;
            if (t > k) break;
            auto it = lower_bound(v.begin(), v.end(), t);
            if (it != v.end() && *it == t) keep[it - v.begin()] = 0;
        }
    }

    vector<long long> out;
    for (int i = 0; i < m; i++)
        if (keep[i]) out.push_back(v[i]);

    cout << out.size() << "\n";
    for (int i = 0; i < (int)out.size(); i++) {
        cout << out[i];
        if (i + 1 < (int)out.size()) cout << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build();

    int tt;
    cin >> tt;
    while (tt--) work();

    return 0;
}
