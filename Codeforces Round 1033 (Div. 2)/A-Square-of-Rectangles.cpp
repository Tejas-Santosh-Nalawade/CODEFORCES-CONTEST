#include <bits/stdc++.h>
using namespace std;

bool solve() {
    long long l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    long long area = l1 * b1 + l2 * b2 + l3 * b3;

    long long s = 0;
    for (long long i = 1; i * i <= area; i++) {
        if (i * i == area) {
            s = i;
            break;
        }
    }

    if (s == 0) { 
        return false;
    }

    if (s != l1 && s != b1) {
        return false;
    }

    if (l1 == s) {
        if (l2 == s && l3 == s && (b1 + b2 + b3 == s)) {
            return true;
        }
        if (b1 < s && b2 == (s - b1) && b3 == (s - b1) && (l2 + l3 == s)) {
            return true;
        }
    }

    if (b1 == s) {
        if (b2 == s && b3 == s && (l1 + l2 + l3 == s)) {
            return true;
        }
        if (l1 < s && l2 == (s - l1) && l3 == (s - l1) && (b2 + b3 == s)) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        if (solve()) {
            cout << "YES"<<"\n";
        } else {
            cout << "NO"<<"\n";
        }
    }
    return 0;
}