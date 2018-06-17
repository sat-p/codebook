#include <bits/stdc++.h>

// Fenwick Tree
struct BIT
{   
    typedef int dt;
    int n;
    std::vector<dt> bit;
    BIT (int n) : n (n), bit (n + 1) {}
    
    // returns sum till idx
    dt read (int idx) {
    
        dt res = 0;
        while (idx > 0) {
        
            res += bit[idx];
            idx -= idx & (-idx);
        }
        
        return res;
    }
    
    void update (int idx, dt val)
    {
        while (idx <= n) {
        
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    
    /*
     * Below code may not be required for most tasks.
     */
    
    // Similar to STL's lower bound function.
    // Returns smallest positive idx such that read(idx) > target.
    int lower_bound (dt target)
    {
        if (target <= 0) return 1;
        dt pwr = 1;
        while (pwr * 2 <= n) pwr *= 2;
        int idx = 0; dt tot = 0;
        while (pwr) {
            if (idx + pwr <= n && tot + bit[idx + pwr] < target)
                tot += bit[idx += pwr];
            pwr >>= 1;
        }
        return idx + 1;
    }
    
    // Similar to STL's upper bound function.
    // Returns smallest positive idx such that read(idx) >= target
    int upper_bound (dt target)
    {
        if (target < 0) return 1;
        dt pwr = 1;
        while (pwr * 2 <= n) pwr *= 2;
        int idx = 0; dt tot = 0;
        while (pwr) {
            if (idx + pwr <= n && tot + bit[idx + pwr] <= target)
                tot += bit[idx += pwr];
            pwr >>= 1;
        }
        
        return idx + 1;
    }
};