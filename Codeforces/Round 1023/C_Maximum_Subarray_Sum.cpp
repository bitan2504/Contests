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
    int _ = tt;
    while (tt--) {
        // Main solve function
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> a(n);
        vector<pair<int, int>> b(n);
        for (auto &i: a) cin >> i;
        auto ans = a;

        int curr = 0, flg = 1, maxi = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (s[r] == '0') {
                b[r].first = curr;
                l = r + 1;
                curr = 0;
                continue;
            }
            curr += a[r];
            while (curr < 0) {
                curr -= a[l++];
            }
            maxi = max(maxi, curr);
            // if (curr > k) {
            //     flg = 0;
            //     break;
            // }
        }
        curr = 0, maxi = 0;
        for (int l = n - 1, r = n - 1; r >= 0; r--) {
            if (s[r] == '0') {
                b[r].second = curr;
                l = r - 1;
                curr = 0;
                continue;
            }
            curr += a[r];
            while (curr < 0) {
                curr -= a[l--];
            }
            maxi = max(maxi, curr);
            // if (curr > k) {
            //     flg = 0;
            //     break;
            // }
        }
        if (!flg) {
            cout << "No" << endl;
            debug(_ - tt);
            continue;
        }

        int ff = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (ff)
                    ans[i] = k - b[i].first - b[i].second;
                else ans[i] = -1e18;
                ff = 0;
            }
        }

        maxi = curr = 0;
        for (int l = 0, r = 0; r < n; r++) {
            curr += ans[r];
            while (curr < 0) {
                curr -= ans[l++];
            }
            maxi = max(maxi, curr);
        }

        // debug(a);
        // debug(ans, maxi, k);
        if (maxi != k) {
            cout << "No" << endl;
            // debug(_ - tt);
            continue;
        }
        cout << "Yes" << endl;
        for (auto i: ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}