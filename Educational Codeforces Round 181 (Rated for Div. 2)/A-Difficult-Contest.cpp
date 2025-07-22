#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin >> s;

    string t_chars, f_chars, n_chars, other_chars;

    for (char c : s) {
        if (c == 'T') {
            t_chars += c;
        } else if (c == 'F') {
            f_chars += c;
        } else if (c == 'N') {
            n_chars += c;
        } else {
            other_chars += c;
        }
    }

    sort(other_chars.begin(), other_chars.end());

    cout << t_chars << f_chars << n_chars << other_chars << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}