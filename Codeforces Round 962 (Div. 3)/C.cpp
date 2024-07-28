/*
 *  @date: 26 . 07 . 2024
 *  @tienle0103
 *  @__Sort
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

cs int N = 2e5 + 5;
cs int oo = 1e18;

int t, n, q, k, prea[26][N], preb[26][N];
char a[N], b[N];

void solve() {
    int l, r; 
    cin >> l >> r;
    ii res = {0, 0};
    frr(i, 0, 25) {
        int x = prea[i][r] - prea[i][l - 1];
        int y = preb[i][r] - preb[i][l - 1];
        if (x > y) res.fi += abs(x - y);
        else res.se += abs(x - y);
    }
    cout << res.fi + (res.se - res.fi) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    cin >> t; 
    while (t--) {
        cin >> n >> q;
        frr(i, 1, n) {
            cin >> a[i];
            frr(j, 0, 25) prea[j][i] = prea[j][i - 1] + (a[i] == (char)(j + 'a'));
        }
        frr(i, 1, n) {
            cin >> b[i];
            frr(j, 0, 25) preb[j][i] = preb[j][i - 1] + (b[i] == (char)(j + 'a'));
        }
        while (q--) {
            solve();
        }
    }
}
