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

#define         int                 long long
#define         db                  double
#define         str                 string
#define         vi                  vector<int>
#define         gi                  greater<int>
#define         mii                 map<int, int>
#define         ii                  pair<int, int>
#define         fi                  first
#define         se                  second
#define         all(x)              x.begin(), x.end()
#define         rall(x)             x.rbegin(), x.rend()
#define         fr(x, l, r)         for (int x = l; x < r; x++)
#define         frr(x, l, r)        for (int x = l; x <= r; x++)
#define         frd(x, l, r)        for (int x = l; x >= r; x--)
#define         cs                  const

cs int mxn = 1e6 +5;
cs int oo = 0x7fffffff;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, s, t;
vi sex[mxn];
int dist[mxn];
queue<int> q;

void bfs(int start) {
    frr (i, 1, n) dist[i] = -1;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        for (int x : sex[pos]) {
            if (dist[x] == -1) {
                dist[x] = dist[pos] + 1;
                q.push(x);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> s >> t;

    fr (i, 0, m) {
        int x, y; cin >> x >> y;
        sex[x].push_back(y);
        sex[y].push_back(x);
    }

    bfs(s);

    cout << dist[t];
}