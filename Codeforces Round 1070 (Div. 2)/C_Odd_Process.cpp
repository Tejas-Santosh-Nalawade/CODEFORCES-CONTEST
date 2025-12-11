#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> odd_List, even_List;
    for(int i = 0; i < n; i++){
        int z;
        cin >> z;
        if(z & 1) odd_List.push_back(z);
        else even_List.push_back(z);
    }
    sort(odd_List.begin(), odd_List.end(), greater<int>());
    sort(even_List.begin(), even_List.end(), greater<int>());
    int oc = odd_List.size(), ec = even_List.size();
    vector<int> prefE(ec+5);
    for(int p = 1; p <= ec; p++){
        prefE[p] = prefE[p-1] + even_List[p-1];
    }

    if(oc == 0){
        for(int kk = 1; kk <= n; kk++){
            cout << 0;
            if(kk != n) cout << " ";
        }
        cout << "\n";
        return;
    }

    int bigOdd = odd_List[0];

    for(int k = 1; k <= n; k++){
        int aa = k - oc;
        if(aa < 0) aa = 0;
        int bb = k - 1;
        if(bb > ec) bb = ec;

        if(aa > bb){
            cout << 0 << (k==n? "" : " ");
            continue;
        }

        int whatParity = (k % 2 ? 0 : 1);  
        int pickj = -1;
        if((bb % 2) == whatParity){
            pickj = bb;
        } else {
            if(bb - 1 >= aa){
                if(((bb - 1) % 2) == whatParity){
                    pickj = bb - 1;
                }
            }
        }

        if(pickj < 0){
            cout << 0 << (k==n? "" : " ");
            continue;
        }

        int ans = prefE[pickj] + bigOdd;
        cout << ans << (k==n? "" : " ");
    }

    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
