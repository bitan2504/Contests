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

int f(int n, int v, int x, int y) {
    // debug(n, v, x, y);
    if (n == 2) {
        if (x == 1) {
            if (y == 1)
                return v + 1;
            return v + 4;
        }
        if (y == 1)
            return v + 3;
        return v + 2;
    }

    int cnt = 0;
    if (x > (n >> 1)) {
        cnt |= (0b01);
        x -= (n >> 1);
    }
    if (y > (n >> 1)) {
        cnt |= (0b10);
        y -= (n >> 1);
    }

    int m = n * n / 4;
    if (cnt == 0b00)
        return f(n >> 1, v, x, y);
    else if (cnt == 0b11)
        return f(n >> 1, v + m, x, y);
    else if (cnt == 0b01)
        return f(n >> 1, v + 2 * m, x, y);
    return f(n >> 1, v + 3 * m, x, y);
}

void g(int n, int i, int j, int d) {
    // debug(n, i, j, d);
    if (n == 2) {
        if (d == 1) {
            cout << i << " " << j << endl;
        } else if (d == 2) {
            cout << i + 1 << " " << j + 1 << endl;
        } else if (d == 3) {
            cout << i + 1 << " " << j << endl;
        } else {
            cout << i << " " << j + 1 << endl;
        }
        return ;
    } 
    int m = (n * n + 3)/ 4;
    int y = d / m;
    if (d <= m) {
        g(n >> 1, i, j, d);
    } else if (d <= 2 * m) {
        g(n >> 1, i + (n >> 1), j + (n >> 1), d - m);
    } else if (d <= 3 * m) {
        g(n >> 1, i + (n >> 1), j, d - 2 * m);
    } else {
        g(n >> 1, i, j + (n >> 1), d - 3 * m);
    }
}

int32_t main() {
    fast_io();
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function
        int n;
        cin >> n;
        int q;
        cin >> q;
        string s;
        while (q--) {
            cin >> s;
            if (s == "->") {
                int x, y;
                cin >> x >> y;
                cout << f(1LL << n, 0, x, y) << endl;
            } else {
                int d;
                cin >> d;
                g(1LL << n, 1, 1, d);
            }
            // cerr << endl;
        }
    }
    return 0;
}