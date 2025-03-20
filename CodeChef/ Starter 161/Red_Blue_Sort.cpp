#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; --i)
template <typename T1, typename T2> void swap(T1 &a, T2 &b) { T1 temp = a; a = b; b = temp; }
template <typename T1, typename T2> auto max(T1 a, T2 b) -> decltype(a > b ? a : b) { return (a > b) ? a : b; }
template <typename T1, typename T2> auto min(T1 a, T2 b) -> decltype(a < b ? a : b) { return (a < b) ? a : b; }

// Main solve function
void solve() {
    ll n; cin >> n;
    ll cnt = 0;
    rep(i, 1, n + 1) {
        ll x; cin >> x;
        if (x == i) cnt++;
    }
    ll ans = n - 2;
    if (cnt) ans = n - 1;
    if (cnt == n) ans = n;
    cout << ans << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}