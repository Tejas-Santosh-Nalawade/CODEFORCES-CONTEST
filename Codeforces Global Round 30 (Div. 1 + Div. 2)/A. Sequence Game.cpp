#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

int32_t main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin>>n;
        vector<int>a(n);

        for(auto &x: a) cin>>x;

        int x;
        cin>>x;

        if( x <= *max_element(a.begin(),a.end()) && x>=*min_element(a.begin(),a.end())){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}