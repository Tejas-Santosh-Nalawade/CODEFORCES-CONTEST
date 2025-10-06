#include <bits/stdc++.h>
using namespace std;

const int MAXN = 35;
const int MAX_S = 450;

bool dp[MAXN][MAX_S];
int choice[MAXN][MAX_S];

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    long long total_subsegments = (long long)n * (n - 1) / 2;
    long long S = total_subsegments - k;

    memset(dp, 0, sizeof(dp));
    memset(choice, 0, sizeof(choice));
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= S; ++j) {
            for (int p = 1; p <= i; ++p) {
                long long p_score = (long long)p * (p - 1) / 2;
                if (j >= p_score && dp[i - p][j - p_score]) {
                    dp[i][j] = true;
                    choice[i][j] = p;
                    break;
                }
            }
        }
    }

    if (!dp[n][S]) {
        cout << 0 << "\n";
        return;
    }

    vector<int> run_lengths;
    int current_n = n;
    long long current_S = S;
    while (current_n > 0) {
        int p = choice[current_n][current_S];
        run_lengths.push_back(p);
        current_n -= p;
        current_S -= (long long)p * (p - 1) / 2;
    }

    vector<int> result;
    int end_num = n;
    for (int len : run_lengths) {
        int start_num = end_num - len + 1;
        for (int i = start_num; i <= end_num; ++i) result.push_back(i);
        end_num = start_num - 1;
    }

    for (int i = 0; i < n; ++i) cout << result[i] << (i == n - 1 ? "\n" : " ");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
}
