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
        string s, t; cin >> s>> t;
        int i = 0;
        bool flg = 1;
        for (; i < n; i++) {
            if (s[i] != t[i]) {
                flg = 0;
                break;
            }
            if (s[i] == '1') break;
        }

        if (!flg) {
            cout << -1 << endl;
            continue;
        }

        vector<int> ans;
        for (int j = i + 1; j < n; j++) {
            if (s[j] != '1') ans.push_back(j - 1);
        }
        for (int j = n - 1; j > i; j--) {
            if (t[j] == '0') ans.push_back(j - 1);
        }
        cout << ans.size() << endl;
        for (auto i: ans) cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}