#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adjacent(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    vector<int> color(n+1,-1);

    int ans = 0;

    for(int i=1; i<=n; i++){
        if(color[i]!= -1) continue;

        int count[2] = {0,0};
        bool is_bipartite = true;
        queue<int> q;
        q.push(i);
        color[i] = 0;
        count[0]++;

        while (!q.empty()){
            int u = q.front();
            q.pop();

            for (int v : adjacent[u]){
                if (color[v] == -1){
                    color[v] = 1 - color[u];
                    count[color[v]]++;
                    q.push(v);
                }
                else if (color[v] == color[u]){
                    is_bipartite = false;
                }
            }
        }

        if (is_bipartite){
            ans += max(count[0], count[1]);
        }
    }
    cout<<ans<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}