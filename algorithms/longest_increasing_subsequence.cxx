#include "../template.h"

/*****************************************************************************/

u32 tail[1000000];
template <typename it_t>
u32 LIS (it_t it, it_t it_end)
{    
    if (it == it_end)
        return 0;
    
    *tail = *it;
    u32 length = 1;
    
    while (++it != it_end) {
    
        if (*it < *tail)
            *tail = *it;
        else if (*it > *(tail + length - 1))
            *(tail + length++) = *it;
        else {
            *std::lower_bound (tail, tail + length, *it) = *it;
        }
    }
    
    return length;
}

/*****************************************************************************/