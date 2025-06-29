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

#define N (int)(1e7 + 10)

vector<int> sieve(long long n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i < n; i++) {
        if (is_prime[i]) primes.pb(i);
    }
    return primes;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _ = 1;
    // cin >> _;
    for (int tt = 1; tt <= _; tt++) {
        int l, r; cin >> l >> r;
        auto primes = sieve(N);
        vector<int> vis(r - l);
        int cnt = 0;
        for (int &i: primes) {
            for (int p = (l / i + 1) * i; p <= r; p += i) {
                if (vis[r - p]) continue;
                vis[r - p] = 1;
                int x = p;
                while (x % i == 0) x /= i;
                cnt += (x == 1);
            }
        }
        for (auto &i: vis) cnt += !i;

        cout << 1 + cnt << endl;
    }
    return 0;
}