/*
    @date: 13 / 05 / 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef long long      ll;
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
int n, res = oo;
int a[N][N];
queue<ii> q;
bool vst[N][N];

bool bfs(int l, int r) {
    memset(vst, false, sizeof(vst));
    if (a[1][1] >= l && a[1][1] <= r) 
        q.push({1, 1}),
        vst[1][1] = true;
    while (!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        fr (i, 0, 4) {
            int x = u + dx[i];
            int y = v + dy[i];
            if (x < 1 || x > n) continue;
            if (y < 1 || y > n) continue;
            if (a[x][y] >= l && a[x][y] <= r && !vst[x][y]) {
                vst[x][y] = true;
                q.push({x, y});
            }
        }
    }
    return vst[n][n];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    frr (i, 1, n) frr (j, 1, n) cin >> a[i][j];
    frr (i, 0, 100) {
        int l = i, r = 100;
        while (l <= r) {
            int m = (l + r) / 2;
            if (bfs(i, m)) 
                res = min(res, m - i), 
                r = m - 1;
            else
                l = m + 1;
        }
    }
    cout << res;
}