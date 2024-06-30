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

int n, m, ta, tb, k, a[N], b[N], res = 0;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> ta >> tb >> k;
    frr (i, 1, n) cin >> a[i];
    frr (i, 1, m) cin >> b[i];
    if (k > min(n, m)) {
        cout << "-1";
        return 0;
    }
    frr (i, 1, min(k + 1, n)) {
        int l = 1, r = m, pos;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (b[mid] >= a[i] + ta) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (pos + (k - (i - 1)) > m) {
            cout << "-1";
            return 0;
        } else res = max(res, b[pos + (k - (i - 1))] + tb);
    }
    cout << res;
}