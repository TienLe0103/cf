/*
    @date: 21 . 05 . 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

#define int            long long
#define fi             first
#define se             second
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define fr(x, l, r)    for (int x = l; x < r; x++)
#define frr(x, l, r)   for (int x = l; x <= r; x++)
#define frd(x, l, r)   for (int x = l; x >= r; x--)
#define cs             const

typedef double         db;
typedef string         str;
typedef vector<int>    vi;
typedef greater<int>   gi;
typedef map<int, int>  mii;
typedef pair<int, int> ii;

cs int mxn = 1e6 +5;
cs int N   = 1e3 + 5;
cs int oo  = 0x7fffffff;

int q;

void solve() {
    int n; cin >> n;
    mii cnt;
    while (n--) {
        int x; cin >> x;
        cnt[x]++;
    }
    ii res = {0, 0};
    for (auto &[i, j] : cnt) {
        if (j >= 4) res = {i, i};
        else if (j >= 2) res = {i, res.fi};
    }
    cout << ((!res.se) ? -1 : res.fi * res.se) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> q;
    while (q--) {   
        solve();
    }
}