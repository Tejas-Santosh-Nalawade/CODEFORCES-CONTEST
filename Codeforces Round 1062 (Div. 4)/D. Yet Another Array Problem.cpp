#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

const int Maxp = 1000000;
vector<int> primes;

// sieve CALCULATION
void sieve() {
    vector<bool> isPrime(Maxp + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= Maxp; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= Maxp; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= Maxp; i++)
        if (isPrime[i]) primes.push_back(i);
}

// GCD CALCULATION
int gcd_ll(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

// GCD for array
int gcdarray(const vector<int>& a) {
    int g = a[0];
    for (int i = 1; i < (int)a.size(); i++)
        g = gcd_ll(g, a[i]);
    return g;
}

// Factorization using sieve primes
vector<int> primeFactors(long long n) {
    vector<int> factors;
    for (auto p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            factors.push_back(p);
            while (n % p == 0)
                n /= p;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

int32_t main() {
    fastio();
    sieve();

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int g = gcdarray(a);

        if (g == 1) {
            cout << 2 << endl;
            continue;
        }
        vector<int> pf = primeFactors(g);

        int ans = -1;
        for (int x = 2; x <= 1000000; x++) {
            bool ok = true;
            for (auto p : pf) {
                if (x % p == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = x;
                break;
            }
        }
        if (ans == -1) ans = 1000003;

        cout << ans << endl;
    }
    return 0;
}
