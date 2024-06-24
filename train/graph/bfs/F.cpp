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

int n, k;
queue<int> q;
vi meet[N], res;
bool vst[N];

void bfs(int start) {
    vst[start] = true;
    res.push_back(start);
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : meet[u]) 
            if (!vst[v]) vst[v] = true, q.push(v), res.push_back(v);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    frr (i, 1, n) {
        int t; cin >> t;
        while (t--) {
            int x; cin >> x; 
            meet[i].push_back(x);
        }
    }
    bfs(k);
    sort(all(res));
    cout << res.size() << '\n';
    for (int x : res) cout << x << ' ';
}   