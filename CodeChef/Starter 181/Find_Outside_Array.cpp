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
        int n;
        cin >> n;
        vint a(n);
        read(a, 0, n);
        sort(all(a));
        int i = 0;
        for (; i < n; i++) {
            if (a[i])
                break;
        }
        if (i == n) {
            cout << -1 << endl;
            continue;
        }

        if (a[0] < 0) {
            cout << a[0] << " " << a[0] << endl;
        } else {
            cout << a[n - 1] << " " << a[n - 1] << endl;
        }
    }
    return 0;
}