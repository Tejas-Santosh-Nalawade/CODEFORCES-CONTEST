#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[40][40];

void precompute() {
    for (int i = 0; i < 35; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    int pow = 0;
    while ((1LL << (pow + 1)) <= n) {
        pow++;
    }

    int number = 0;
    if (pow + 1 > k) {
        number++;
    }

    for (int i = 0; i < pow; i++) {
        int requirement = k - i;
        if (requirement < 0) requirement = 0;
        
        for (int j = requirement; j <= i; j++) {
            number += dp[i][j];
        }
    }
    cout << number << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int tt; cin >> tt;
    while (tt--) solve();
}