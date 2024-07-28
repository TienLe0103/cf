/*
 *  @date: 26 . 07 . 2024
 *  @tienle0103
 *  @__Bomb
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

int t, n, k, a[N], b[N];

bool check(int x) {
    int s=  0;
    frr (i, 1, n) {
        if ((a[i]- x+ b[i]- 1) / b[i] >= 1) s +=(a[i] - x + b[i] - 1) / b[i];
        if (s  >= k) return 0;
    }
    return 1;
}

int search() {
    int l = 0, r  = 1e9, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;
}

void solve() {
    int add = search();
    int res = 0, s=  0;
    priority_queue<int> q;
    frr (i, 1, n ){
        int  x= (a[i] - add  +b[i] -  1)/ b[i];
        if (x >= 1) {
            (res += a[i] * x) -= ((x-  1) * x / 2 * b[i]);
            a[i] -= x * b[i];
            s +=x;
        }
        if (a[i] > 0) q.push(a[i]);
    }
    while (!q.empty() && k > s) {
        res += q.top();
        q.pop();
        s++;        
    } 
    cout << res << '\n';
}

signed main() {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while  (t--) {
        cin >> n >> k;
        frr (i,  1, n) cin >> a[i];
        frr (i, 1, n) cin >> b[i];
        solve();
    }
}  
