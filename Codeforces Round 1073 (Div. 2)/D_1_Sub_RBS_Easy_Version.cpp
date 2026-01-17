#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; 
    cin >> n;
    string s; 
    cin >> s;

    int open = 0;
    bool correct = false;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '('){
            open++;
        }
        else {
            if(open >= 2){
                correct = true;
                break;
            }
        }
    }

    if(correct){
        cout << n - 2 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}