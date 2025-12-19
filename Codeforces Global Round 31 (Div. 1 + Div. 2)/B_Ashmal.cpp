#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;cin>>n;
    vector<string>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    string best_string = a[0];

    for(int i=1; i<n; i++){
        string choice_1 = a[i] + best_string;
        string choice_2 = best_string + a[i];

        if(choice_1 < choice_2){
            best_string = choice_1;
        }
        else{
            best_string = choice_2;
        }
    }
    cout<<best_string<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
