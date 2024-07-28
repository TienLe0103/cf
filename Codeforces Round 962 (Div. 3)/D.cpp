/*
 *  @date: 26 . 07 . 2024
 *  @tienle0103
 *  @__Fun
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

int t,n,x;

void solve() {
    int res = 0;
    frr (i, 1, n) 
        frr (j, 1, n) {
            if (i * j > n) break;
            res += max(0LL , min((n - i * j) / (i + j) , x - i - j));
        }
    cout << res<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >>t;
    while (t--) {
        cin >>n>> x;
        solve();
    }
}