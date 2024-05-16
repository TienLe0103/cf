/*
    @date: 14 / 05 / 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long      int;
typedef double         db;
typedef string         str;
typedef vector<int>    vi;
typedef greater<int>   gi;
typedef map<int, int>  mii;
typedef pair<int, int> ii;

#define fi             first
#define se             second
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define fr(x, l, r)    for (int x = l; x < r; x++)
#define frr(x, l, r)   for (int x = l; x <= r; x++)
#define frd(x, l, r)   for (int x = l; x >= r; x--)
#define cs             const

cs int mxn = 1e6 +5;
cs int N   = 1e3 + 5;
cs int oo  = 0x7fffffff;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, dist[mxn];
vector<ii> a[mxn];
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijk(int s) {
    frr (i, 1, n) dist[i] = 1e18;
    dist[s] = 0;
    pq.push(ii(dist[s], s));
    while (!pq.empty()) {
        int c = pq.top().fi;
        int u = pq.top().se;
        if (c > dist[u]) continue;
        // cout << u << ' ' << dist[u] << '\n';
        pq.pop();
        for (auto x : a[u]) {
            int v = x.fi;
            int w = x.se;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[u], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    dijk(1);
    cout << ((dist[n] != 1e18) ? dist[n] : -1);
}