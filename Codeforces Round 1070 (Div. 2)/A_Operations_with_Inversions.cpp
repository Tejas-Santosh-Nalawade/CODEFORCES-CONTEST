#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int max_operation = 0;
    int operation = 0;

    for(int i=0; i<n; i++){
        if(arr[i] < max_operation){
            operation ++;
        }
        else{
            max_operation = arr[i];
        }
    }
    cout<< operation << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}