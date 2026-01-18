#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(), a.end());

    int maximum_length = 1;
    int current_length = 1;

    for(int i=1; i<n; i++){
        if(a[i] == a[i-1] + 1){
            current_length++;
        } 
        else if(a[i] == a[i-1]){
            continue;

        }else {
            maximum_length = max(maximum_length, current_length);
            current_length = 1;
        }
    }
    maximum_length = max(maximum_length, current_length);

    cout<<maximum_length<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
