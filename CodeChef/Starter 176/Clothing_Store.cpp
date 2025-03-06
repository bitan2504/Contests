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
    int x, y, z; cin >> x >> y >> z;
    int cnt = 0, ans = 0;
    cnt = z;
    int a, b, c; cin >> a >> b >> c;
    // cerr << cnt << " " << c << endl;
    ans += min(cnt, c);
    cnt = max(0, cnt - c) + y;
    // cerr << cnt << " " << b << endl;
    ans += min(cnt, b);
    cnt = max(0, cnt - b) + x;
    // cerr << cnt << " " << a << endl;
    ans += min(cnt, a);

    cerr << endl;
    cout << ans << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}