// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"


// void solve(){
//     int n; cin >> n;
//     vector<int> p(n);
//     for(int i=0; i<n; i++) cin >> p[i];

//     vector<int> suffix;
//     int curr = -1;
//     for(int i = n-1; i >= 0; i--){
//         if(p[i] > curr){
//             curr = p[i];
//             suffix.push_back(i);
//         }
//     }

//     reverse(suffix.begin(), suffix.end());

//     vector<int> prefix(n);
//     prefix[0] = p[0];
//     for(int i = 1; i < n; i++){
//         prefix[i] = min(prefix[i-1], p[i]);
//     }
//     for(size_t k = 1; k < suffix.size(); k++){
//         int curr_idx = suffix[k];
//         int prev_idx = suffix[k-1]; 
        
//         int val = p[curr_idx];
    
//         int min_val_left = prefix[prev_idx]; 
//         if(min_val_left > val){
//             cout << "No" << endl;
//             return;
//         }
//     }

//     cout << "Yes" << endl;
// }

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int tt; cin >> tt;
//     while (tt--) solve();
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];
    vector<int> suffix;
    int current = -1;
    for(int i = n-1; i >= 0; i--){
        if(p[i] > current){
            current = p[i];
            suffix.push_back(i);
        }
    }
    reverse(suffix.begin(), suffix.end());
    vector<int> prefix(n);
    prefix[0] = p[0];
    for(int i=1; i<n; i++){
        prefix[i] = min(prefix[i-1], p[i]);
    }
    for(size_t k = 1; k < suffix.size(); k++){
        int current_idx = suffix[k]; 
        int prev_idx = suffix[k-1]; 
        int peak_val = p[current_idx];

        if(prefix[prev_idx] > peak_val){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}