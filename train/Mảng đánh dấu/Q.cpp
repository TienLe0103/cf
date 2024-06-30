/*
    @date: 21 . 05 . 2024
    @tienle0103
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define frr(i, l, r) for (int i = l; i <= r; i++)

const int d = 3e5;
const int N = 1e6 + 5;

int n, k, a[N], res = 0, cnt[N]; 

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    frr (i, 1, n) cin >> a[i];
    frr (i, 1, n) {
        frr (j, i + 1, n) res += cnt[k - a[i] - a[j] + d];
        cnt[a[i] + d]++;
    }
    cout << res;
}