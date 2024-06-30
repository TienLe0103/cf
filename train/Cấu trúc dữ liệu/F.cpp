/*
    @date: 16 / 05 / 2024
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

int n, a[mxn], d = 0;
ii cnt[mxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    frr (i, 1, n) {
        cin >> a[i];
        cnt[i] = {a[i], i};
    }
    sort(cnt + 1, cnt + n + 1);
    frr (i, 1, n) {
        if (i == 1 || cnt[i].fi != cnt[i - 1].fi)
            d++;
        a[cnt[i].se] = d;
    }
    frr (i, 1, n)   
        cout << a[i] << ' ';
}