#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> q(n);

    for(int i = 0; i < n; i++){cin >> q[i]; q[i]++;}

    vector<int> r(n);
    for(int i = 0; i < n; i++) {cin >> r[i];r[i]++;}

    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    int ans = 0;
    int right = n - 1; 
    int limit = k + 1;
    for(int i = 0; i < n; i++){
        while(right >= 0 && r[right] > limit / q[i]){
            right--;
        }
        if(right >= 0){
            ans++;
            right--; 
        } else {
            break;
        }
    }

    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}