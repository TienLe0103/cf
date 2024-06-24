/*
    @date: 16 . 06 . 2024
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

cs int N   = 1e6 + 5;
cs int oo  = 1e18;

int t, n, k;
int a[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        frr(i, 1, n) a[i] = i; 
        if (k % 2 != 0) {
            cout << "No\n";
            continue;
        }
        int c = 2 * (n - 1);
        bool possible = true;
        frr(i, 1, n / 2) {
            if (k >= c) {
                k -= c;
                swap(a[i], a[n - i + 1]);
            } else {
                int cnt = 0;
                frr(j, i + 1, n) {
                    cnt += 2;
                    if (k == cnt) {
                        k -= cnt;
                        swap(a[i], a[j]);
                        break;
                    }
                }
                possible = (k == 0);
                break;
            }
            c -= 4;
        }
        if (k != 0) possible = false;
        if (possible) {
            cout << "Yes\n";
            frr(i, 1, n) cout << a[i] << ' ';
            cout << '\n';
        } else {
            cout << "No\n";
        }
    }
}