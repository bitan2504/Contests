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

ll f(int j, int k, string &a, string &b, string &c, vector<vector<ll>> &dp) {
    int i = j + k;
    int sa = a.size(), sb = b.size();
    if (i == sa + sb) return dp[j][k] = 0;
    if (dp[j][k] != -1) return dp[j][k];
    ll A = 1e12, B = 1e12;
    if (j < sa) {
        A = f(j + 1, k, a, b, c, dp);
        if (a[j] != c[i]) A++;
    }
    if (k < sb) {
        B = f(j, k + 1, a, b, c, dp);
        if (b[k] != c[i]) B++;
    }
    return dp[j][k] = min(A, B);
}

// Main solve function
void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    vector<vector<ll>> dp(a.size() + 1, vector<ll> (b.size() + 1, -1));
    cout << f(0, 0, a, b, c, dp) << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}