#include <stdint.h>

/*****************************************************************************/

typedef uint32_t EUCLID_t;
EUCLID_t gcf (EUCLID_t a, EUCLID_t b) {

    if (a < b) {
    
        const EUCLID_t temp = a;
        a = b;
        b = temp;
    }
    
    if (b == 0)
        return a;
    
    while (1) {

        if (const EUCLID_t c = a % b) {
            
            a = b;
            b = c;
        }
        else
            return b;
    }
}

/*****************************************************************************/