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
        vvint adj(n + 1);
        string s;
        int e = 1;
        for (int u = 2, v; u <= n; u++) {
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if (adj[v].size() % 2)
                e--;
            else
                e++;
            if (e)
                s += "0";
            else
                s += "1";
        }
        cout << s << endl;
        if (n % 2) {
            continue;
        }

        vint a(n + 1);
        a[1] = 1;
        int cur = 2;
        auto f = [&](auto &&self, int u, int p) -> bool {
            if ((adj[u].size() - 1) % 2)
                return 0;
            for (int v : adj[u]) {
                if (v == p)
                    continue;
                a[v] = cur++;
            }
            for (int v : adj[u]) {
                if (v == p)
                    continue;
                if (!self(self, v, u))
                    return 0;
            }
            return 1;
        };

        if (!f(f, 1, 0)) {
            continue;
        }

        for (int i = 1; i < n + 1; i++) {
            cout << (a[i] + 1) / 2 << " ";
        }
        cout << endl;
    }
    return 0;
}