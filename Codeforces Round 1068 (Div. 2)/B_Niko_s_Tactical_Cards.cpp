#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    vector<int>b(n);
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    int maxx = 0;
    int minn = 0;

    for(int i=0; i<n; i++){
        int value1 = maxx - a[i];
        int value2 = b[i] - maxx;
        int value3 = minn - a[i];
        int value4 = b[i] - minn;

        maxx = max({value1,value2,value3,value4});
        minn = min({value1, value2, value3, value4});
    }
    cout<<maxx<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}