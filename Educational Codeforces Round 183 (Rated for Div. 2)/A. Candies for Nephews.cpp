#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin>>n;
        // if(n%3==1){
        //     cout<<2<<"\n";
        // }
        // else if(n%3==2){
        //     cout<<1<<"\n";
        // }
        // else{
        //     cout<<0<<"\n";
        // }
        // Single formula Optimized
        cout<<(3-(n%3))%3<<"\n";
    }   
    return 0;
}