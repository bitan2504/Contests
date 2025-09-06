/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...)
#endif

#define int             long long
#define INF             1000000000000000000LL
#define MOD             1000000007LL
#define endl            '\n'
#define sz(x)           (int)(x).size()
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define eb              emplace_back
#define pb              push_back
#define get(a, i)       get<i> (a)
#define ff              first
#define ss              second

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using vstr = vector<string>;
template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &it : v) cin >> it; return is; }
template<class T, class U> inline bool chmin(T &a, U b) { if (b < a) { a = b; return true; } return false; }
template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true; } return false; }

void solve(int tt) {
    debug(tt);
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    for (int i = l; i < n - r; i++) cout << s[i];
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _ = 1;
    // cin >> _;
    for (int tt = 1; tt <= _; tt++) solve(tt);
    return 0;
}