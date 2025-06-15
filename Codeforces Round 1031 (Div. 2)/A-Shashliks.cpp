#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll k, ll a, ll b, ll x  ,ll y)
{
     // A first then B
    ll ans = 0;

    ll temp = k;
    ll countA = 0;
    if(temp >= a){
        countA = (temp - a) / x + 1;
        temp -= countA * x; 
    }

    ll countB = 0;

    if(temp >= b){
        countB = (temp - b) / y + 1;
    }

    ans = countA + countB;

    // B first then A

    temp = k;

    ll countB2 = 0;
    if(temp >= b){
        countB2 = (temp - b) / y + 1;
        temp -= countB2 * y; 
    }

    ll countA2 = 0;
    if(temp >= a){
        countA2 = (temp - a) / x + 1;
    }

    ans = max(ans, countA2 + countB2);

    return  ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin>>tt;
    while(tt--)
    {
        ll k, a, b, x , y;
        cin >> k >> a >> b >> x >> y;
        cout<<solve(k ,a ,b, x, y)<<"\n";
    }
    return 0;
}
