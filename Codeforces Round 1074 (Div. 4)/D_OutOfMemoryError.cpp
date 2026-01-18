#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m,h;
    cin>>n>>m>>h;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<pair<int, int>> old;

    for(int i=0; i<m; i++){
        int b,c;
        cin >> b >> c;
        b--;
        if(a[b] + c >  h){
            while (!old.empty())
            {
                pair<int, int> p = old.back();
                old.pop_back();
                a[p.first] -= p.second;
            }
            
        }
        else{
            a[b] += c;
            old.push_back({b, c});
        }
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << (i == n-1 ? "" : " ");
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
