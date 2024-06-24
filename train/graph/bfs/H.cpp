/*
    @date: 23 . 06 . 2024
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

cs int N   = 1e3 + 5;
cs int oo  = 1e18;

int dx[] = {-2, 2, -2, 2};
int dy[] = {-2, -2, 2, 2};
int x, y, tx, ty, dist[N][N];
queue<ii> q;

void bfs(int x, int y) {
    frr (i, 1, 8) frr (j, 1, 8) dist[i][j] = -1;
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        fr (i, 0, 4) {
            int x = u.fi + dx[i];
            int y = u.se + dy[i];
            if (x < 1 || x > 8) continue;
            if (y < 1 || y > 8) continue;
            if (dist[x][y] == -1) dist[x][y] = dist[u.fi][u.se] + 1, q.push({x, y});
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> y >> x >> ty >> tx;
    bfs(x, y);
    cout << dist[tx][ty];
}