/*
    @date: 15 . 06 . 2024
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

int n, a[N], cnt[N], res = 0;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    frr (i, 1, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    res += cnt[4];
    res += min(cnt[1], cnt[3]);
    cnt[3] -= res - cnt[4];
    cnt[1] -= res - cnt[4];
    if (cnt[3] != 0) {
        res += cnt[3];
        if (cnt[2] % 2 == 0) res += cnt[2] / 2;
        else {
            int s = (2 * cnt[2] + cnt[1]);
            if (s % 4 == 0) res += s / 4;
            else res += s / 4 + 1;
        }
    }
    cout << res;
}