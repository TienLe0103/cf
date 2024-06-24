/*
    @date: 18 . 06 . 2024
    @tienle0103
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>

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

cs int N   = 501;
cs int oo  = 1e18;

int m, n, a[N][N], pre[N][N], cnt[9], res = 0;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> m >> n;
    frr (i, 1, m) frr (j, 1, n) cin >> a[i][j], pre[i][j] = pre[i - 1][j] + a[i][j];
    frr (i, 1, m)   
        frr (j, i, m) {
            memset(cnt, 0, sizeof(cnt));
            cnt[0] = 1;
            int s = 0;
            frr (k, 1, n) {
                s += pre[j][k] - pre[i - 1][k];
                s = (s % 9 + 9) % 9;
                res += cnt[s];
                cnt[s]++;
            }
        }
    cout << res;
}   