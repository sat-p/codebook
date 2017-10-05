#include <bits/stdc++.h>

// Fenwick Tree
struct BIT
{   
    typedef int dt;
    int n;
    std::vector<dt> bit;
    BIT (int n) : n (n), bit (n + 1) {}
    
    dt read (int idx) {
    
        dt res = 0;
        while (idx > 0) {
        
            res += bit[idx];
            idx -= idx & (-idx);
        }
        
        return res;
    }
    
    void update (int idx, int val)
    {
        while (idx <= n) {
        
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    
    /*
     * Below code may not be required for most tasks.
     */
    
    // Similar to STL's lower bound function
    int lower_bound (dt target)
    {
        if (target <= 0) return 0;
        dt pwr = 1;
        while (pwr * 2 <= n) pwr *= 2;
        int idx = 0;
        dt tot = 0;
        while (pwr) {
            if (idx + pwr <=  n && tot + bit[idx + pwr] < target)
                tot += bit[idx += pwr];
            pwr >>= 1;
        }
        return idx + 1;
    }
    
    // Similar to STL's upper bound function
    int upper_bound (dt target)
    {
        if (target <= 0) return 0;
        dt pwr = 1;
        while (pwr * 2 <= n) pwr *= 2;
        int idx = 0;
        dt tot = 0;
        while (pwr) {
            if (idx + pwr <= n && tot + bit[idx + pwr] <= target) // <= instead of <
                tot += bit[idx += pwr];
            pwr >>= 1;
        }
    }
};