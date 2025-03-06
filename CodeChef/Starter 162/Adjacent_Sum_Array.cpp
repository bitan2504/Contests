/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Main solve function
void solve() {
    ll n; cin >> n;
    vector<ll> b(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    sort(b.begin(), b.end());
    vector<ll> a(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) a[i] = b[i - 1] - a[i - 1];
    for (auto i : a) cout << i << " ";
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}