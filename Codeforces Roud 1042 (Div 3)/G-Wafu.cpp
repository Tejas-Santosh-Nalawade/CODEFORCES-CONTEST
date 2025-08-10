#include <bits/stdc++.h>
using namespace std;

const int MAX_PRECOMP = 62;
const long long MOD = 1e9+7;

long long P_mod[MAX_PRECOMP], ops_needed[MAX_PRECOMP];

void precompute() {
    P_mod[0] = 1;
    ops_needed[0] = 0;
    for (int i = 1; i < MAX_PRECOMP; i++) {
        long long sq = (P_mod[i-1]*P_mod[i-1]) % MOD;
        P_mod[i] = (sq * i) % MOD;
        ops_needed[i] = 2*ops_needed[i-1] + 1;
    }
}

long long get_partial_product(long long k) {
    if (k == 0) return 1;
    long long res = 1;
    for (int p = 0; p < MAX_PRECOMP; p++) {
        if ((k>>p)&1) {
            long long term = (P_mod[p] * (p+1)) % MOD;
            res = (res * term) % MOD;
        }
    }
    return res;
}

void solve() {
    int n; long long k; cin >> n >> k;
    vector<long long> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    sort(s.begin(), s.end());

    long long score = 1;
    for (auto val : s) {
        if (k == 0) break;

        score = (score * val) % MOD;
        k--;
        if (k == 0) break;

        long long m = val - 1;
        if (m == 0) continue;

        long long ops = (m < MAX_PRECOMP) ? ops_needed[m] : -1;

        if (ops != -1 && k >= ops) {
            score = (score * P_mod[m]) % MOD;
            k -= ops;
        } else {
            long long partial = get_partial_product(k);
            score = (score * partial) % MOD;
            k = 0;
        }
    }
    if (k > 0) {
        score = (score * get_partial_product(k)) % MOD;
    }

    cout << score << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int tt; 
    cin >> tt;
    while(tt--) solve();
    return 0;
}
