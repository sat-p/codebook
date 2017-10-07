#include "../template.h"

/*****************************************************************************/
/*****************************************************************************/

/*
 * WARNING: The function currently returns minimum possible output.
 * WARNING: It is also setup to reject 0xFF.
 */
template < typename It1, typename It2>
i64 knapsack (u32 money, u32 items, It1 cost_it, It2 val_it)
{
    static i64 DP [100001][501];

    fill0n (DP[0], money + 1);

    rep32_1 (i, items)
        DP[i][0] = 0;

    rep32_1 (i, items) {

        if (*val_it < 0 && *cost_it != 0xFF) {
            rep32_1 (m, money) {
                if (m < *cost_it)
                    DP[i][m] = DP[i - 1][m];
                else
                    DP[i][m] = std::min (DP[i - 1][m],
                                         DP[i - 1][m - *cost_it] + *val_it);
                }
        }
        else {
            rep32_1 (m, money)
                DP[i][m] = DP[i - 1][m];
        }

        ++val_it;
        ++cost_it;
    }

    return DP[items][money];
}

/*****************************************************************************/
