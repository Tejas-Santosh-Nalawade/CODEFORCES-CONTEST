#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;

    int SZ = 1LL << n;
    vector<char> used(SZ, 0);
    vector<int> out;
    out.reserve(SZ);

    for (int bit = n; bit >= -1; --bit) {
        int base = (bit < 0 ? 0 : ((1LL << bit) - 1));

        for (int x = base; x < SZ; ++x) {
            if (used[x]) continue;
            if ((x & base) != base) continue;

            used[x] = 1;
            out.push_back(x);
        }
    }

    for (int i = 0; i < SZ; ++i) {
        cout << out[i];
        if (i + 1 < SZ) cout << ' ';
    }
    cout << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; 
    cin >> tt;
    while (tt--) solve();
}
