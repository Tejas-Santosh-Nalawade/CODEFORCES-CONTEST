// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// template<typename T>
// T getErasures(T d, int n, const vector<T>& cnt, const vector<T>& pref) {
//     T erase = pref[d - 1]; 
//     for (int x = d; x <= n; x++) {
//         if (cnt[x] == 0) continue;
//         if (x % d == 0) continue;

//         T qmin = (x - d + 2 * d - 1) / (2 * d);
//         T qmax = (x - 2 * d) / d;

//         if (qmin > qmax || qmax < 1) erase += cnt[x];
//     }
//     return erase;
// }

// void solve() {
//     int n;
//     ll k;
//     cin >> n >> k;

//     vector<ll> cnt(n + 1, 0);
//     for (int i = 0; i < n; i++) {
//         ll a; cin >> a;
//         cnt[a]++;
//     }

//     vector<ll> pref(n + 1, 0);
//     for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + cnt[i];

//     for (ll d = n; d >= 1; d--) {
//         if (getErasures(d, n, cnt, pref) <= k) {
//             cout << d << "\n";
//             return;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tt; cin >> tt;
//     while (tt--) solve();
// }


// O(N2) solution will get TLE

// o(N)  Greedy + Prefix Sum + Counting 

// Optimized approach 
#include <bits/stdc++.h>
using namespace std;

template<typename T>
T maxGCD(int n, T k, const vector<int>& cnt) {
    vector<T> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + cnt[i];

    for (int d = n; d >= 1; d--) {
        T erase = pref[d - 1];
        long long up = min((long long)n, 4LL * d - 1);
        if (up >= d) {
            T total = pref[up] - pref[d - 1], mult = 0;
            for (int i = 1; i <= 3; i++) if (i * d <= n) mult += cnt[i * d];
            erase += total - mult;
        }
        if (erase <= k) return d;
    }
    return 1;
}

void solve() {
    int n; long long k;
    cin >> n >> k;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) { int a; cin >> a; cnt[a]++; }
    cout << maxGCD(n, k, cnt) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) solve();
}
