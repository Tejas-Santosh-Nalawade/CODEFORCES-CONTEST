#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    int diff = 0;
    int index = -1;

    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            diff++;
            index = i + 1; 
        }
    }

    if(diff % 2 == 0){
        cout << "Tie" << endl;
    } else {
        if(index % 2 != 0){
            cout << "Ajisai" << endl;
        } else {
            cout << "Mai" << endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}