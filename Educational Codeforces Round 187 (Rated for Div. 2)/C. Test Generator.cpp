#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void processTestCase() {
    ull target_sum, allowed_mask;
    cin >> target_sum >> allowed_mask;

    int smallest_usable_bit = __builtin_ctzll(allowed_mask);
    
    ull min_divisor = (1ULL << smallest_usable_bit);
    if (target_sum % min_divisor != 0) {
        cout << -1 << endl;
        return;
    }

    ull left_bound = 1;
    ull right_bound = target_sum >> smallest_usable_bit;
    ull result = right_bound;

    while (left_bound <= right_bound) {
        ull candidate = (left_bound + right_bound) / 2;
        
        __int128 leftover = 0;
        
        int bit_pos = 61;
        while (bit_pos >= 0) {
            __int128 needed_count = leftover + ((target_sum >> bit_pos) & 1ULL);
            
            bool bit_available = ((allowed_mask >> bit_pos) & 1ULL);
            
            if (bit_available) {
                if (needed_count > candidate) {
                    leftover = (needed_count - candidate) * 2;
                } else {
                    leftover = 0;
                }
            } else {
                leftover = needed_count * 2;
            }
            
            bit_pos--;
        }
        
        if (leftover == 0) {
            result = candidate;
            right_bound = candidate - 1;
        } else {
            left_bound = candidate + 1;
        }
    }
    
    cout << (long long)result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cases;
    cin >> test_cases;
    
    for (int i = 0; i < test_cases; i++) {
        processTestCase();
    }
    
    return 0;
}