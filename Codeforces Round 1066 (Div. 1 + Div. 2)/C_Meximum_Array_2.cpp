#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Constraint {
    int id;
    int type;
    int l, r;
};

void solve(){
    int n, k, q;
    cin >> n >> k >> q;

    vector<Constraint> cons;
    vector<bool> t1(n + 1, false);
    vector<bool> t2(n + 1, false);

    for(int i=0; i<q; ++i){
        int c, l, r;
        cin >> c >> l >> r;
        cons.push_back({i, c, l, r});
        
        if(c == 1) {
            for(int j=l; j<=r; ++j) t1[j] = true;
        } else {
            for(int j=l; j<=r; ++j) t2[j] = true;
        }
    }

    vector<int> a(n + 1, 1e9);

    for(int i=1; i<=n; ++i){
        if(t1[i] && !t2[i]){
            a[i] = k;
        }
    }
    for(int val = 0; val < k; ++val) {
        vector<Constraint> needed;
        for(auto &c : cons) {
            if(c.type == 2) {
                bool found = false;
                for(int j=c.l; j<=c.r; ++j) {
                    if(a[j] == val) {
                        found = true; 
                        break;
                    }
                }
                if(!found) needed.push_back(c);
            }
        }
        sort(needed.begin(), needed.end(), [](const Constraint &x, const Constraint &y){
            return x.r < y.r;
        });

        for(auto &c : needed) {
            bool found = false;
            for(int j=c.l; j<=c.r; ++j) {
                if(a[j] == val) {
                    found = true; 
                    break;
                }
            }
            if(found) continue;
            int slot = -1;
            for(int j=c.r; j>=c.l; --j) {
                if(!t1[j] && a[j] == 1e9) {
                    slot = j;
                    break;
                }
            }
            
            if(slot != -1) a[slot] = val;
        }
    }

    for(int i=1; i<=n; ++i) cout << a[i] << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}