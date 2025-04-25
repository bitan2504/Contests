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
        int n, x; cin >> n >> x;
        vector<int> a(n);
        iota(a.begin(), a.end(), 0LL);
        for (int i = x; i < n - 1; i++) a[i] = a[i + 1];
        a[n - 1] = min(n - 1, x);
        for (auto i: a) cout << i << " ";
        cout << endl;
    }
    return 0;
}