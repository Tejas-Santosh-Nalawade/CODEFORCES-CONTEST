#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

void solve(){
    ll a, b, n;
    cin >> a >> b >> n;
    if(b >= a ){
        cout<<1<<endl;
        return;
    }
    if(n * b <= a){
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;
}

int main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
       solve();
    }
    return 0;
}
