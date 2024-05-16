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
int n, m, k, d;
bool a[N][N], v[N][N];
queue<ii> q;

void bfs(ii s) {
    q.push(s);
    v[s.fi][s.se] = true;
    d--;

    while (!q.empty()) {
        ii u = q.front();
        q.pop();

        fr (i, 0, 4) {
            int x = u.fi + dx[i];
            int y = u.se + dy[i];

            if (x < 1 || x > n) continue;
            if (y < 1 || y > m) continue;
            if (!v[x][y] && a[x][y]) {
                v[x][y] = true;
                q.push(ii(x, y));
                d--;
            }

            if (d == 0) return; 
        } 
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;
    
    int x, y;
    frr (i, 1, n) 
        frr (j, 1, m) {
            cin >> a[i][j];
            if (a[i][j]) {
                d++;
                x = i;
                y = j;
            }
        }
    
    d -= k;
    bfs(ii(x, y));

    frr (i, 1, n) 
        frr (j, 1, m)   
            if (!v[i][j] && a[i][j]) 
                cout << i << ' ' << j << '\n'; 
}