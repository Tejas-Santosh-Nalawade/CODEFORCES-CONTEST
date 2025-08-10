#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin>>n;
        vector<long long > a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int dec = 0, inc = 0;
        for(int i=0; i<n; i++){
            if(a[i]>b[i]) dec+=a[i]-b[i];
            else if(a[i]<b[i]) inc+=b[i]-a[i];
        }

        int ans = 0;
        if(dec == 0) ans = 1;
        else if (inc > dec ) ans = dec + 1;
        else ans = dec + 1;
        cout << ans << "\n";
    }
    return 0;
}