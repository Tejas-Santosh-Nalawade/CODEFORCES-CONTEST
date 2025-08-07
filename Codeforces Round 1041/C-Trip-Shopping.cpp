#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    priority_queue<long long, vector<long long>, greater<long long>> a;
    priority_queue<long long> b;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        a.push(x);
    }

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        b.push(x);
    }

    while (k--) {
        long long smallest = a.top();
        long long largest = b.top();

        if (smallest < largest) {
            a.pop(); b.pop();
            a.push(largest);
            b.push(smallest);
        } else {
            break;
        }
    }

    long long sum = 0;
    while (!a.empty()) {
        sum += a.top();
        a.pop();
    }

    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
