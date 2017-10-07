/*
 * 
 * 
 * WARNING: Incomplete Program
 * 
 * 
 */

/*****************************************************************************/

/*
 * NOTE: Returns n^k % m
 */

inline uint32_t mod_exp (uint32_t n, uint32_t k, const uint32_t m)
{
    uint64_t x = 1;
    uint64_t y = n;
    
    while (k) {
    
        if (k & 1)  // if k is odd
            x = (x * y) % m;
        
        y = (y * y) % m; // squaring the base
        k >>= 1;
    }
    
    return x;
}

/*****************************************************************************/

u64 fac[65];

inline void init_factorial (void)
{
    fac[0] = 1;
    
    u64 ans = 1;
    
    rep8_1 (i, 64) {
    
        ans = (ans * i) % MOD;
        fac[i] = ans;
    }
}

u32 inv[65];

inline void init_inv (void)
{
    inv[0] = 1;
    inv[1] = 1;
    
    REP8 (i, 2, 64) {
    
        inv[i] = mod_exp (fac[i], MOD - 2, MOD);
    }
}

/*****************************************************************************/