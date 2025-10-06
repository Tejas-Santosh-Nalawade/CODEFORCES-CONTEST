#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; 
    cin>>tt;
    while (tt--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int z = 0, o = 0;
        for (char c : s) {
            if (c == '0') ++z;
            else if (c == '1') ++o;
        }
        int t = k - z - o;

        // special case: all removed
        if (n == k) {
            cout << string(n, '-') << '\n';
            continue;
        }

        int rem_len = n - k;
        int left_def = z;         
        int right_def = o;        

        int intL = z + t + 1;       // left bound 
        int intR = z + rem_len;     // right bound 

        string res(n, '?');
        for (int i = 1; i <= n; ++i) {
            if (i <= left_def) res[i-1] = '-';
            else if (i > n - right_def) res[i-1] = '-';
            else if (intL <= intR && i >= intL && i <= intR) res[i-1] = '+';
            else res[i-1] = '?';
        }
        cout << res << '\n';
    }
    return 0;
}
