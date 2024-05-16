/*
    @date: 11 / 05 / 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef         long long           ll;
typedef         double              db;
typedef         string              str;
typedef         vector<int>         vi;
typedef         greater<int>        gi;
typedef         map<int, int>       mii;
typedef         pair<int, int>      ii;

#define         fi first
#define         se second
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
int n, m; 
int dist[N][N];
char c[N][N];
queue<ii> q;
ii s, e;

void bfs(ii s) {
    frr (i, 1, n) frr (j, 1, m) dist[i][j] = -1;
    dist[s.fi][s.se] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();

        fr (i, 0, 4) {
            int x = u + dx[i];
            int y = v + dy[i];

            if (x < 1 && x > n) continue;
            if (y < 1 && y > m) continue;
            if (c[x][y] == '*') continue;

            if (dist[x][y] == -1) 
                dist[x][y] = dist[u][v] + 1,
                q.push(ii(x, y));
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    
    frr (i, 1, n) 
        frr (j, 1, m) {
            cin >> c[i][j];

            if (c[i][j] == 'B') s = ii(i, j); 
            if (c[i][j] == 'C') e = ii(i, j);
        }
    
    bfs(s);

    cout << dist[e.fi][e.se];
}