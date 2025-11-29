#include <bits/stdc++.h>
using namespace std;
#define int long long

static int maxSub(const vector<int> &arr) {
    int cur = LLONG_MIN, best = LLONG_MIN;
    for (int x : arr) {
        if (cur < 0) cur = x;
        else cur += x;
        best = max(best, cur);
    }
    return best;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;

    int baseAns = maxSub(A);

    if ((k & 1) == 0) {
        cout << baseAns << "\n";
        return;
    }

    vector<int> pref(n);
    pref[0] = A[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = max(A[i], pref[i - 1] + A[i]);
    }

    vector<int> suff(n);
    suff[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = max(A[i], A[i] + suff[i + 1]);
    }

    int finalAns = baseAns;
    for (int i = 0; i < n; ++i) {
        int leftSide = pref[i];
        int rightSide = suff[i];
        int merged = leftSide + rightSide - A[i] + B[i];
        finalAns = max(finalAns, merged);
    }

    cout << finalAns << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
