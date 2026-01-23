#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,h,l;
    cin >> n >> h >> l;

    int combine = 0;     
        int row = 0;  
        int column = 0;  
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        bool i_row = (x <= h);
        bool i_col = (x <= l);
        
        if (i_row && i_col) {
            combine++;
        } else if (i_row) {
            row++;
        } else if (i_col) {
            column++;
        }
    }

    int ans = 0;
    int match_ = min(row, column);
    ans += match_;
    
    row -= match_;
    column -= match_;
    int remaining = row + column ;
    
    int match_mixed = min(remaining, combine);
    ans += match_mixed;
    combine -= match_mixed;
    ans += combine / 2;

    cout << ans << "\n";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}