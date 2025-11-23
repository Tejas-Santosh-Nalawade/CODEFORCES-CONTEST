#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    long long n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    
    int c4 = 0;
    int c8 = 0;

    for(char c : s){
        if(c == '4') c4++;
        else c8++;
    }
    int axis = c4 + c8;
    int diag = c4 + 2 * c8;
    bool possible = true;
    if (abs(x) > axis || abs(y) > axis) {
        possible = false;
    }

    if (abs(x + y) > diag || abs(x - y) > diag) {
        possible = false;
    }

    if(possible) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}