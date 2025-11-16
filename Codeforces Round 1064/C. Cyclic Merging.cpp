// #include <bits/stdc++.h>
// using namespace std;

// #define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
// using ll = long long;
// #define endl '\n'

// struct Node {
//     ll val;
//     ll prev;
//     ll next;
//     bool active;
// };

// void solve(){
//     ll n;
//     cin >> n;

//     if (n == 2) {
//         ll a, b;
//         cin >> a >> b;
//         cout << max(a, b) << endl;
//         return;
//     }

//     vector<Node> nodes(n);
//     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

//     for (ll i = 0; i < n; i++) {
//         cin >> nodes[i].val;
//         nodes[i].prev = (i - 1 + n) % n;
//         nodes[i].next = (i + 1) % n;
//         nodes[i].active = true;
//         pq.push({nodes[i].val, i});
//     }

//     ll cost = 0;
//     int count = n;

//     while (count > 1) {
//         ll val = pq.top().first;
//         int idx = pq.top().second;
//         pq.pop();

//         if (!nodes[idx].active || nodes[idx].val != val) {
//             continue;
//         }

//         ll prev = nodes[idx].prev;
//         ll next = nodes[idx].next;

//         ll target;
//         if (nodes[prev].val <= nodes[next].val) {
//             target = prev;
//         } else {
//             target = next;
//         }

//         ll merge_cost = max(nodes[idx].val, nodes[target].val);
//         cost += merge_cost;

//         nodes[target].val = merge_cost;
        
//         nodes[idx].active = false;
//         count--;

//         nodes[prev].next = next;
//         nodes[next].prev = prev;

//         pq.push({nodes[target].val, target});
//     }

//     cout << cost << endl;
// }

// int main() {
//     fastio();

//     int tt;
//     cin >> tt;
//     while (tt--) {
//         solve();  
//     }
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

struct Node {
    ll val;
    int idx;
    bool operator<(const Node& other) const {
        return val < other.val;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<ll> initial_val(n);
    vector<Node> sorted_nodes(n);
    for(int i = 0; i < n; ++i) {
        cin >> initial_val[i];
        sorted_nodes[i] = {initial_val[i], i};
    }
    if (n == 2) {
        cout << max(initial_val[0], initial_val[1]) << endl;
        return;
    }

    sort(sorted_nodes.begin(), sorted_nodes.end());

    vector<int> prev(n), next(n);
    vector<bool> active(n, true);

    for (int i = 0; i < n; ++i) {
        prev[i] = (i - 1 + n) % n;
        next[i] = (i + 1) % n;
    }

    ll total_cost = 0;
    int merges_done = 0;

    for (int i = 0; i < n; ++i) {
        int idx = sorted_nodes[i].idx;
        ll val = sorted_nodes[i].val;

        if (!active[idx]) {
            continue;
        }

        if (merges_done == n - 1) {
            break;
        }

        int prev_idx = prev[idx];
        int next_idx = next[idx];

        ll neighbor_val;
        if (initial_val[prev_idx] <= initial_val[next_idx]) {
            neighbor_val = initial_val[prev_idx];
        } else {
            neighbor_val = initial_val[next_idx];
        }


        total_cost += max(val, neighbor_val);

        active[idx] = false;
        merges_done++;
        
        next[prev_idx] = next_idx;
        prev[next_idx] = prev_idx;
        if (initial_val[prev_idx] <= initial_val[next_idx]) {
             initial_val[prev_idx] = max(val, neighbor_val);
        } else {
             initial_val[next_idx] = max(val, neighbor_val);
        }
    }

    cout << total_cost << endl;
}

int main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        solve();  
    }
    return 0;
}