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
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        q.push({x, i});
    }
    vector<int> ans;
    ll plast = -1, clast = -1, end = n, lch = q.top().first;
    
    while (q.size()) {
        while (q.size() && q.top().first == lch) {
            auto it = q.top(); q.pop();
            ll top = it.first, ind = it.second;
            ans.push_back(top);
            plast = ind;
        }
        if (!q.size()) break;
        while (q.size() && q.top().second < plast) {
            auto it = q.top(); q.pop();
            ll top = it.first, ind = it.second;
            q.push({top + 1, end++});
        }
        if (!q.size()) break;
        auto it = q.top(); q.pop();
        ll top = it.first, ind = it.second;
        lch = top;
        plast = ind;
        ans.push_back(top);
    }

    for (auto it : ans) cout << it << " ";
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}