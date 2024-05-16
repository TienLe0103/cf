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
int n, k;
queue<int> q;
priority_queue<int, vi, gi> pq;
vector<bool> check(mxn, false);
vi meet[mxn];

void bfs(int s) {
    q.push(s);
    check[s] = true;
    pq.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto x : meet[u]) 
            if (!check[x]) {
                check[x] = true;
                q.push(x);
                pq.push(x);
            }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    frr (i, 1, n) {
        int x; cin >> x;
        while (x--) {
            int w; cin >> w;
            meet[i].push_back(w);
        }
    }
    bfs(k);
    cout << pq.size() << '\n';
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
}