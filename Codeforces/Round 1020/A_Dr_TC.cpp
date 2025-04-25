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
        string s; cin >> s;
        int ans = 0;
        for (auto i: s) {
            if (i == '1') ans += (n - 1);
            else ans++;
        }
        cout << ans << endl;

    }
    return 0;
}