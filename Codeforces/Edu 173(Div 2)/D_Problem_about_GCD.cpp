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
    ll l, r, g; cin >> l >> r >> g;
    ll a = (l + g - 1)/g, b = r / g;
    a *= g, b *= g;
    ll an = -1, bn = -1;
    // cerr << a << " " << b << endl;
    for (int i = 0; i <= (b - a)/g; i++) {
        for (int j = 0; j <= i; j++) {
            // cerr << i << " " << j << " " << a + j * g << " " << b - (i - j) * g << endl;
            // cerr << __gcd(a + j * g, b - (i - j) * g) << endl;
            if (__gcd(a + j * g, b - (i - j) * g) == g) {
                an = a + j * g;
                bn = b - (i - j) * g;
                break;
            }
        }
        if (an != -1) break;
    }
    cout << an << " " << bn << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}