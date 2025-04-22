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
        s.insert(s.begin(), '0');
        int ans = n;
        for (int i = 1; i <= n; i++) {
            if (s[i] != s[i - 1]) ans++;
        }
        map<pair<char, char>, int> st;
        for (int i = 0; i < n; i++) {
            st[{s[i], s[i + 1]}]++;
        }
        // cerr << s << endl;
        int cnt = 0;
        if (st[{'0', '1'}] && st[{'1', '0'}]) cnt = 1;
        if (st[{'0', '1'}] >= 2 || st[{'1', '0'}] >= 2) cnt = 2;
        // debug(ans, cnt);
        // debug(st);
        cout << ans - cnt << endl;
    }
    return 0;
}