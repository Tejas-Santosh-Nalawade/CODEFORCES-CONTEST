#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; 
    cin >> n;

    vector<int> v(n);
    int reference  = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        reference = min(reference, v[i]);
    }

    int limt = LLONG_MAX;
    bool flagged = true;

    for (int i = 0; i < n; ++i) {
        int cur = v[i];
        if (cur == reference) continue;

        int differnce = cur - reference;
        if (differnce <= reference) {
            flagged = false;
            break;
        }
        limt = min(limt, differnce);
    }

    cout << (flagged ? limt : reference) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; 
    cin >> tt;
    while (tt--) solve();
}
