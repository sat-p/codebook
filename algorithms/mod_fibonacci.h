
const int MOD = 1e9 + 7;

/*****************************************************************************/

std::unordered_map <int, int> mem = {
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

inline int mod_fibonnacci (const int i) {

    if (!i)
        return 0;
    
    const int n = (i + 1) >> 1;
    const int f_n   = mod_fibonnacci (n);
    const int f_n_1 = mod_fibonnacci (n - 1);
    
    if (i & 1) {
        // If i is odd : F(2*n-1)=F(n)*F(n)+F(n-1)*F(n-1) 
        long long ans = static_cast<long long> (f_n)   * f_n +
                        static_cast<long long> (f_n_1) * f_n_1;
        ans %= MOD;
        
        return ans;
    }
    else {
        // If i is even : F(2*n)=(2*F(n-1)+F(n))*F(n)
        
        long long ans = static_cast<long long> ((f_n_1 << 1) + f_n) * f_n;
        ans %= MOD;
        
        return ans;
    }
}

/*****************************************************************************/