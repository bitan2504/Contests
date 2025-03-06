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
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    map<int, int> ord, c, p;
    for (int i = 0; i < 26; i++) {
        ord[b[i]] = i + 1;
        c[i + 1] = b[i];
        // cerr << (char)b[i];
    }
    // cerr << endl;
    for (int i = 0; i < 26; i++) {
        p[b[i]] = c[27 - ord[b[i]]];
        // cerr << (char)p[b[i]];
    }
    // cerr << endl;

    vector<vector<ll>> dp(2, vector<ll> (2));
    int prev = 0, curr = 1;
    dp[prev][0] = 0;
    dp[prev][1] = 1;
    for (int i = 1; i < n; i++) {
        dp[curr][0] = dp[curr][1] = 1e12;
        if (a[i] >= a[i - 1]) {
            dp[curr][0] = min(dp[curr][0], dp[prev][0]);
        }
        if (a[i] >= p[a[i - 1]]) {
            dp[curr][0] = min(dp[curr][0], dp[prev][1]);
        }
        if (p[a[i]] >= p[a[i - 1]]) {
            dp[curr][1] = min(dp[curr][1], 1  + dp[prev][1]);
        }
        if (p[a[i]] >= a[i - 1]) {
            dp[curr][1] = min(dp[curr][1], 1 + dp[prev][0]);
        }
        prev = (prev + 1) % 2, curr = (curr + 1) % 2;
    }
    cout << (min(dp[prev][0], dp[prev][1]) >= 1e12 ? -1 : min(dp[prev][0], dp[prev][1])) << endl; 
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}