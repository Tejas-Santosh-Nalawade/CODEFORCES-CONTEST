#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

int main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        int n;cin>>n;
        string s; cin>>s;
        int count =0;
        char last = s[n-1];
        for(char c:s){
            if(c != last){
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}