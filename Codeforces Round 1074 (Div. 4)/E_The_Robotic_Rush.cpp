#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b(m);
    for(int i = 0; i < m; ++i) cin >> b[i];

    string g;

    cin >> g;

    sort(b.begin(), b.end());

    vector<vector<int>> die_left(k + 2);
    vector<vector<int>> die_right(k + 2);

    for(int i = 0; i < n; ++i){
        int position  = a[i];
        auto it = lower_bound(b.begin(), b.end(), position);
        
        if(it != b.end()){
            int dist = *it - position;
            if(dist <= k) die_right[dist].push_back(i);
        }

        if(it != b.begin()){
            int dist = position - *prev(it);
            if(dist <= k) die_left[dist].push_back(i);
        }
    }

    vector<bool> dead_end(n, false);
    int lived = n;
    int currrent = 0;
    int min_right = 0;
    int max_right = 0;

    for(char c : g){
        if(c == 'L') currrent--;
        else currrent++;

        if(currrent < min_right){
            min_right = currrent;
            int d = -min_right;
            if(d <= k){
                for(int i : die_left[d]){
                    if(!dead_end[i]){
                        dead_end[i] = true;
                        lived--;
                    }
                }
            }
        }

        if(currrent > max_right){
            max_right = currrent;
            int d = max_right;
            if(d <= k){
                for(int i : die_right[d]){
                    if(!dead_end[i]){
                        dead_end[i] = true;
                        lived--;
                    }
                }
            }
        }
        cout << lived << " ";
    }
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}