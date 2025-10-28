#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

bool check(int T, int n, int k, int x, const vector<int>& a) {
    if (T == 0) return (x + 1) >= k;

    vector<pair<int, int>> intervals;
    for (auto pos : a) {
        int l = pos - T + 1, r = pos + T - 1;
        if (l <= r) intervals.push_back({l, r});
    }
    if (intervals.empty()) return (x + 1) >= k;

    vector<pair<int, int>> merged;
    int l = intervals[0].first, r = intervals[0].second;
    for (int i = 1; i < (int)intervals.size(); i++) {
        int nl = intervals[i].first;
        int nr = intervals[i].second;
        if (nl <= r + 1) r = max(r, nr);
        else {
            merged.push_back({l, r});
            l = nl, r = nr;
        }
    }
    merged.push_back({l, r});

    int freePos = 0, cnt = 0;
    for (int i = 0; i < (int)merged.size(); i++) {
        int L = merged[i].first, R = merged[i].second;
        int start = max(freePos, 0LL), end = min(L - 1, x);
        if (start <= end) cnt += (end - start + 1);
        if (cnt >= k) return true;
        freePos = max(freePos, R + 1);
    }
    if (freePos <= x) cnt += (x - freePos + 1);
    return cnt >= k;
}

void printAns(int T, int n, int k, int x, const vector<int>& a) {
    vector<pair<int, int>> intervals;
    for (auto pos : a) {
        int l = pos - T + 1, r = pos + T - 1;
        if (l <= r) intervals.push_back({l, r});
    }

    vector<pair<int, int>> merged;
    if (!intervals.empty()) {
        int l = intervals[0].first, r = intervals[0].second;
        for (int i = 1; i < (int)intervals.size(); i++) {
            int nl = intervals[i].first;
            int nr = intervals[i].second;
            if (nl <= r + 1) r = max(r, nr);
            else {
                merged.push_back({l, r});
                l = nl, r = nr;
            }
        }
        merged.push_back({l, r});
    }

    int placed = 0, pos = 0;
    for (int i = 0; i < (int)merged.size(); i++) {
        int L = merged[i].first, R = merged[i].second;
        int start = max(pos, 0LL), end = min(L - 1, x);
        for (int p = start; p <= end && placed < k; p++) {
            cout << p << " ";
            placed++;
        }
        pos = max(pos, R + 1);
        if (placed == k) break;
    }

    for (int p = pos; p <= x && placed < k; p++) {
        cout << p << " ";
        placed++;
    }
    cout << endl;
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int lo = 0, hi = x + 1, best = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid, n, k, x, a)) best = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    printAns(best, n, k, x, a);
}

int32_t main() {
    fastio();
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
