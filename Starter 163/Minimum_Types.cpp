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
    ll n, x; cin >> n >> x;
    vector<ll> mpp(n);
    for (int i = 0; i < n; i++) cin >> mpp[i];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mpp[i] *= x;
    }
    sort(mpp.rbegin(), mpp.rend());
    ll cnt = 0;
    for (int i = 0; i < n && x > 0; i++) {
        cnt++;
        x -= mpp[i];
    }
    cout << ((x <= 0) ? cnt : -1) << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}