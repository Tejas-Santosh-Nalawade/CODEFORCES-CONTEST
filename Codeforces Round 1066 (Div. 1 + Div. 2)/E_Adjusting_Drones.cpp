#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;
    map<int, int> count;
    for(int i=0; i<n; ++i){
        int a; cin >> a;
        count[a]++;
    }
    
    int max_op = 0;
    int start = -1;      
    int front = -1;      
    int excess = 0;      
    
    for(auto [val, cnt] : count){
        if(front == -1){
            start = val;
            front = val;
            excess = cnt;
        } else {
            int dist = val - front;
            int can_move = max(0LL, excess - k);
            
            int move = min(dist, can_move);
            
            front += move;
            excess -= move;
            
            if(front < val){
                max_op = max(max_op, front - start);
                start = val;
                front = val;
                excess = cnt;
            } else {
                excess += cnt;
            }
        }
    }

    int can_move = max(0LL, excess - k);
    front += can_move;
    max_op = max(max_op, front - start);
    
    cout << max_op << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}