#include<bits/stdc++.h>
using namespace std;
#define int long long


int max_value(int n) {
    int max_details = 1;
    while (max_details * 2 <= n) max_details *= 2;
    return max_details;
}

bool powertwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

void solve(){
    int n;
    cin >> n;
    if (powertwo(n)) {
        cout << "-1" << "\n";
        return;
    }

    vector<int> permutations(n + 1);
    fill(permutations.begin(), permutations.end(), 0);

    int current = n;
    
    while (current > 0) {
        int m = max_value(current);
        int start = 2 * m - 1 - current;
        
        for (int i = start; i < m; i++) {
            int j = 2 * m - 1 - i;
            if (j <= current) {
                permutations[i] = j;
                permutations[j] = i;
            }
        }
        current = start - 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << permutations[i] << (i == n ? "" : " ");
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