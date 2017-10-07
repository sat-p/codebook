int mod_exp (const int x, int y, const int MOD)
{
    long long ans = 1;
    long long m = x;
    
    while (y)
    {
        if (y & 1)
            ans = (ans * m) % MOD; 
        
        m = (m * m) % MOD;
        
        y >>= 1;
    }
    
    return ans;
}

/*
/* Checking using double hashing
/*/

int rabin_karp (const std::string& text, const std::string& search)
{
    constexpr int B = 2;
    
    constexpr int MOD1 = 1e9 + 7;
    constexpr int MOD2 = 1e9 + 9;
    
    if (text.size() < search.size())
        return 0;
    
    int ans = 0;
    
    long long hs1 = 0, hs2 = 0;
    
    for (const auto& c : search) {
    
        hs1 = (hs1 * B + c) % MOD1;
        hs2 = (hs2 * B + c) % MOD2;
    }
    
    long long ht1 = 0, ht2 = 0;
    
    const int M_ = search.size() - 1;
    const int N_ = text.size() - 1;
    
    rep (i, 0, M_) {
    
        ht1 = (ht1 * B + text[i]) % MOD1;
        ht2 = (ht2 * B + text[i]) % MOD2;
    }
    
    if (ht1 == hs1 && ht2 == hs2)
        ans = 1;
    
    const long long inv1 = mod_exp (B, M_, MOD1);
    const long long inv2 = mod_exp (B, M_, MOD2);
    
    rep (i, search.size(), N_) {
        
        const int prev = i - search.size();
        
        ht1 -= (text[prev] * inv1) % MOD1;
        ht2 -= (text[prev] * inv2) % MOD2;
        
        ht1 = (ht1 * B + text[i]) % MOD1;
        ht2 = (ht2 * B + text[i]) % MOD2;
        
        if (ht1 < 0)
            ht1 += MOD1;
        if (ht2 < 0)
            ht2 += MOD2;
        
        if (ht1 == hs1 && ht2 == hs2)
            ++ans;
    }
    
    return ans;
}
