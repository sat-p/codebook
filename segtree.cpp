#include <vector>
#include <limits>

// This is set up for range minimum queries, but can be easily adapted for computing other quantities.
// To enable lazy propagation and range updates, uncomment the following line.
#define LAZY
struct Segtree {
	uint32_T n;
	std::vector<uint32_T> data;
#ifdef LAZY
#define NOLAZY 2e9
#define GET(node) (lazy[node] == NOLAZY ? data[node] : lazy[node])
	vector<uint32_T> lazy;
#else
#define GET(node) data[node]
#endif
	void build_rec(uint32_T node, uint32_T* begin, uint32_T* end) {
		if (end == begin+1) {
			if (data.size() <= node) data.resize(node+1);
			data[node] = *begin;
		} else {
			uint32_T* mid = begin + (end-begin+1)/2;
			build_rec(2*node+1, begin, mid);
			build_rec(2*node+2, mid, end);
			data[node] = std::min(data[2*node+1], data[2*node+2]);
		}
	}
#ifndef LAZY
	void update_rec(uint32_T node, uint32_T begin, uint32_T end, uint32_T pos, uint32_T val) {
		if (end == begin+1) {
			data[node] = val;
		} else {
			uint32_T mid = begin + (end-begin+1)/2;
			if (pos < mid) {
				update_rec(2*node+1, begin, mid, pos, val);
			} else {
				update_rec(2*node+2, mid, end, pos, val);
			}
			data[node] = std::min(data[2*node+1], data[2*node+2]);
		}
	}
#else
	void update_range_rec(uint32_T node, uint32_T tbegin, uint32_T tend, uint32_T abegin, uint32_T aend, uint32_T val) {
		if (tbegin >= abegin && tend <= aend) {
			lazy[node] = val;
		} else {
			uint32_T mid = tbegin + (tend - tbegin + 1)/2;
			if (lazy[node] != NOLAZY) {
				lazy[2*node+1] = lazy[2*node+2] = lazy[node]; lazy[node] = NOLAZY;
			}
			if (mid > abegin && tbegin < aend)
				update_range_rec(2*node+1, tbegin, mid, abegin, aend, val);
			if (tend > abegin && mid < aend)
				update_range_rec(2*node+2, mid, tend, abegin, aend, val);
			data[node] = std::min(GET(2*node+1), GET(2*node+2));
		}
	}
#endif
	uint32_T query_rec(uint32_T node, uint32_T tbegin, uint32_T tend, uint32_T abegin, uint32_T aend) {
		if (tbegin >= abegin && tend <= aend) {
			return GET(node);
		} else {
#ifdef LAZY
			if (lazy[node] != NOLAZY) {
				data[node] = lazy[2*node+1] = lazy[2*node+2] = lazy[node]; lazy[node] = NOLAZY;
			}
#endif
			uint32_T mid = tbegin + (tend - tbegin + 1)/2;
			uint32_T res = std::numeric_limits<uint32_T>::max();
			if (mid > abegin && tbegin < aend) 
				res = std::min(res, query_rec(2*node+1, tbegin, mid, abegin, aend));
			if (tend > abegin && mid < aend)
				res = std::min(res, query_rec(2*node+2, mid, tend, abegin, aend));
			return res;
		}
	}

	// Create a segtree which stores the range [begin, end) in its bottommost level.
	Segtree(uint32_T* begin, uint32_T* end): n(end - begin) {
		build_rec(0, begin, end);
#ifdef LAZY
		lazy.assign(data.size(), NOLAZY);
#endif
	}

#ifndef LAZY
	// Call this to update a value (indices are 0-based). If lazy propagation is enabled, use update_range(pos, pos+1, val) instaed.
	void update(uint32_T pos, uint32_T val) {
		update_rec(0, 0, n, pos, val);
	}
#else 
	// Call this to update range [begin, end), if lazy propagation is enabled. Indices are 0-based.
	void update_range(uint32_T begin, uint32_T end, uint32_T val) {
		update_range_rec(0, 0, n, begin, end, val);
	}
#endif
	// Returns minimum in range [begin, end). Indices are 0-based.
	uint32_T query(uint32_T begin, uint32_T end) {
		return query_rec(0, 0, n, begin, end);
	}
};
