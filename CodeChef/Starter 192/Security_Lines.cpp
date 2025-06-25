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

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef pair<int, int> pii;

#define endl        '\n'
#define pb          push_back
#define eb          emplace_back
#define lb          lower_bound
#define ub          upper_bound
#define ff          first
#define ss          second
#define all(x)      (x).begin, (x).end
#define rall(x)     (x).rbegin, (x).rend
#define acc         accumulate
#define maxe        max_element
#define mine        min_element

inline int popcnt(int x) { return __builtin_popcountll(x); }
inline int clz(int x) { return __builtin_clzll(x); }

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &it : v) cin >> it; return is; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function        
        int n; cin >> n;
        vi a(n); cin >> a;
        int ans = a[0];
        for (int i = 1; i < n; i++) {
            int q = 1 + max(0LL, a[i] - i + 1);
            ans = min(ans, q + i - 1);
        }
        cout << ans << endl;
    }
    return 0;
}