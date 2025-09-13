#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int len;
            cin >> len;
            arr[i].resize(len);
            for (int j = 0; j < len; j++) {
                cin >> arr[i][j];
            }
        }

        vector<int> ans;
        vector<int> active;
        for (int i = 0; i < n; i++) active.push_back(i);

        int col = 0;

        while (!active.empty()) {
            vector<int> cur = active;
            int pick = -1, checkCol = col;

            while (pick == -1) {
                if (cur.size() == 1) {
                    pick = cur[0];
                    break;
                }

                int minVal = INT_MAX;
                int shortest = INT_MAX, shortIdx = -1;

                for (int idx : cur) {
                    if (checkCol >= arr[idx].size()) {
                        if ((int)arr[idx].size() < shortest) {
                            shortest = arr[idx].size();
                            shortIdx = idx;
                        }
                    } else {
                        minVal = min(minVal, arr[idx][checkCol]);
                    }
                }

                if (shortIdx != -1) {
                    pick = shortIdx;
                    break;
                }

                vector<int> nxt;
                for (int idx : cur) {
                    if (checkCol < arr[idx].size() && arr[idx][checkCol] == minVal) {
                        nxt.push_back(idx);
                    }
                }
                cur = nxt;
                checkCol++;
            }

            for (int j = col; j < (int)arr[pick].size(); j++) {
                ans.push_back(arr[pick][j]);
            }
            col = arr[pick].size();

            vector<int> nextActive;
            for (int idx : active) {
                if ((int)arr[idx].size() > col) {
                    nextActive.push_back(idx);
                }
            }
            active = nextActive;
        }

        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
        }
    }
    return 0;
}
