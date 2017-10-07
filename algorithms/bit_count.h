/*
 * Counts the number of 1s in 64bit unsigned integer
 */

/*****************************************************************************/

inline u8 count1 (u64 x)
{
    x = (0x5555555555555555ULL & x) + (0x5555555555555555ULL & (x >> 1));
    x = (0x3333333333333333ULL & x) + (0x3333333333333333ULL & (x >> 2));
    x = (0x0F0F0F0F0F0F0F0FULL & x) + (0x0F0F0F0F0F0F0F0FULL & (x >> 4));
    x = (0x00FF00FF00FF00FFULL & x) + (0x00FF00FF00FF00FFULL & (x >> 8));
    x = (0x0000FFFF0000FFFFULL & x) + (0x0000FFFF0000FFFFULL & (x >> 16));
    x = (0x00000000FFFFFFFFULL & x) + (0x00000000FFFFFFFFULL & (x >> 32));
    
    return x;
}

/*****************************************************************************/