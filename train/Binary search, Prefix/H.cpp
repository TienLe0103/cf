/*
    @date: 21 . 06 . 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>

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

int n, m, a[N], pre[N];

int solve(int x) {
    int l = 1, r = n, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (pre[mid] >= x) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    frr (i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    cin >> m;
    while (m--) {
        int x; cin >> x;
        cout << solve(x) << ' ';
    }
}   