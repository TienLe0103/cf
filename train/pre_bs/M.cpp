/*
    @date: 24 . 06 . 2024
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

int n, q, a[N], pre[N];

int solve(int u, int v) {
    int l = u, r = v, res = oo;
    while (l <= r) {
        int mid = (l + r) / 2, 
            sl = pre[mid] - pre[u - 1], 
            sr = pre[v] - pre[mid];
        res = min(res, abs(sl - sr));
        if (sl < sr) l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    frr (i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    while (q--) {
        int u, v; cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}
