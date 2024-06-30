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

int n, l, cnt[mxn], res = 0;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> l;
    int a[n]; for (int &x : a) cin >> x;
    int b[n]; for (int &x : b) cin >> x;
    int c[n]; for (int &x : c) cin >> x;
    int d[n]; for (int &x : d) cin >> x;
    fr (i, 0, n) 
        fr (j, 0, n)
            cnt[a[i] + b[j]]++;
    frr (i, 0, n)
        frr (j, 0, n) 
            if (l - c[i] - d[j] >= 0)
                res += cnt[l - c[i] - d[j]];
    cout << res;
}   