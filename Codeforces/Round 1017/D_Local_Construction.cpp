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
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        deque<int> d;
        for (int i = 0; i < n; i++) {
            if (a[i] != -1)
                q.push({a[i], i});
            else 
                d.push_front(i);
        }
        while (q.size())  {
            auto [i, j] = q.top(); q.pop();
            if (i % 2) {
                d.push_back(j);
            } else {
                d.push_front(j);
            }
        }

        int x = 1;
        while (d.size()) {
            auto i = d.front();
            d.pop_front();
            ans[i] = x++;
        }
        for (auto i: ans) cout << i << " ";
        cout << endl;
        
    }
    return 0;
}