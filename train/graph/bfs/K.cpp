/*
    @date: 11 / 05 / 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

typedef         long long           ll;
typedef         double              db;
typedef         string              str;
typedef         vector<int>         vi;
typedef         greater<int>        gi;
typedef         map<int, int>       mii;
typedef         pair<int, int>      ii;

#define         fi                  first
#define         se                  second
#define         all(x)              x.begin(), x.end()
#define         rall(x)             x.rbegin(), x.rend()
#define         fr(x, l, r)         for (int x = l; x < r; x++)
#define         frr(x, l, r)        for (int x = l; x <= r; x++)
#define         frd(x, l, r)        for (int x = l; x >= r; x--)
#define         cs                  const

cs int mxn = 1e6 +5;
cs int N = 1e3 + 5;
cs int oo = 0x7fffffff;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, k, res = 0;
vi ssc[mxn];
bool vis[mxn];

void dfs(int u) {
    vis[u] = true;
    for (auto v : ssc[u]) 
        if (!vis[v]) 
            dfs(v);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        if (c >= k) {
            ssc[u].push_back(v);
            ssc[v].push_back(u);
        }
    }
    frr (i, 1, n) 
        if (!vis[i]) {
            dfs(i);
            res++;
        }
    cout << res;
}