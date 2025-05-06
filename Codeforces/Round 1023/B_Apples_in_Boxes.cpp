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
        for (auto &i: a) cin >> i;
        int sum = accumulate(a.begin(), a.end(), 0LL);
        auto mini = min_element(a.begin(), a.end()) - a.begin();
        auto maxi = max_element(a.begin(), a.end()) - a.begin();
        a[maxi]--;
        if (*max_element(a.begin(), a.end()) - a[mini] >= k + 1) {
            cout << "Jerry" << endl;
            continue;
        }
        cout << (sum % 2 ? "Tom" : "Jerry") << endl;
    }
    return 0;
}