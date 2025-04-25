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
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (auto &i: a) cin >> i;
        for (auto &i: b) cin >> i;

        vector<int> pre(m, 1e9), suf(m, -1);
        for (int i = 0, j = 0; i < n && j < m; i++) {
            if (a[i] >= b[j]) pre[j++] = i;
        }
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
            if (a[i] >= b[j]) suf[j--] = i;
        }
        
        if (pre.back() != 1e9) {
            cout << 0 << endl;
            continue;
        }

        debug(pre);
        debug(suf);
        int ans = 1e12;
        for (int i = 0; i < m; i++) {
            int l = (i ? pre[i - 1] : -1);
            int r = (i < m - 1 ? suf[i + 1] : n);
            if (l < r) ans = min(ans, b[i]);
        }
        cout << (ans == 1e12 ? -1 : ans) << endl;
    }
    return 0;
}