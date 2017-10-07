#include "../template.h"

/*****************************************************************************/

const u32 MOD = 1e9 + 7;

/*****************************************************************************/

std::unordered_map <u32, u32> mem = {
                                        {1, 1},
                                        {2, 1},
                                        {3, 2},
                                        {4, 3},
                                        {5, 5},
                                        {6, 8}
                                    };

/*
 * NOTE: Returns the ith fibonnacci term.
 * NOTE: a0 = 0 & a1 = 1.
 */

inline u32 mod_fibonnacci (const u32 i) {

    if (!i)
        return 0;
    
    if (const u32 val = mem[i])
        return val;
    
    const u32 n = (i + 1) >> 1;
    const u32 f_n   = mod_fibonnacci (n);
    const u32 f_n_1 = mod_fibonnacci (n - 1);
    
    if (i & 1) {
        // If i is odd : F(2*n-1)=F(n)*F(n)+F(n-1)*F(n-1) 
        u64 ans = static_cast<u64> (f_n)   * f_n +
                  static_cast<u64> (f_n_1) * f_n_1;
        ans %= MOD;
        
        mem[i] = ans;
        return ans;
    }
    else {
        // If i is even : F(2*n)=(2*F(n-1)+F(n))*F(n)
        
        u64 ans = static_cast<u64> ((f_n_1 << 1) + f_n) * f_n;
        ans %= MOD;
        
        mem[i] = ans;
        return ans;
    }
}

/*****************************************************************************/