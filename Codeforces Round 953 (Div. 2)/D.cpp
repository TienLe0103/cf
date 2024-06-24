/*
    @date: 16 . 06 . 2024
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

int t, n, s;
int a[N], pre[N], add[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        frr (i, 1, n) cin >> a[i];
        pre[0] = -oo;
        frr (i, 1, n) {
            pre[i] = max(pre[i - 1], a[i]);
            if (i == 1) pre[i] += s;
        }
        add[n + 1] = -oo;
        fd (i, n, 1) add[i] = max(add[i + 1], a[i]);
        frr (i, 1, n) {
            s += a[i];
            cout << (((a[i] > pre[i - 1] && a[i] >= add[i + 1])) ? 0 : ((s >= add[i + 1]) ? i - 1 : i)) << ' ';
        }
        cout << '\n';
    }
}