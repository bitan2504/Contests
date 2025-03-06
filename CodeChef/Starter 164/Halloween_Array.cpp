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
    ll n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string ans = "NO";

    sort(begin(a),end(a));
    map<int, int> mpp;
    for (auto i : a) {
        mpp[i]++;
        if (mpp[i] > 2) {
            if (0 >= l && 0 <= r) ans = "YES";
            cout << ans << endl;
            return ;
        }
    }
    ll p = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            p *= (a[i] ^ a[j]);
            if (p > r || p == 0) break;
        }
        if (p > r || p == 0) break;
    }
    if (p >= l && p <= r) ans = "YES";
    cout << ans << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}