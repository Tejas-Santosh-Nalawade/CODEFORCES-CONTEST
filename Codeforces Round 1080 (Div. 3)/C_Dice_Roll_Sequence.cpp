#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(7);
    for(int i = 1; i <= 6; i++) {
        dp[i] = (a[0] == i) ? 0 : 1;
    }

    for(int i = 1; i < n; ++i) {
        vector<int> dp_next(7);
        for(int vj= 1; vj <= 6; vj++) {
            int prize = (a[i] == vj) ? 0 : 1;
            int min_prev = 1e18;
            for(int ui = 1; ui <= 6; ui++) {
                if (ui != vj && ui + vj != 7) {
                    if (dp[ui] < min_prev) {
                        min_prev = dp[ui];
                    }
                }
            }
            dp_next[vj] = prize + min_prev;
        }
        dp = dp_next;
    }

    int ans = 1e18;
    for(int v = 1; v <= 6; ++v) {
        if (dp[v] < ans) {
            ans = dp[v];
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}