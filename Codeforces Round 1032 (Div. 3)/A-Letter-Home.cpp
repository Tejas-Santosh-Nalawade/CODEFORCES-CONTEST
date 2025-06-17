#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,s;
        cin>>n>>s;

        vector<int> x(n);

        for(int i=0; i<n; i++){
            cin>>x[i];
        }

        int left = x[0];           
        int right = x[n - 1];

        int total_range = right - left;
        int extra = min(abs(s - left), abs(s - right));

        int steps = total_range + extra;
        
        cout << steps << '\n';
        
    }    return 0;
}