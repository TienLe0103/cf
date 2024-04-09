/*
    @date: 09 / 04 / 2024
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

cs in mxn = 3e6 +5;
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
in n, res = 0, ress = 0;
in cnt[mxn];
char k;
str s;

void sang(in x, priority_queue<in, vi, gi>& pq) {
    vector<bool> c(x + 5, true);
    c[0] = c[1] = false;
    for (in i = 2; i * i <= x; ++i)
        if (c[i])
            for (in j = i * i; j <= x; j += i)
                c[j] = false;
    frr (i, 2, x)   
        if (c[i])
            pq.push(i);
}

// *...Main...* //
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    vi a(n); for (in &x : a) cin >> x;
    cin >> s;
    // cout << k << '\n';
    // return 0;
    priority_queue<in, vi, gi> pq; sang(n, pq);
    while (!pq.empty()) {
        if (s[pq.top() - 1] == k) {
            // cout << a[pq.top() - 1] << '\n';
            res = max(res, a[pq.top() - 1]);
            cnt[a[pq.top() - 1]]++;
            // cout << res << '\n';
        } pq.pop();
    }
    cout << cnt[res] << ' ' << res;
}


/*
18
X
1 14 7 2 16 12 11 4 14 2 1 8 4 1 10 20 4 13
   2 3    5     7        11  13        17
   W Y    Z     Z         Y   V         X 

2 3 5 7 11 13 17

*/