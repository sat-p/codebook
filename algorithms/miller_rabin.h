#include "../template.h"

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

inline uint64_t mod_exp (const uint64_t n, uint64_t k, const uint64_t m)
{
    uint64_t x = 1;
    uint64_t y = n;
    
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

u8 b[] = {2, 3,  5,  7,  11,
         13, 17, 19, 23, 29,
         31, 37, 41, 43, 47,
         53, 59, 61, 67, 71,
         73, 79, 83, 89, 97};

template
<typename size_t = uint64_t>
class MillerRabin
{
public:
    MillerRabin (u8 count = 3) :
        _count (count)
    { srand (time (NULL));}

public:
    bool isPrime (const size_t num)
    {
        size_t s = num - 1;
        
        rep8 (i, 25) {
            if (num == b[i])
                return true;
        else if (!(num % b[i]))
                return false;
        }
        
        while (!(s & 1))
            s >>= 1;
        
        rep32 (i, _count) {
        
            const size_t a = (rand() % (num - 1)) + 1;
            size_t temp = s;
            
            size_t mod = mod_exp (a, temp, num);
            
            while ((temp != num - 1) && (mod != 1) && (mod != num - 1)) {
            
                mod = mod_mul (mod, mod, num);
                temp <<= 1;
            }
            
            if ((mod != num - 1) && !(temp & 1))
                return false;
        }
        
        return true;
    }

private:
    u8 _count;
};

/*****************************************************************************/
/*****************************************************************************/