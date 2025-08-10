#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

pair<int,int> bfs(int src,int n){
    vector<int> dist(n+1,-1);
    queue<int> q; q.push(src);
    dist[src]=0;
    int far=src, maxd=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto v: adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
                if(dist[v]>maxd){
                    maxd=dist[v];
                    far=v;
                }
            }
        }
    }
    return {far,maxd};
}

int findDiameter(int n){
    if(n==1) return 0;
    pair<int,int> p1 = bfs(1,n);
    pair<int,int> p2 = bfs(p1.first,n);
    return p2.second;
}

int solve(int n){
    if(n<=2) return 0;
    int diameter = findDiameter(n);

    int minDiameter=0, nodes=1;
    while(nodes<n){
        minDiameter++;
        nodes<<=1;
    }

    if(diameter <= minDiameter) return 0;
    int excess = diameter - minDiameter;

    if(n>=8 && excess>=2) return 2*excess;
    return excess;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        adj.assign(n+1, {});
        for(int i=0; i<n-1; i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << solve(n) << "\n";
    }
    return 0;
}
