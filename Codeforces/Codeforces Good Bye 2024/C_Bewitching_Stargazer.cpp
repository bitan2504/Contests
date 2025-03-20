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

// Main solve function
void solve() {
    ll n, k; cin >> n >> k;
    auto f = [&](auto&& self, int n, ll& cnt) -> ll {
        if (n < k) return 0;
        ll sum = self(self, n / 2, cnt);
        sum *= 2;
        sum += cnt * (ll((n + 1) / 2));
        cnt *= 2;
        // cerr << n << " " << sum << " " << cnt << endl;
        if (n % 2) sum += (n + 1) / 2, cnt++;
        // cerr << n << " " << sum << " " << cnt << endl;
        return sum;
    };
    ll cnt = 0;
    cout << f(f, n, cnt) << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}