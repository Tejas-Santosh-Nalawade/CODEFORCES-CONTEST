#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; cin >> n;
    string ss; cin   >> ss;

    int value = 0;

    for(char c : ss){
        if(c == '0') {
            value = 1;
            break;
        }
    }

    if(!value){
        cout << 0 << "\n";
        return;
    }

    string s = ss;
    s.append(ss);


    int ans = 0 , current = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            current++;
        }
        else{
            if(current > ans) {
                ans = current;
            }
            current = 0;
        }
    }
    if(current > ans) {
        ans = current;
    }

    cout<< ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}