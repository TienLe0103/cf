/*
    @date: 16 / 04 / 2024
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

#pragma GCC optimize("03,unroll-loops")
#pragma GCC target ("avx2")

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
#define         s(a, n, i)          sort(a + i, a + n + i)
#define         sg(a, n)            sort(a, a + n, greater<in>())
#define         fr(x, l, r)         for (in x = (l); x < (r); ++x)
#define         frd(x, l, r)        for (in x = (l) - 1; x > (r) - 1; --x)
#define         frr(x, l, r)        fr (x, (l), (r) + 1)
#define         frrd(x, l, r)       frd(x, (l) + 1, (r))
#define         cs                  const

cs in mxn = 1e6 +5;
cs in o = -0x7fffffff - 1;
cs in oo = 0x7fffffff;
cs in mod = 14062008;

using namespace std;

// *...SETUP...* //
void IO(const str &name) {
    freopen((name + ".inp").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

template <class T> inline bool minn(T& a, const T& b) { return (a > b) ? a = b, true : false; }
template <class T> inline bool maxx(T& a, const T& b) { return (a < b) ? a = b, true : false; }

// *...VAR-FUNC...* //
in t;
in pre[mxn];

void bp() {
    frr (i, 1, 1e5)
        pre[i] = pre[i - 1] + i * i;
}


// *...Main...* //
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    bp();
    cin >> t;
    while (t--) {
        in n; cin >> n;
        cout << pre[n] << '\n';
    }
}