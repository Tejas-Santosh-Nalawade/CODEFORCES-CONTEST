// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// void solve(){
//     int n; cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n; i++){
//         cin>>arr[i];
//     }
    
//     if(arr[0] != -1 && arr[n-1] != -1) {
//     }
//     else if(arr[0] != -1 && arr[n-1] == -1) {
//         arr[n-1] = arr[0];
//     }
//     else if(arr[0] == -1 && arr[n-1] != -1) {
//         arr[0] = arr[n-1];
//     }
//     else {
//         arr[0] = 0;
//         arr[n-1] = 0;
//     }

//     for(int i=1; i<n-1; i++){
//         if(arr[i] == -1) {
//             arr[i] = 0;
//         }
//     }
//     cout << abs(arr[n-1] - arr[0]) << "\n";
//     for(int i=0; i<n; i++){
//         cout << arr[i] << (i == n-1 ? "" : " ");
//     }
//     cout << "\n";
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
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n; i++){
        cin>>a[i];
    }
    if (a[0] == -1) {
        a[0] = (a[n-1] != -1) ? a[n-1] : 0;
    }
    if (a[n-1] == -1) {
        a[n-1] = a[0];
    }
    for(int i=1; i<n-1; i++){
        if(a[i] == -1) a[i] = 0;
    }
    cout << abs(a[n-1] - a[0]) << "\n";
    for(int i=0; i<n; i++){
        cout << a[i] << (i == n-1 ? "" : " ");
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