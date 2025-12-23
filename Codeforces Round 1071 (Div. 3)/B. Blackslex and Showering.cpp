#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int total_sum = 0;
    for(int i = 0; i < n - 1; i++) {
        total_sum += abs(a[i] - a[i+1]);
    }

    int minmum_value = total_sum;

    for(int i = 0; i < n; i++){
        int cuum_value = total_sum;

        if(i == 0){
            cuum_value -= abs(a[0] - a[1]);
        }
        else if (i == n-1){
            cuum_value -= abs(a[n-2] - a[n-1]);
        }
        else{
            int reduce = abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]);
            int add = abs(a[i-1] - a[i+1]);
            cuum_value = total_sum - reduce + add;
        }
        minmum_value = min(minmum_value, cuum_value);
    }
    cout << minmum_value << "\n";
}   

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
