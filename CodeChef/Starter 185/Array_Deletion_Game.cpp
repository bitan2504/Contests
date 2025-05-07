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
        vector<int> a(n * 2LL);
        for (auto &i: a) cin >> i;
        multiset<int> q;
        q.insert(max(a[0], a[1]));
        for (int i = 2; i < 2 * n; i += 2) {
            vector<int> b = {a[i], a[i + 1], *q.begin()};
            q.erase(q.begin());
            sort(b.begin(), b.end());
            q.insert(b[1]);
            q.insert(b[2]);
        }
        // debug(q);
        cout << accumulate(q.begin(), q.end(), 0LL) << endl;
    }
    return 0;
}