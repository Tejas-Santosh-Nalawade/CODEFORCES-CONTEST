#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int r,g,b;
    cin >> r >> g >> b;

    vector<pair<int, char>> a = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
    sort(a.begin(), a.end());

    int val1 = a[0].first , val2 = a[1].first , val3 = a[2].first;
    char x = a[0].second, y = a[1].second, z = a[2].second;

    if(val3 >= val1 + val2){
        for(int i = 0; i < val2; i++) cout << z<<y;
        for(int i = 0; i < val1; i++) cout << z<<x;
        if(val3 > val1 + val2) cout << z;
    }
    else{
        int ans = val1 + val2 + val3;
        if(ans % 2 != 0){
            cout<<y;
            val2--;
            ans--;
        } 
        for(int i=0; i<ans/2 - val3; i++)cout<<x<<y;
        for(int i=0; i<ans/2 - val1; i++)cout<<z<<y;
        for(int i=0; i<ans/2 - val2; i++)cout<<z<<x;
    }
    cout<<"\n"; 
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}