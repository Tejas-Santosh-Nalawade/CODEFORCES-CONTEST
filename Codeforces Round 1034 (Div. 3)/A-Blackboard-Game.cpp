#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin>>n;
        int count[4] = {0};
        for (int i = 0; i < n; ++i) {
            count[i % 4]++;
        }
        int pairs = min(count[0], count[3]) + min(count[1], count[2]);

        if (pairs * 2 == n) {
            cout<<"Bob"<<"\n";
        } 
        else {
            cout<<"Alice"<<"\n";
        }
    }
    return 0;
}
