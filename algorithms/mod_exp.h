#include <stdint.h>

/*****************************************************************************/

/*
 * NOTE: Returns n^k % m
 */

inline int mod_exp (int n, int k, const int m)
{
    long long x = 1;
    long long y = n;
    
    while (k) {
    
        if (k & 1)  // if k is odd
            x = (x * y) % m;
        
        y = (y * y) % m; // squaring the base
        k >>= 1;
    }
    
    return x;
}

/*****************************************************************************/
/*****************************************************************************/

/*
 * NOTE: Required when multiplying numbers of order 10^18
 * NOTE: Returns (a * b) % c.
 */
inline long long mod_mul (const long long a, long long b, const long long m)
{
    long long x = 0;
    long long y = a % m;
    
    while(b > 0) {
        
        if(b & 1) {
            x += y;
            if (x >= m)
                x -= m;
        }
        
        y <<= 1;
        if (y >= m)
            y -= m;
        
        b >>= 1;
    }
    
    return x;
}

/*****************************************************************************/

inline long long mod_exp (const long long n, long long k, const long long m)
{
    long long x = 1;
    long long y = n;
    
    while (k) {
    
        if (k & 1)  // if k is odd
            x = mod_mul (x , y, m);
        
        y = mod_mul (y , y, m); // squaring the base
        k >>= 1;
    }
    
    return x;
}

/*****************************************************************************/
/*****************************************************************************/