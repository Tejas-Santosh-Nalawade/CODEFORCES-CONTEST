#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){   
    int n; cin >> n;

    vector<int>a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> dp_l(n, 1);
    vector<pair<int, int>> stack_l;
    

    for(int i=0; i<n; i++){
        while(!stack_l.empty() && stack_l.back().first < a[i]){
            stack_l.pop_back();
        }

        int best_l = 0;

        if(!stack_l.empty()){
            best_l = stack_l.back().second;
        }

        dp_l[i] = best_l + 1;

        int curr = dp_l[i];

        if(!stack_l.empty()){
            curr = max(curr, stack_l.back().second);
        }
        stack_l.push_back({a[i],curr});
    }

    vector<int> dp_r(n, 1);
    vector<pair<int, int>> stack_r;

    for(int i= n-1; i>=0; i--){
        while(!stack_r.empty() && stack_r.back().first < a[i]){
            stack_r.pop_back();
        }

        int best_r = 0;

        if(!stack_r.empty()){
            best_r = stack_r.back().second;
        }

        dp_r[i] = best_r + 1;
        int curr_max = dp_r[i];

        if(!stack_r.empty()){
            curr_max = max(curr_max, stack_r.back().second);
        }
        stack_r.push_back({a[i],curr_max});
    }

    int max_cool = 0;

    for(int i=0; i<n; i++){
        int curr_v = dp_l[i] + dp_r[i] - 1;

        max_cool = max( max_cool , curr_v);
    }
    cout<<n - max_cool<<"\n";








}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
