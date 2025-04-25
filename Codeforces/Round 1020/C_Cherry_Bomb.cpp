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
        vector<int> a(n), b(n);
        for (auto &i: a) cin >> i;
        for (auto &i: b) cin >> i;
        int cnt = 0;
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) cnt++;
            else st.insert(b[i] + a[i]);
        }

        // debug(st);
        if (st.size() > 1) {
            cout << 0 << endl;
            continue;
        }
        if (!st.size()) {
            int mini = *min_element(a.begin(), a.end());
            int maxi = *max_element(a.begin(), a.end());
            cout << k + mini - maxi + 1 << endl;
            // debug(k, mini, maxi);
            continue;
        }

        int mini = *min_element(a.begin(), a.end());
        int maxi = *max_element(a.begin(), a.end());
        // debug(k, mini, maxi);
        if (*st.begin() >= maxi && *st.begin() <= k + mini) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}