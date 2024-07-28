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

cs int N   = 1e3 + 5;
cs int oo  = 1e18;

int m, n, d, k;
char a[N][N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> m >> n >> d >> k;
    frr (i, 1, m) frr (j, 1, n) cin >> a[i][j];
    
}