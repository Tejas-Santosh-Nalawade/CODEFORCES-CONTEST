#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

// Flush output
void flush_output() {
    cout.flush();
}

/**
 * @brief Sends a query to the interactor and reads the response.
 */
int query(int u, int v) {
    if (u > v) swap(u, v);
    
    cout << u << " " << v << "\n";
    flush_output();
    int x;
    if (!(cin >> x)) {
        exit(0);
    }
    if (x == -1) {
        exit(0);
    }
    return x;
}

/**
 * @brief Solves the Batteries problem using the Two-Phase Tournament Strategy.
 */
void solve_batteries() {
    int n;
    if (!(cin >> n)) return;

    // Use a deque for Phase 1: Sequential Elimination (Tournament Reduction).
    deque<int> candidates;
    for (int i = 1; i <= n; ++i) {
        candidates.push_back(i);
    }
    
    // Phase 1: Sequential Elimination. Finds one guaranteed working battery W*. Cost: O(N).
    while (candidates.size() >= 2) {
        int u = candidates.front();
        candidates.pop_front();
        int v = candidates.front();
        candidates.pop_front();

        int result = query(u, v);
        
        if (result == 1) {
            // Success! Found a working pair (u, v).
            return;
        } else {
            // Result is 0 (Failure). Eliminate 'u' and re-insert 'v' as the stronger candidate.
            candidates.push_front(v); 
        }
    }
    
    // Phase 2 is mandatory to find the final pair.
    if (candidates.empty()) {
        // This should not happen since N >= 2
        return;
    }
    
    int w_star = candidates.front(); // The single remaining candidate, guaranteed to work.
    
    // Phase 2: Probe W* against all N-1 other batteries. Cost: O(N).
    for (int j = 1; j <= n; ++j) {
        if (j == w_star) continue;

        if (query(w_star, j) == 1) {
            // Success! Found the working pair (W*, j).
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve_batteries();
    }
    return 0;
}