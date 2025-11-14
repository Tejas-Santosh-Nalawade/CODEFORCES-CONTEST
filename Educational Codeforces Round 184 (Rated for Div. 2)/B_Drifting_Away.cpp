#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

const ll INF = (1LL << 60);

ll dfs(int i, const string &s, vector<ll> &memo) {
    int n = s.size();
    if (i < 0 || i >= n) return 0;
    if (memo[i] == -2) return INF;
    if (memo[i] != -1) return memo[i];
    memo[i] = -2; 
    ll res = 0;

    if (s[i] == '<') {  
        ll nxt = dfs(i - 1, s, memo);
        res = (nxt == INF ? INF : nxt + 1);
    }
    else if (s[i] == '>') {
        ll nxt = dfs(i + 1, s, memo);
        res = (nxt == INF ? INF : nxt + 1);
    }
    else { 
        ll L = dfs(i - 1, s, memo);
        ll R = dfs(i + 1, s, memo);
        if (L == INF || R == INF) res = INF;
        else res = 1 + max(L, R);
    }
    memo[i] = res; 
    return res;
}

int main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {

        string s;
        cin >> s;
        int n = s.size();

        vector<ll> memo(n, -1);
        ll ans = 0;
        bool infinite = false;

        for (int i = 0; i < n; i++) {
            ll t = dfs(i, s, memo);
            if (t == INF) {
                infinite = true;
                break;
            }
            ans = max(ans, t);
        }

        cout << (infinite ? -1 : ans) << endl;
    }

    return 0;
}
