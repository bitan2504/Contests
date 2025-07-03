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

#define INF             (int)(1e18)
#define MOD             (int)(1e9 + 7)
#define endl            '\n'
#define mp              make_pair
#define pb              push_back
#define eb              emplace_back
#define lb              lower_bound
#define ub              upper_bound
#define ff              first
#define ss              second
#define sz(x)           (int)(x).size()
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define acc             accumulate
#define maxe            max_element
#define mine            min_element
#define popcount        __builtin_popcountll
#define clz             __builtin_clzll
#define ctz             __builtin_ctzll
#define rep(i, x, y)    for (int i = x; i < y; i++)
#define per(i, x, y)    for (int i = x; i >= y; i--)

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef pair<int, int> pii;

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &it : v) cin >> it; return is; }
template<int W = 64> inline string itob(size_t x) { return bitset<W>(x).to_string(); }

void solve(int tt) {
    debug(tt);
    int n; cin >> n;
    vvi adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    int cnt = 0;
    for (auto &i: adj) cnt += (i.size() == 1);
    cout << (cnt == 2 ? 2 * n - 1 : n + 1) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _ = 1;
    cin >> _;
    for (int tt = 1; tt <= _; tt++) solve(tt);
    return 0;
}