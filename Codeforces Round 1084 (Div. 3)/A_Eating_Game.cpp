// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve(){
//     int n; cin>>n;
//     vector<int>a(n);
//     int max_value = 0;
//     for(int i=0; i<n;i++){
//         cin>>a[i];
//         max_value = max(max_value , a[i]);
//     }

//     int solution = 0;

//     for(int i=0;i<n; i++){
//        if(a[i] == max_value){
//             solution++;
//        } 
//     }
//     cout<<solution<<"\n";
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
void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int max_val = *max_element(a.begin(), a.end());
    
    int ans = count(a.begin(), a.end(), max_val);
    
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}