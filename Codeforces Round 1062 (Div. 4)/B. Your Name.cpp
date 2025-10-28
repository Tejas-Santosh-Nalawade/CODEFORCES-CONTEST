// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long 
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int q;
//     cin >> q;
//     while (q--) {
//  		ll n;
//  		cin>>n;
//  		string s,t;
//  		cin>>s>>t;
 		
//  		sort(s.begin(),s.end());
 		
//  		sort(t.begin(),t.end());
 		
//  		if(s == t){
//  			cout<<"YES"<<"\n";
//  		}
//  		else{
//  			cout<<"NO"<<"\n";
//  		}	
 		
// 	}

    
//     return 0;
// }


// OPTIMAL SOLUTION
// USING FREQUENCY MAP


#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

int32_t main() {
    fastio();

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        map<char, int> frequencyS, frequencyT;

        for (char c : s) frequencyS[c]++;
        for (char c : t) frequencyT[c]++;

        if (frequencyS == frequencyT) yes;
        else no;
    }

    return 0;
}
