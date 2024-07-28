/*
 *  @date: 26 . 07 . 2024
 *  @tienle0103
 *  @__
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define int            long long
#define fi             first
#define se             second
#define pb             push_back
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
cs int mod = 1e9 + 7;

int t, pre[N];
mii cnt;
str s;

void solve() {
    int res=  0, n = s.size();
    s = " " + s; cnt.clear();
        frr (i,1 ,n ) pre[i] = pre[i - 1] + (s[i] == '1') - (s[i] == '0');
        frr (i, 1, n) {
                cnt[pre[i - 1]] += i;
            (res += (n -i + 1) * cnt[pre[i]]) %= mod;
        }
        cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >>t;
    while (t--) {
        cin >> s;
        solve();
    }
}