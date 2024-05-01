/*
    @date: 01 / 05 / 2024
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

in n, m;
in a[2005][2005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    fr (i, 0, m) {
        in x, y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    frr (i, 1, n) {
        frr (j, 1, n)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}