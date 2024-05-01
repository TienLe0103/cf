/*
    @date: 01 / 05 / 2024
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

#define         in                  long long
#define         db                  double
#define         str                 string
#define         vi                  vector<in>
#define         gi                  greater<in>
#define         mii                 map<in, in>
#define         pii                 pair<in, in>
#define         fi                  first
#define         se                  second
#define         all(x)              x.begin(), x.end()
#define         rall(x)             x.rbegin(), x.rend()
#define         fr(x, l, r)         for (in x = l; x < r; x++)
#define         frr(x, l, r)        for (in x = l; x <= r; x++)
#define         frd(x, l, r)        for (in x = l; x >= r; x--)
#define         cs                  const

cs in mxn = 1e3 +5;
cs in oo = 0x7fffffff;

in dx[] = {1, 0, -1, 0};
in dy[] = {0, 1, 0, -1};
in n, m;
char a[mxn][mxn];
in dist[mxn][mxn];
queue<pii> q;
pii start, finish;

void BFS(pii start) {
    frr (i, 1, n) 
        frr (j, 1, m)   
            dist[i][j] = 1e9;
    dist[start.fi][start.se] = 0;
    q.push(start);
    while (!q.empty()) {
        in u = q.front().fi;
        in v = q.front().se;
        q.pop();
        // cout << u << ' ' << v << ' ' << dist[u][v] << '\n';
        fr (i, 0, 4) {
            in x = u + dx[i];
            in y = v + dy[i];
            if (x > 0 && x <= n && y > 0 && y <= m &&
                a[x][y] != '*' && dist[x][y] > dist[u][v] + 1) {
                    dist[x][y] = dist[u][v] + 1;
                    q.push(pii(x, y));
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    frr (i, 1, n) 
        frr (j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'B')
                start = pii(i, j);
            else if (a[i][j] == 'C')
                finish = pii(i, j);
        }
    // cout << start.fi << ' ' << start.se << '\n';
    // cout << finish.fi << ' ' << finish.se;
    BFS(start);
    // frr (i, 1, n) {
    //     frr (j, 1, m) {
    //         if (dist[i][j] == 1e9)
    //             cout << "-1" << ' ';
    //         else    
    //             cout << dist[i][j] << ' ';
    //     }
    // }
    if (dist[finish.fi][finish.se] == 1e9)
        cout << "-1";
    else    
        cout << dist[finish.fi][finish.se];
}