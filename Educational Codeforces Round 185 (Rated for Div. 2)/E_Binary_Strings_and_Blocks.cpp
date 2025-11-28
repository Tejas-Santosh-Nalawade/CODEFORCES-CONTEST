#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<int> max_l(n + 1, 0);
    for(int i = 0; i < m; ++i){
        int l, r; 
        cin >> l >> r;
        max_l[r] = max(max_l[r], l);
    }

    vector<int> dp(n + 1, 0);
    

    dp[0] = 1;

    // Sliding Window Variables
    int current_sum = 1; // Initially contains dp[0]
    int left_ptr = 0;    // The start of our summation window
    int limit = 0;       // The required start constraint

    for(int i = 1; i <= n; ++i){
        limit = max(limit, max_l[i]);
        while(left_ptr < limit){
            current_sum = (current_sum - dp[left_ptr] + MOD) % MOD;
            left_ptr++;
        }
        dp[i] = current_sum;
        current_sum = (current_sum + dp[i]) % MOD;
    }

    cout << (dp[n] * 2) % MOD << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) solve();
}
