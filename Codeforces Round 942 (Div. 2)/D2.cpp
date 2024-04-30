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

in gcd(in a, in b) {
    while (b != 0) {
        in tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

bool check(in x, in y) {
    return gcd(x, y) == 1;
}

in find(in a, in b, in c, in d) {
    return min(a / b - 1, c / d - b);
}

in solve(in n, in m) {
    in res=  0;
    frr (i, 1, sqrt(n)) 
        frr (j, 1, find(n, i, m, j)) 
            if (check(i, j)) {
                in s = i + j; 
                res += min(n / s / i, m / s / j); 
            }
    return res;
}

void phnm() {
    in n, m; cin >> n >> m;
    cout << solve(n, m) << '\n'; 
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    in t; cin >> t;
    while (t--) {
        phnm();
    }
}   