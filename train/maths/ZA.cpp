/*
    @date: 25 / 04 / 2024
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

in n, res = 0;

in gcd(in a, in b) {
    while (b != 0) {
        in tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

in lcm(in a, in b) {
    return a * b / gcd(a, b);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    // in x = 0;
    for (in i = 1; i <= n / 2; i ++) {
        res = max(res, lcm(i, n - i));
        // if (res == lcm(i, n - i))
        //     x = i;
    }
    // cout << x << ' ' << n - x << ' ' << res;
    cout << res;
}