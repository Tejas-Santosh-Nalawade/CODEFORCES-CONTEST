    #include<bits/stdc++.h>
    using namespace std;
    #define int long long

    int listen(int i, int j){
        cout << "? " << i << " " << j << endl;
        int x; cin >> x;
        if(x == -1) exit(0);
        return x;
    }

    void print(int k){
        cout << "! " << k << endl;
    }
    void solve(){
        int n;cin>>n;

        if(listen(1, 2) == 1){
            print(1);
            return;
        }
        if(listen(2, 3) == 1){
            print(2);
            return;
        }
        if(listen(1, 3) == 1){
            print(1);
            return;
        }

        for(int i = 4; i <= 2* n - 1; i+=2){
            if(listen(i, i+1) == 1){
                print(i);
                return;
            }
        }
        print(2*n);    
    }

    int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int tt; cin >> tt;
        while (tt--) solve();
    }