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
        long long total_sum = 0;
        vector<long long> odds;

        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            total_sum += a;
            if (a % 2 != 0) odds.push_back(a);
        }

        if (odds.empty()) {
            cout << 0 << "\n";
            continue;
        }

        sort(odds.begin(), odds.end());

        long long loss = 0;
        int num_to_sacrifice = odds.size() / 2;

        for (int i = 0; i < num_to_sacrifice; i++) {
            loss += odds[i];
        }

        cout << total_sum - loss << "\n";
    }

    return 0;
}
