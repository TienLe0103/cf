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

int n, p, q, r, a[N], pre[N], res = 0;

int check(int l, int r, int x) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (pre[mid - 1] == x) return mid;
        else if (pre[mid - 1] > x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> p >> q >> r;
    frr (i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    frr (i, 1, n) {
        int z = check(1, i, pre[i] - r);
        if (z != -1) {
            int y = check(1, z - 1, pre[z - 1] - q);
            if (y != -1) {
                int x = check(1, y - 1, pre[y - 1] - p);
                if (x != -1) res++;
            }
        }
    }
    cout << res;
}