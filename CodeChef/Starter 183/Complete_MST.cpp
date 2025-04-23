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
        int z = n * (n - 1) / 2 - m;

        int l = 1, r = n;
        int mxi = 0, mni = max(0LL, n - z - 2);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid * (mid - 1) / 2 >= z) {
                mxi = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        mxi = n - mxi;
        // debug(mni, mxi);
        cout << (mxi * (mxi + 1) / 2 - mni * (mni + 1) / 2) << endl;
    }
    return 0;
}