#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    int l, r;
    cin >> n >> l >> r;
    
    vector<int> a(n);
    vector<int> incr;
    incr.reserve(2 * n);
    
    int curr = 0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        curr += (a[i] - l);
        int val = l - a[i];
        incr.push_back(val);
        incr.push_back(val);
    }
    sort(incr.begin(), incr.end(), greater<int>());
    
    int k = -n; 
    int width = r - l;
    int max_guaranteed = -4e18;

    int curr_f = curr + k * width;
    max_guaranteed = max(max_guaranteed, min(curr, curr_f));
    
    for(int val : incr){
        curr += val;
        k++;
        curr_f = curr + k * width;
        max_guaranteed = max(max_guaranteed, min(curr, curr_f));
    }
    
    cout << max_guaranteed << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}