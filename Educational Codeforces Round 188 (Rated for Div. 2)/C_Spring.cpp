#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int ab = lcm(a, b);
    int ac = lcm(a, c);
    int bc = lcm(b, c);
    int abc = lcm(ab, c);

   cout << 6*(m/a) - 3*(m/ab) - 3*(m/ac) + 2*(m/abc) << " "
         << 6*(m/b) - 3*(m/ab) - 3*(m/bc) + 2*(m/abc) << " "
         << 6*(m/c) - 3*(m/ac) - 3*(m/bc) + 2*(m/abc) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}