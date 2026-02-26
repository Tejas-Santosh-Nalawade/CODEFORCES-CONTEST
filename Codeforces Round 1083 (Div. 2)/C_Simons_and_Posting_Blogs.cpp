#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXIMUM = 1000005;
bool local[MAXIMUM];
bool global[MAXIMUM];


void solve(){   
    int n; cin >> n;
    vector<vector<int>>v(n);
    
    for(int i=0; i<n; i++){
        int left;
        cin>>left;
        vector<int>a(left);

        for(int j=0; j<left; j++){
            cin>>a[j];
        }

        vector<int>local_dev;

        for(int j= left - 1; j>=0; j--){
            if(!local[a[j]]){
                local[a[j]] = true;
                local_dev.push_back(a[j]);
                v[i].push_back(a[j]);
            }

        }

        for(int c: local_dev){
            local[c] = false;
        }
    }

    vector<int> answer;

    vector<int>pack(n,0);

    vector<int>global_a;

    for(int s= 0; s<n; s++){
        int best = -1;
        vector<int>besty;

        for(int i=0; i<n; i++){
            if(pack[i]) continue;

            vector<int>curr;
            for(int x: v[i]){
                if(!global[x]){
                    curr.push_back(x);
                }
            }
            if(best == -1 || curr < besty){
                best = i;
                besty = curr;
            }
        }
        pack[best] = 1;

        for(int x: besty){
            global[x] = true;
            global_a.push_back(x);
            answer.push_back(x);
        }
    }
    for(int x: global_a){
       global[x] = false;
    }

    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<(i+ 1 == answer.size() ? "\n" : " ");
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
