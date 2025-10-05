#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solves Abraham's Great Escape problem.
 * Constructs an N x N grid with exactly K escapable cells ('U').
 * Remaining cells form a cycle to prevent escape.
 */
void solve() {
    int n, k;
    cin >> n >> k;

    long long totalCells = (long long)n * n;

    // Impossible case: only one cell left for cycle
    if (k == totalCells - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<string> grid(n, string(n, ' '));

    // Fill the grid
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            long long index = (long long)row * n + col;

            if (index < k) {
                // First K cells are escapable
                grid[row][col] = 'U';
            } else {
                // Remaining cells form a cycle or point towards it
                if (row == n - 1) {
                    // Bottom row: create a small 2-cell cycle at the end
                    if (col == n - 1) {
                        grid[row][col] = 'L';  // Rightmost points left
                    } else if (col == n - 2) {
                        grid[row][col] = 'R';  // Second-to-last points right
                    } else {
                        grid[row][col] = 'R';  // Other bottom cells point right
                    }
                } else {
                    // All other cycle cells point downwards
                    grid[row][col] = 'D';
                }
            }
        }
    }

    // Print the final grid
    for (int row = 0; row < n; ++row) {
        cout << grid[row] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) solve();

    return 0;
}
