/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

// Main solve function
void solve() {
    int x, y; cin >> x >> y;
    if (x == y) {
        cout << x + y << endl;
        return ;
    }
    if (x > y) swap(x, y);
    ll ans = 2 * x + 1 + (y - x - 1) * 2;
    cout << ans << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}