#include <bits/stdc++.h>

#define rep(i, a, b)    for (int i = a; i <= b; ++i)

constexpr int MAX = 1e5 + 1;
constexpr int LGMAX = 18;

std::vector<int> adjList[MAX];
int visited[MAX], depths[MAX];
int parent[MAX][LGMAX];
int depth;
int n; // number of nodes

void dfs (int u)
{
    visited[u] = true;
    depths[u] = ++depth;
    
    for (auto& v : adjList[u])
        if (!visited[v]) {
        
            parent[v][0] = u;
            dfs (v);
        }
    
    --depth;
}


void setup (void)
{
    rep (i, 1, LGMAX - 1)
        rep (j, 1, n) {
        
            int p = parent[j][i - 1];
            if (p)
                parent[j][i] = parent[p][i - 1];
        }
}


int lca (int x, int y)
{
    int diff = depths[x] - depths[y];
    
    if (diff < 0) {
    
        diff *= -1;
        std::swap (x, y);
    }
    
    int i = 0;
    while (diff) {
        
        if (diff & 1)
            x = parent[x][i];
        
        ++i;
        depth >>= 1;
    }
    
    if (x == y)
        return x;
    
    
    for (int i = LGMAX - 1; i >= 0; --i)
        if (parent[x][i] != parent[y][i]) {
        
            x = parent[x][i];
            y = parent[y][i];
        }
        
    return parent[x][0];
}