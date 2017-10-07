#include <vector>
#include <stdint.h>

/*****************************************************************************/

class PrimeSeive
{
    typedef uint32_t data_t;
    
public:
    PrimeSeive (const data_t x) :
     _sp    (x + 1, 0)
     { seive (x); }

public:
    bool isPrime (const data_t x) const
    { return (_sp[x] == x); }
    
    
    /*
     * Function factorizes a number x and returns all its unique factors.
     * NOTE: Can be modified to obtain factors of a number.
     */
//     std::vector<data_t> unique_factorize (data_t x) {
//     
//         std::vector<data_t> unique_factors;
//         
//         data_t last_p = 0;
//         
//         while (!_sp[x])
//         {
//             if (_sp[x] != last_p) {
//             
//                 last_p = _sp[x];
//                 unique_factors.push_back (last_p);
//             }
//             
//             x = _q[x];
//         }
//         
//         return unique_factors;
//     }
     
public:
    const std::vector<data_t>& fetchPrimes (void) const
    { return _p; }
        
private:
    void seive (const data_t x)
    {        
        data_t i = 1;
        
        _p.push_back (2);
        
        while (1) {
        
            const data_t i2 = i << 1;
            
            if (i2 > x) {
                break;
            }
            else {
                _sp[i2] = 2;
//                 _q[i2] = i;
            }
            ++i;
        }
        
        for (data_t p = 3; p <= x; p += 2) {
            if (!_sp[p]) {
                
                _p.push_back (p);
                
                i = 1;
                
                while (1) {
            
                    const data_t i2 = i * p;
                    
                    if (i2 > x) {
                        break;
                    }
                    else {
                        _sp[i2] = p;
//                         _q[i2] = i;
                    }
                    ++i;
                }
            }
        }
    }
    
private:
    std::vector<data_t> _sp;
//     std::vector<data_t> _q;
    std::vector<data_t> _p;
};

/*****************************************************************************/