/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
template <typename T1, typename T2> void swap(T1 &a, T2 &b) { T1 temp = a; a = b; b = temp; }
template <typename T1, typename T2> auto max(T1 a, T2 b) -> decltype(a > b ? a : b) { return (a > b) ? a : b; }
template <typename T1, typename T2> auto min(T1 a, T2 b) -> decltype(a < b ? a : b) { return (a < b) ? a : b; }
template <typename T1, typename T2> auto lower_bound_sorted(vector<T1> &a, T2 target, int l, int r) { while (l <= r) { int m = l + (r - l)/2; if (a[m] < target) l = m + 1; else r = m - 1; } return l + a.begin(); } 

typedef class Modular {
public:
    int value;
    const static int MOD = 998244353;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}
    Modular& operator+=(int const& b) {value += b; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(int const& b) {value -= b; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(int const& b) {value = (long long)value * b % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
      Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
      return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
} mint;

// Main solve function
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n), c(n), d(n);
    mint p = 1;
    for (int i = 0; i < n; i++) cin >> a[i], c[i] = a[i];
    for (int i = 0; i < n; i++) cin >> b[i], d[i] = b[i];
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++) p *= min(c[i], d[i]);
    cout << p << " ";

    while (q--) {
        int o, u, v; cin >> o >> u;
        u--;
        if (o == 1) {
            v = lower_bound_sorted(c, a[u] + 1, 0, n - 1) - c.begin();
            v--;
            if (d[v] > c[v]) p = (p / c[v]) * (c[v] + 1);
            a[u]++, c[v]++;
        } else {
            v = lower_bound_sorted(d, b[u] + 1, 0, n - 1) - d.begin();
            v--;
            if (c[v] > d[v]) p = (p / d[v]) * (d[v] + 1);
            b[u]++, d[v]++;
        }
        cout << p << " ";
    }
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}