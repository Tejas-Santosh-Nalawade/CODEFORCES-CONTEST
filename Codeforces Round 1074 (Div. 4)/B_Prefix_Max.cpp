#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int maximum_value = 0;


    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            
            swap(a[i], a[j]);


            int current_value = 0;
            int current_maximum = 0;
            for(int k = 0; k < n; k++){
                current_maximum = max(current_maximum, a[k]);
                current_value += current_maximum;
            }
            maximum_value = max(maximum_value, current_value);
            swap(a[i], a[j]);
        }
    }

    cout << maximum_value << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}