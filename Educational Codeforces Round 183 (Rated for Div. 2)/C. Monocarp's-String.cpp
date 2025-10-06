#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin>>n;
        cin>>s;
        // Count a and b
        int total_a = 0;
        int total_b = 0;
        for(char c:s){
            if(c=='a'){
                total_a++;
            }
            else{
                total_b++;
            }
        }
        if(total_a == total_b){
            cout<<0<<"\n";
            continue;
        }   
        
        int diff = total_a - total_b;

        map<int,int> last_pos;
        last_pos[0]=0;
        int min_len = n;
        int current_d = 0;

        for (int j = 1; j <= n; ++j) {
            if (s[j - 1] == 'a') {
                current_d++;
            } else {
                current_d--;
            }
        
            int target_d = current_d - diff;
            if (last_pos.count(target_d)) {
                int i = last_pos[target_d];
                min_len = min(min_len, j - i);
            }
        
            last_pos[current_d] = j;
        }
    
        if (min_len == n) {
            cout << -1 << "\n";
        } else {
            cout << min_len << "\n";
        }
    }   
    return 0;
}