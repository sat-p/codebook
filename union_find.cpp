#include <bits/stdc++.h>

#define rep(i, a, b)    for (int i = a; i <= b; ++i)

constexpr int SIZE = 1000;

std::vector<int> pset (SIZE);

void initSet (int size = SIZE)
{
    pset.resize (size);
    std::iota (pset.begin(), pset.end(), 0); // or rep(i, 0, size - 1) pset[i] = i;
}

int findSet (int i)
{ return (pset[i] == i) ? i : (pset[i] = findSet (pset[i])); }

bool sameSet (int i, int j)
{ return findSet (i) == findSet (j); }

void unionSet (int i, int j)
{ pset[findSet (i)] = findSet (j); }