#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> freq(n);
    for(int i = 0; i < n; i++){
        cin >> freq[i];
    }

    vector<int> a(n);

    for(int i = 1; i < n - 1; i++){
        a[i] = (freq[i+1] - 2 * freq[i] + freq[i-1]) / 2;
    }

    int weight_mid_value = 0;
    for(int i = 1; i < n - 1; i++){
        weight_mid_value += i * a[i];
    }
    
    if (n > 1) {
        a[n-1] = (freq[0] - weight_mid_value) / (n - 1);
    }

    int mid_sum_value = 0;
    for(int i = 1; i < n - 1; i++){
        mid_sum_value += a[i];
    }
    
    a[0] = a[n-1] + freq[1] - freq[0] + mid_sum_value;`

    for(int i = 0; i < n; i++){
        cout << a[i] << (i == n-1 ? "" : " ");
    }
    cout << "\n";
}

int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int tt; cin >> tt;
        while (tt--) solve();
}