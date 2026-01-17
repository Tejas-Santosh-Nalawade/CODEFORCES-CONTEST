#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; cin >> n;
    string s; cin >> s;
    bool poosible = true;
    for(int i = 0; i <= n - 2; i++){
        if(s[i] >  s[i+1]){
            poosible = false;
            break;
        }
    }
    if(poosible) {
        cout << "Bob\n";
        return;
    } 

    cout << "Alice\n";

    int count = 0;
    for(char c: s){
        if(c == '0') count++;
    }

    vector<int> changes;

    for(int i=0; i<n; i++){
        if(i < count){
            if(s[i] == '1') changes.push_back(i + 1);
        } else {
            if(s[i] == '0') changes.push_back(i + 1);
        }
    }
    cout << changes.size()<< "\n";

    for(int c: changes){
        cout << " " << c;
    }
    cout<< "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
