/*****************************************************************************/

const u32 MOD  = 1e9 + 7;
const u32 MOD_ = MOD - 1;

/*****************************************************************************/

u32 fac [200001];

inline void initFactorial (void)
{
    fac[0] = 1;
    
    u64 f = 1;
    
    rep32_1 (i, 200000) {
    
        f = (f * i) % MOD_;
        *(fac + i) = f;
    }
}

inline u32 mod_factorial (const u32 n)
{
    return fac[n];
}

/*****************************************************************************/

std::unordered_map<u32, u32> cat = {
                                        {0, 1},
                                        {1, 2},
                                        {2, 6}
                                   };

inline u32 mod_catalan (const u32 n, const u32 p = MOD_)
{
    if (const u32 val = cat[n])
        return val;
    
    const u64 fac_2n = mod_factorial (n << 1);
    const u64 fac_n  = mod_factorial (n);
        
    const u32 inv = mod_exp (fac_n, 500000001, MOD_); // phi MOD_ = 500000002
    
    const u32 ans = (((fac_2n * inv) % p) * inv) % p;
    
    return cat[n] = ans;
}

/*****************************************************************************/
/*****************************************************************************/