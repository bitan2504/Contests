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
        int n; cin >> n;
        vector<int> a(n);
        for (auto &i: a) cin >> i;
        int maxi = max_element(a.begin(), a.end()) - a.begin();
        vector<int> ans(n);
        bool flg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[maxi]) ans[i] = 1;
            else ans[i] = 2, flg = 1;
        }
        if (flg) {
            cout << "Yes" << endl;
            for (int i: ans) cout << i << " ";
            cout << endl;
        } else cout << "No" << endl;
    }
    return 0;
}