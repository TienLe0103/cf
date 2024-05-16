/*
    @date: 24 / 04 / 2024
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

in a, b, x, y;

in gcd(in a, in b) {
    while (b != 0) {
        in tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

in solve(in a, in b, in x, in y) {
    in lcm = (x * y) / gcd(x, y);
    return b / x + b / y - b / lcm - (a - 1) / x - (a - 1) / y + (a - 1) / lcm;
}

signed main() {
    cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> a >> b >> x >> y;
    cout << solve(a, b, x, y);
}