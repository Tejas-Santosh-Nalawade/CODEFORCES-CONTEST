#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int expected_val = -1; 
    bool possible = true;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        if (val == 0) {
            possible = false;
        }
        if (val > 0) {
            if (expected_val == -1) {
                expected_val = val;
            } else if (val != expected_val) {
                possible = false;
            }
        }
    }

    if (possible) {
        cout<<"YES"<<"\n";
    } else {
        cout<<"NO"<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}