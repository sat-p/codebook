#include <bits/stdc++.h>

/*
 * Currently written for range minimum query.
 */

#define BASIC \
    int l = 2 * node + 1; \
    int r = l + 1; \
    auto mid = begin + (end - begin + 1) / 2;
    
#define LAZY
struct Segtree {
    
    typedef int dt;
    std::vector<dt> data;
    int n;
    
#ifdef LAZY
#define NOLAZY 2e9
#define GET(node) (lazy[node] == NOLAZY) ? data[node] : lazy[node]
    std::vector<dt> lazy;
#endif
    
    void build_rec (int node, dt* begin, dt* end)
    {
        if (end == begin + 1) {
            if (data.size() <= node) data.resize (node + 1);
            data[node] = *begin;
        }
        else {
            
            BASIC
            
            build_rec (l, begin, mid);
            build_rec (r, mid, end);
            data[node] = std::min (data[l], data[r]);
        }
    }

#ifdef LAZY
    void update_range_rec (int node, int begin, int end, int rbegin, int rend, dt val)
    {
        if (begin >= rbegin && end <= rend)
            lazy[node] = val;
        else {
        
            BASIC
            
            if (lazy[node] != NOLAZY) {
                lazy[l] = lazy[r] = lazy[node];
                lazy[node] = NOLAZY;
            }
            
            if (mid > rbegin && begin < rend)
                update_range_rec (l, begin, mid, rbegin, rend, val);
            if (end > rbegin && mid < rend)
                update_range_rec (r, mid, end, rbegin, rend, val);
            data[node] = std::min (GET (l), GET (r));
        }
    }
#else
    void update_rec (int node, int begin, int end, int pos, dt val)
    {
        if (end == begin + 1)
            data[node] = val;
        else {
        
            BASIC
            
            if (pos < mid)
                update_rec (l, begin, mid, pos, val);
            else
                update_rec (r, mid, end, pos, val);
            data[node] = std::min (data[l], data[r]);
        }
    }
#endif
    dt query_rec (int node, int begin, int end, int rbegin, int rend)
    {
    
        if (begin >= rbegin && end <= rend)
            return data[node];
        else {
            
            BASIC
#ifdef LAZY   
            if (lazy[node] != NOLAZY) {
                data[node] = lazy[l] = lazy[r] = lazy[node];
                lazy[node] = NOLAZY;
            }
#endif

            dt res = std::numeric_limits<dt>::max();
            if (mid > rbegin && begin < rend)
                res = std::min (res, query_rec (l, begin, mid, rbegin, rend));
            if (end > rbegin && mid < rend)
                res = std::min (res, query_rec (r, mid, end, rbegin, rend));
            return res;
        }
    }
    
    Segtree (dt* begin, dt* end) : n (end - begin)
    {
        build_rec (0, begin, end);
#ifdef LAZY        
        lazy.assign (data.size(), NOLAZY);
#endif
    }

#ifdef LAZY
    void update_range (int begin, int end, dt val)
    { update_range_rec (0, 0, n, begin, end, val); }
#else
    void update (int pos, dt val)
    { update_rec (0, 0, n, pos, val); }
#endif

    dt query (int begin, int end)
    { return query_rec (0, 0, n, begin, end); }
};