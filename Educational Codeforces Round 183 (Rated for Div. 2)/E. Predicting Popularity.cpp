#include <bits/stdc++.h>
using namespace std;

struct Node { int min_val, lazy; };
vector<Node> tree;
int n;
long long ac, dr;
vector<long long> a, d;

void build(vector<int>& g, int node, int l, int r) {
    if (l == r) { tree[node] = {g[l], 0}; return; }
    int m = (l + r) / 2;
    build(g, 2*node, l, m);
    build(g, 2*node+1, m+1, r);
    tree[node].min_val = min(tree[2*node].min_val, tree[2*node+1].min_val);
    tree[node].lazy = 0;
}

void push(int node) {
    if (tree[node].lazy) {
        tree[2*node].min_val += tree[node].lazy;
        tree[2*node].lazy += tree[node].lazy;
        tree[2*node+1].min_val += tree[node].lazy;
        tree[2*node+1].lazy += tree[node].lazy;
        tree[node].lazy = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, int val) {
    if (l > r || l > qr || r < ql) return;
    if (ql <= l && r <= qr) { tree[node].min_val += val; tree[node].lazy += val; return; }
    push(node);
    int m = (l + r) / 2;
    update(2*node, l, m, ql, qr, val);
    update(2*node+1, m+1, r, ql, qr, val);
    tree[node].min_val = min(tree[2*node].min_val, tree[2*node+1].min_val);
}

int query(int node, int l, int r, int idx) {
    if (l == r) return tree[node].min_val;
    push(node);
    int m = (l + r) / 2;
    return idx <= m ? query(2*node, l, m, idx) : query(2*node+1, m+1, r, idx);
}

long long cost(long long x, long long y) { return max(0LL,x-ac)+max(0LL,y-dr); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> ac >> dr >> n;
    a.resize(n); d.resize(n);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>d[i];

    vector<int> freq(n+1,0);
    for (int i=0;i<n;i++) {
        long long c = cost(a[i],d[i]);
        if (c<=n) freq[c]++;
    }

    vector<int> g(n+1,0);
    int cnt=0;
    for (int i=0;i<=n;i++) { cnt+=freq[i]; g[i]=i-cnt; }

    tree.resize(4*(n+1)+4);
    build(g,1,0,n);

    int m; cin>>m;
    while(m--) {
        int k; long long na, nd;
        cin>>k>>na>>nd; k--;
        long long oldc = cost(a[k],d[k]);
        if (oldc<=n) update(1,0,n,oldc,n,1);
        a[k]=na; d[k]=nd;
        long long newc = cost(a[k],d[k]);
        if (newc<=n) update(1,0,n,newc,n,-1);

        int f0 = -query(1,0,n,0);
        int ans = n, low=f0, high=n;
        while(low <= high) {
            int mid = (low + high)/2;
            if (query(1,0,n,mid) >= 0) { ans = mid; high = mid-1; }
            else low = mid+1;
        }
        cout << ans << "\n";
    }
}
