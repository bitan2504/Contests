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
        if (k < n - 1) {
            cout << -1 << endl;
            continue;
        }
        int d = k - (n - 1);
        int g = d + 1;
        cout << g << " " << (2LL * g) << " ";
        int c = 1e9, lst = 2LL * g;
        for (int i = 2; i < n; i++) {
            while (gcd(c, lst) > 1) c--;
            cout << c << " ";
            lst = c--;
        }
        cout << endl;
    }
    return 0;
}