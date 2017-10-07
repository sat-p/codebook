/*
 * NOTE: Below program currently generates all combinations with n, r <= 64 
 */

/*****************************************************************************/

unsigned long long nCr_[65][65];

inline void init_nCr (void)
{
    rep (n, 0, 64)
        nCr_[n][0] = 1;
    
    rep (n, 1, 64)
        rep (r, 1, n)
            nCr_[n][r] = nCr_[n - 1][r] + nCr_[n - 1][r - 1];    
}

inline unsigned long long nCr (const int n, const int r)
{ return nCr_[n][r]; }



/*****************************************************************************/