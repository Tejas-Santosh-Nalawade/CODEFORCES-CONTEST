// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     vector<int> freq(n + 1, 0);
//     for (int x : a) freq[x]++;

//     int ans = 0;
//     for (int x = 1; x <= n; x++) {
//         int f = freq[x];
//         if (f == 0) continue;

//         if (f < x) {
//             ans += f;   
//         } else {
//             ans += (f - x);
//         }
//     }
//     ans += freq[0];

//     cout << ans << "\n";
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int tt;
//     cin >> tt;
//     while (tt--) solve();
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; 
    cin >> tt;
    while (tt--) {
        int n; 
        cin >> n;
        unordered_map<int,int> mp;
        int x;
        for (int i = 0; i < n; i++) cin >> x, mp[x]++;

        int ans = 0;
        for (auto &p : mp) {
            int x = p.first, f = p.second;
            ans += (x == 0 ? f : (f < x ? f : f - x));
        }
        cout << ans << "\n";
    }
}

