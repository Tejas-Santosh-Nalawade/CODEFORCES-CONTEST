#include <bits/stdc++.h>
using namespace std;

bool LorR(const string &s, int i, char b) {
    for (int j = 0; j < i; ++j) {
        if (s[j] == b) return true;
    }

    for (int j = i + 1; j < s.size(); ++j) {
        if (s[j] == b) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        string s;
        cin >> n >> s;

        bool found = false;

        for (int i = 1; i < n - 1; i++) {
            char b = s[i];

            if (LorR(s, i, b)) {
                found = true;
                break;
            }
        }

        cout << (found ? "Yes" : "No") << '\n';
    }

    return 0;
}
