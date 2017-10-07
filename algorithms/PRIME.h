#include <stdint.h>
#include <cmath>
#include <set>

class Prime
{
    typedef uint32_t data_t;

public:
    Prime (const data_t x = 2)
    {
        _primes.insert (2);
        generate_primes_till (x);
    }
    
public:
    bool isPrime (const data_t x)
    {
        if (x < *(_primes.crbegin()))
            return _primes.count (x);
        
        generate_primes_till (x);
        return (*(_primes.crbegin()) == x);
    }
    
private:
    void generate_primes_till (const data_t x)
    {
        for (data_t num = *(_primes.crbegin()) + 1;  num <= x; ++num) {

            const data_t p_max = std::sqrt (num);
            bool isPrime = true;

            for (const auto& p : _primes) {
                if (p <= p_max) {
                    if (!(num % p)) {
                        isPrime = false;
                        break;
                    }
                }
                else
                    break;
            }

            if (isPrime)
                _primes.insert (num);
        }
    }
    
private:
    std::set<data_t> _primes;
};

// class Prime
// {
//     typedef uint32_t data_t;
// 
// public:
//     Prime (const data_t x = 2)
//     {
//         _primes.push_back (2);
//         generate_primes_till (x);
//     }
//     
// public:
//     bool isPrime (const data_t x)
//     {
//         auto it = std::binary_search<data_t> (_primes.begin(), _primes.end(),
//                                               x);
//         return (it != _primes.end());
//     }
//     
//     const std::vector<data_t>& get_primes (void)
//     { return _primes;}
//     
//     size_t numPrimes (void)
//     { return _primes.size();}
// 
// private:
//     void generate_primes_till (const data_t x)
//     {
//         for (data_t num = *(_primes.crbegin()) + 1;  num <= x; ++num) {
// 
//             const data_t p_max = std::sqrt (num);
//             bool isPrime = true;
// 
//             for (const auto& p : _primes) {
//                 if (p <= p_max) {
//                     if (!(num % p)) {
//                         isPrime = false;
//                         break;
//                     }
//                 }
//                 else
//                     break;
//             }
// 
//             if (isPrime)
//                 _primes.push_back (num);
//         }
//     }
//     
// private:
//     std::vector<data_t> _primes;
// };