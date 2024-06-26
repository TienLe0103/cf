/*
    @date: 27 . 06 . 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define int            long long
#define fi             first
#define se             second
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define fr(x, l, r)    for (int x = l; x < r; x++)
#define frr(x, l, r)   for (int x = l; x <= r; x++)
#define fd(x, l, r)    for (int x = l; x >= r; x--)
#define cs             const

typedef double         db;
typedef string         str;
typedef vector<int>    vi;
typedef greater<int>   gi;
typedef map<int, int>  mii;
typedef pair<int, int> ii;

cs int N   = 1e6 + 5;
cs int oo  = 1e18;

int n, m, x, res = 0;
vi a[N];
bool vst[N];

void dfs(int u) {
    vst[u] = true;
    for (auto v : a[u]) if (!vst[v]) dfs(v);    
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> x;
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        if (c >= x) 
            a[u].pb(v),
            a[v].pb(u);
    }        
    frr (i, 1, n) if (!vst[i]) dfs(i), res++;
    cout << res;
}
