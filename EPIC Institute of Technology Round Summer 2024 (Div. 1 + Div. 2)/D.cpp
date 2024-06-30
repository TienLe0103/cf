/*
    @date: 30 . 06 . 2024
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

cs int INF = 1e9;
cs int N   = 1e6 + 5;
cs int oo  = 1e18;

int t;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        int n, diff = 0; cin >> n;
        vi a(n + 1), b(n + 1), c(n + 1, 0);
        vector<vi> f(n + 1, vi(n + 1, INF));
        frr (i, 1, n) cin >> a[i];
        sort(a.begin() + 1, a.begin() + 1 + n);
        frr (i, 1, n) b[i] = a[i];
        frr (i, 1, n) a[i] = (b[i] != b[i - 1]) ? ++diff : diff;
        frr (i, 1, n) c[a[i]]++;
        f[1][1] = 1;
        frr (i, 2, n) 
            fd (j, n, 0) 
                f[i][j] = INF, f[i][j] = min(j >= 1 ? f[i - 1][j - 1] + 1 : INF, j + c[i] <= n ? f[i - 1][j + c[i]] : INF);
        cout << *min_element(f[n].begin(), f[n].end()) << '\n';
        fill(all(c), 0);
    }
}
