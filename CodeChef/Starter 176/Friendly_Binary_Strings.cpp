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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) c2++;
        else if (a[i] == '1') c3++;
        else c1++;
    }
    string ans = "NO";
    if (n % 2) {
        if (c1 % 2 == 0 || c2 % 2 == 0 || c3 % 2 == 0) ans = "YES";
    } else {
        if (c1 % 2 == 0 && c2 % 2 == 0 && c3 % 2 == 0) ans = "YES";
    }
    cout << ans << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}