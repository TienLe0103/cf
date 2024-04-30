/*
    @date: 30 / 04 / 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#define         in                  long long
#define         db                  double
#define         str                 string
#define         vi                  vector<in>
#define         gi                  greater<in>
#define         mii                 map<in, in>
#define         pii                 pair<in, in>
#define         fi                  first
#define         se                  second
#define         all(x)              x.begin(), x.end()
#define         rall(x)             x.rbegin(), x.rend()
#define         fr(x, l, r)         for (in x = l; x < r; x++)
#define         frr(x, l, r)        for (in x = l; x <= r; x++)
#define         frd(x, l, r)        for (in x = l; x >= r; x--)
#define         cs                  const

cs in mxn = 1e6 +5;
cs in oo = 0x7fffffff;
cs in mod = 14062008;

in t;
in n, k;
in a[mxn];

bool check(in m) {
    in res = 0;
    fr (i, 0, n) 
        if (a[i] < m)
            res += (m - a[i]);
    return res <= k;
}

in search(in l, in r) {
    in res = 0;
    while (l <= r) {
        in m = (l + r) / 2;
        if (check(m)) l = m + 1, res = m;
        else r = m - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        fr (i, 0, n) cin >> a[i];
        in l = 1, r = 2e12;
        in res = search(l, r);
        in phnm = 0;
        fr (i, 0, n) {
            if (a[i] > res) phnm++;
            else k -= res - a[i];
        }
        cout << res * n - (n - 1) + phnm + k << '\n';
    }
}
