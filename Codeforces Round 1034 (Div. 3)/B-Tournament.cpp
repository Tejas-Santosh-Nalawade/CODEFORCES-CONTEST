#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i]; 
        }

        int j1 = j - 1;       
        int s = a[j1];       

        if (k == 1) {
            bool is_weakest = true;
            for (int i = 0; i < n; i++) {
                if (i == j1) continue;
                if (a[i] <= s) {
                    is_weakest = false;
                    break;
                }
            }
            if (is_weakest) {
                cout << "NO"<<"\n";
                continue; 
            }
        }

        int count = 0;
        for (int i = 0; i < j1; i++) {
            if (a[i] > s) {
                count++;
            }
        }

        if (count < k) {
            cout << "YES"<<"\n";
        } else {
            cout << "NO"<<"\n";
        }
    }
    return 0;
}
