#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin >> n;
    vector<int> permutations(n + 1);
    permutations[n] = 1;

    for(int i = 2; i < n; i++) {
        permutations[i] = i ^ 1;
        }

    if (n % 2 == 0) {
        permutations[1] = n;
    } else {
        permutations[1] = n - 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << permutations[i] << " ";
    }
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}