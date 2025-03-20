/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

// Main solve function
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp(n + 1, 0);
    vector<int> pre(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        if(pre[a[i]] != -1) {
            dp[i] = min(dp[i], dp[pre[a[i]]]);
        }
        pre[a[i]] = i;
    }
    cout << dp[n] << endl;;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}