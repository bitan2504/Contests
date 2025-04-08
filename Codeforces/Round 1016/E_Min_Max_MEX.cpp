/**
 * code by bitandas
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define uint unsigned long long
#define umap unordered_map
#define uset unordered_set
#define heap priority_queue
#define all(x) (x).begin(), (x).end()
#define sz(x) (long long)(x).size()
#define INF (long long)1e9
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#endif

using namespace std;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<bool> vbool;
typedef vector<string> vstr;
typedef pair<int, int> pii;

template <typename T> inline void read(vector<T> &a, int i, int n) {
    while (i < n)
        cin >> a[i++];
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int32_t main() {
    fast_io();
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function
        int n, k;
        cin >> n >> k;
        vint a(n);
        read(a, 0, n);
        int l = 1, r = n, m;
        int ans = 0;

        auto f = [&](int m) -> bool {
            int cnt = 0;
            set<int> st;
            for (int i = 0; i < n; i++) {
                if (st.size() >= m)
                    st.clear(), cnt++;
                if (a[i] >= m)
                    continue;
                st.insert(a[i]);
            }
            if (st.size() >= m)
                st.clear(), cnt++;
            return cnt >= k;
        };

        while (l <= r) {
            m = (l + r) / 2;
            // cerr << m << " ";
            if (f(m)) {
                // cerr << 1 << endl;
                ans = max(ans, m);
                l = m + 1;
            } else {
                // cerr << 0 << endl;
                r = m - 1;
            }
        }
        // cerr << endl;
        cout << ans << endl;
    }
    return 0;
}