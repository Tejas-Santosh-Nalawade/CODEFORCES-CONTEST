#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

int32_t main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool found = false;
        int x = -1, y = -1;
    
        for (int i = 0; i < n && !found; i++) {
            if (a[i] % 2 == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (a[j] % 2 == 0) {
                        x = a[i];
                        y = a[j];
                        found = true;
                        break;
                    }
                }
            }
        }
    
        if (!found) {
            for (int i = 0; i < n && !found; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (a[j] % a[i] % 2 == 0) {
                        x = a[i];
                        y = a[j];
                        found = true;
                        break;
                    }
                }
            }
        }
        
        if (found) {
            cout << x << " " << y << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}