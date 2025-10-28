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
       ll a,b,c,d;
       cin>>a>>b>>c>>d;
       if(a==b && b==c && c==d && d==a){
       	cout<<"YES"<<"\n";
       } 
       else{
       	cout<<"NO"<<"\n";
       }
    }

    return 0;
}