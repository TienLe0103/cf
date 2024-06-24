/*
    @date: 13 . 06 . 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

#define int            long long
#define fi             first
#define se             second
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

int n, res = 0, c = 0, l = 0, a[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    fr (i, 0, n) {
        cin >> a[i];
        if (a[i] % 2 == 0) c++;
        else l++;
    }
    cout << ((l % 2 == 0) ? c * (c - 1) / 2 + l * (l - 1) / 2 : c * l);
}