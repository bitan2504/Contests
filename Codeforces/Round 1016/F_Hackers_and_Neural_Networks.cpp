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
        int m, n;
        cin >> n >> m;
        vstr a(n);
        read(a, 0, n);
        vector<vstr> b(m, vstr(n));
        for (int i = 0; i < m; i++)
            read(b[i], 0, n);

        vint fq(m);
        vint ff(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j] == b[i][j])
                    fq[i]++, ff[j]++;
            }
        }

        if (*min_element(all(ff)) == 0) {
            cout << -1 << endl;
            continue;
        }

        int cnt = 3 * n - 2 * (*max_element(all(fq)));
        cout << cnt << endl;
    }
    return 0;
}