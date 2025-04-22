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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(n + 1);
        vector<int> c(n + 1);
        for (int i = 0; i < n; i++) {
            b[i + 1] = b[i];
            b[i + 1] += (a[i] > k ? -1 : 1);
        }
        for (int i = n - 1; i >= 0; i--) {
            c[i] = c[i + 1];
            c[i] += (a[i] > k ? -1 : 1);
        }
        multiset<int> st(b.begin() + 1, b.end() - 1);
        multiset<int> tt(c.begin() + 1, c.end() - 1);

        bool flg = 0;
        for (int i = 0; i < n - 2; i++) {
            st.erase(st.find(b[i + 1]));
            // debug(1, i, b[i + 1]);
            if (b[i + 1] >= 0 && st.lower_bound(b[i + 1]) != st.end()) {
                flg = 1;
                break;
            }
        }
        for (int i = n - 1; i >= 2; i--) {
            tt.erase(tt.find(c[i]));
            if (c[i] >= 0 && tt.lower_bound(c[i]) != tt.end()) {
                // debug(2, i, c[i]);
                flg = 1;
                break;
            }
        }
        // debug(b);
        // debug(c);
        for (int i = 1; i < n; i++) {
            b[i + 1] = max(b[i + 1], b[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            c[i] = max(c[i], c[i + 1]);
        }
        // debug(b);
        // debug(c);
        for (int i = 0; i < n - 2; i++) {
            if (b[i + 1] >= 0 && c[i + 2] >= 0) {
                // debug(i);
                flg = 1;
                break;
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}