/**
 * code by bitandas
 */
#include <bits/stdc++.h>
#define int long long
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

int32_t main() {
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function
        int n, q; cin >> n >> q;
        vector<int> a(n);
        for (auto &i: a) cin >> i;
        a.insert(a.begin(), 0);
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) b[a[i]] = i;

        while (q--) {
            int l, r, x; cin >> l >> r >> x;
            if (b[x] < l || b[x] > r) {
                cout << -1 << " ";
                continue;
            }

            int cnt = 0;
            int g = 0, s = 0;
            int G = 0, S = 0;
            while (l <= r) {
                int m = (l + r) / 2;
                if (a[m] == x) break;
                if (b[x] > m) {
                    l = m + 1;
                    if (a[m] > x) S++;
                    s++;
                } else {
                    r = m - 1;
                    if (a[m] < x) G++;
                    g++;
                }
            }
            cout << (s > x - 1 || g > n - x ? -1 : 2 * max(G, S)) << " ";
        }
        cout << endl;
    }
    return 0;
}