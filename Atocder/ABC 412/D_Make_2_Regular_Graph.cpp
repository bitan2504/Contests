/**
 * code by bitandas
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...)
#endif
#define int long long
using namespace std;
using namespace __gnu_pbds;

#define endl        '\n'
#define pb          push_back
#define eb          emplace_back
#define lb          lower_bound
#define ub          upper_bound
#define ff          first
#define ss          second
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define acc         accumulate
#define maxe        max_element
#define mine        min_element
#define popcount    __builtin_popcountll
#define clz         __builtin_clzll
#define ctz         __builtin_ctzll

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef pair<int, int> pii;

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &it : v) cin >> it; return is; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _ = 1;
    // cin >> _;
    for (int tt = 1; tt <= _; tt++) {
        int n, m; cin >> n >> m;
        vvi adj(n + 1, vi(n + 1));
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u][v] = adj[v][u] = 1;
        }

        int ans = 1e9;
        vi a(n); iota(all(a), 1);
        do {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int u = a[i], v = a[(i + 1) % n];
                cnt += adj[u][v];
            }
            ans = min(ans, m + n - 2LL * cnt);
            
            for (int j = 2; j < n - 3; j++) {
                cnt += adj[a[0]][a[j]] + adj[a[j + 1]][a[n - 1]]
                    - adj[a[j]][a[j + 1]] - adj[a[n - 1]][a[0]];
                ans = min(ans, m + n - 2LL * cnt);
                cnt -= adj[a[0]][a[j]] + adj[a[j + 1]][a[n - 1]]
                    - adj[a[j]][a[j + 1]] - adj[a[n - 1]][a[0]];
            }
            debug(a, cnt);
        } while (next_permutation(all(a)));

        cout << ans << endl;
    }
    return 0;
}