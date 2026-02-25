#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin >> s;
    
    int n = s.length();
    
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    
    int data = s[0] - '0';
    vector<int> Result;
    int total = 0;
    
    for (int i = 1; i < n; i++) {
        int value = s[i] - '0';
        Result.push_back(value);
        total += value;
    }
    
    sort(Result.rbegin(), Result.rend());
    
    int ans = n;
    int curr= data + total;
    int cost = 0;
    
    if (curr <= 9) {
        ans = min(ans, cost);
    } else {
        for (int i = 0; i < Result.size(); i++) {
            curr -= Result[i]; 
            cost++;
            if (curr <= 9) {
                ans = min(ans, cost);
                break;
            }
        }
    }
    
    curr = 1 + total;
    int cost1 = 1; 
    
    if (curr <= 9) {
        ans = min(ans, cost1);
    } else {
        for (int i = 0; i < Result.size(); i++) {
            curr -= Result[i]; 
            cost1++;
            if (curr <= 9) {
                ans = min(ans, cost1);
                break;
            }
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
    
    return 0;
}