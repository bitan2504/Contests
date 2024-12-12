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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<ll, ll>> dp(n);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        ll m1 = 0, m2 = 0;
        dp[u].first = adj[u].size();
        for (auto v : adj[u]) {
            if (v == p) continue;
            self(self, v, u);
            dp[u].first = max(dp[u].first, dp[v].first + adj[u].size() - 2);
            if (dp[v].first > m2) m2 = dp[v].first;
            if (m2 > m1) swap(m1, m2);
        }
        dp[u].second = m1 + m2 + adj[u].size() - 4;
    };
    dfs(dfs, 0, -1);
    ll maxi = 0;
    for (int i = 0; i < n; i++) maxi = max({maxi, dp[i].first, dp[i].second});
    cout << maxi << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}