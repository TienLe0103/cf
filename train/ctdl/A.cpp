/*
    @date: 14 / 05 / 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef double         db;
typedef string         str;
typedef vector<int>    vi;
typedef greater<int>   gi;
typedef map<int, int>  mii;
typedef pair<int, int> ii;

#define int            long long
#define fi             first
#define se             second
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define fr(x, l, r)    for (int x = l; x < r; x++)
#define frr(x, l, r)   for (int x = l; x <= r; x++)
#define frd(x, l, r)   for (int x = l; x >= r; x--)
#define cs             const

cs int mxn = 1e6 +5;
cs int N   = 1e3 + 5;
cs int oo  = 0x7fffffff;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, q;
mii cnt;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    int a[n]; for (int &x : a) cin >> x, cnt[x]++;
    cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << cnt[x] << '\n';
    }
}