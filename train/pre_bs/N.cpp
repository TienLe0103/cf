/*
    @date: 24 . 06 . 2024
    @tienle0103
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

int n, k, a[N], l[N], r[N], res = 0;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    frr (i, 1, n) cin >> a[i];
    l[1] = a[1]; 
    frr (i, 2, n) l[i] = gcd(l[i - 1], a[i]);
    r[n] = a[n];
    fd (i, n - 1, 1) r[i] = gcd(r[i + 1], a[i]);
    frr (i, 1, n - k + 1) res = max(res, gcd(l[i - 1], r[i + k]));
    cout << res;
}