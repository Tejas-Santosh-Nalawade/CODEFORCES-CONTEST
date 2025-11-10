#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

int main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin>>n;
        
        vector<int>a(n);
        
        for(auto &x: a ){
            cin>>x;
        }  
        
        sort(a.begin(),a.end());
        
        bool win = true;

        for(int i=1; i + 1<n ; i+=2){
            if(a[i] != a[i + 1]){
                win = false;
                break;
            }
        }
        if(win){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
    }
    return 0;
}