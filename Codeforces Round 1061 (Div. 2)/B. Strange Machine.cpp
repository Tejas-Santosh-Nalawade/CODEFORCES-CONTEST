#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    bool allA = true;
    for (char c : s) if (c == 'B') allA = false;

    for (int i = 0; i < q; i++) {
        long long a;
        cin >> a;
        if (allA) { cout << a << " "; continue; }

        long long sec = 0;
        int idx = 0;
        while (a > 0) {
            sec++;
            if (s[idx] == 'A') a--;
            else a /= 2;
            idx = (idx + 1) % n;
        }
        cout << sec << " "<<"\n";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) solve();
    return 0;
}
