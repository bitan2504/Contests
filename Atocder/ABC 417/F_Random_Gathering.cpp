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

template<int Mod>
struct Mint {
    int val;
    Mint(int _v = 0) : val((_v % Mod + Mod) % Mod) {}
    Mint& operator+=(const Mint& o) { if ((val += o.val) >= Mod) val -= Mod; return *this; }
    Mint& operator-=(const Mint& o) { if ((val -= o.val) < 0) val += Mod; return *this; }
    Mint& operator*=(const Mint& o) { val = ((long long)val * o.val % Mod); return *this; }
    Mint pow(int e) const { Mint r = 1, a = *this; while (e) { if (e & 1) r *= a; a *= a; e >>= 1; } return r; }
    Mint inv() const { return pow(Mod - 2); }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.val; }
};
typedef Mint<998244353> mint;

#define MAXN 200000

array<int, 4 * MAXN> tree;
array<int, 4 * MAXN> lazy;
array<signed, 4 * MAXN> sizes;
void calc(int v) {
    tree[v] = mint(tree[2 * v + 1] + tree[2 * v + 2]).val;
}

void prop(int v) {
    if (lazy[v] == INF) return ;
    tree[2 * v + 1] = mint(1LL * lazy[v] * sizes[2 * v + 1]).val;
    lazy[2 * v + 1] = lazy[v];
    tree[2 * v + 2] = mint(1LL * lazy[v] * sizes[2 * v + 2]).val;
    lazy[2 * v + 2] = lazy[v];  
    lazy[v] = INF;
}

// void build(int v, int l, int r) {
//     if (l == r) tree[v] = 0, lazy[v] = 0;
//     else {
//         int m = (l + r) / 2;
//         build(2 * v + 1, l, m);
//         build(2 * v + 2, m + 1, r);
//         calc(v);
//         lazy[v] = 0;
//     }
// }

void build(int v, int l, int r, const vector<int> &a) {
    if (l == r) tree[v] = a[l], lazy[v] = INF, sizes[v] = 1;
    else {
        int m = (l + r) / 2;
        build(2 * v + 1, l, m, a);
        build(2 * v + 2, m + 1, r, a);
        calc(v);
        lazy[v] = INF;
        sizes[v] = sizes[2 * v + 1] + sizes[2 * v + 2];
    }
}

void add(int v, int l, int r, int ql, int qr, int x) {
    if (ql > qr) return ;
    if (l < r) prop(v);
    // debug(l, r, tree[v], x);
    if (l == ql && r == qr) {
        lazy[v] = x;
        tree[v] = mint(1LL * x * sizes[v]).val;
    }
    else {
        int m = (l + r) / 2;
        add(2 * v + 1, l, m, ql, min(m, qr), x);
        add(2 * v + 2, m + 1, r, max(m + 1, ql), qr, x);
        calc(v);
    }
    debug(l, r, tree[v]);
}

int query(int v, int l, int r, int ql, int qr) {
    if (ql > qr) return 0;
    debug(l, r, tree[v]);
    if (l < r) prop(v);
    if (l == ql && r == qr) return tree[v];
    int m = (l + r) / 2;
    return mint(
        query(2 * v + 1, l, m, ql, min(m, qr)) 
        + query(2 * v + 2, m + 1, r, max(ql, m + 1), qr)
    ).val;
}


void solve(int tt) {
    debug(tt);
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    build(1, 0, n - 1, a);

    while (m--) {
        int l, r; cin >> l >> r;
        l--, r--;
        
        mint p = query(1, 0, n - 1, l, r);
        p /= mint(r - l + 1);
        add(1, 0, n - 1, l, r, p.val);
        debug(m);
    }

    for (int i = 0; i < n; i++) cout << query(1, 0, n - 1, i, i) << " ";
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