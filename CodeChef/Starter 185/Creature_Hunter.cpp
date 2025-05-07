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

struct nd {
public: 
    int d, s;

    bool operator<(nd other) {
        return (double)d / s < (double)other.d / other.s;
    }
};

int32_t main() {
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function
        int n, k; cin >> n >> k;
        int m1 = 0, m2 = 0;
        for (int i = 0; i < n; i++) {
            int s, d; cin >> s >> d;
            if (s == 1) m1 = max(m1, d);
            else m2 = max(m2, d);
        }
        int a1, a2, a3;
        a1 = a2 = a3 = 1e18;
        if (m1) a1 = (k + m1 - 1) / m1;
        if (m2) a2 = (k + m2 - 1) / m2, a2 *= 2;
        if (m1 && m2) {
            a3 = k / m2;
            int left = k - a3 * m2;
            a3 *= 2;
            a3 += (left + m1 - 1) / m1;
        }
        cout << min({a1, a2, a3}) << endl;
    }
    return 0;
}