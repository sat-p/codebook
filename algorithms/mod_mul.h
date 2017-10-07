#include <stdint.h>

/*****************************************************************************/

/*
 * NOTE: Required when multiplying numbers of order 10^18
 * NOTE: Returns (a * b) % c.
 */
inline uint64_t mod_mul (const uint64_t a, uint64_t b, const uint64_t m)
{
    uint64_t x = 0;
    uint64_t y = a % m;
    
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
