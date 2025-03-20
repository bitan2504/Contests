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

void build(vector<int>& arr, vector<int>& segTree, int node, int s, int e) {
    if (s == e) {
        segTree[node] = arr[s];
    } else {
        int m = (s + e) / 2;
        build(arr, segTree, 2 * node + 1, s, m);
        build(arr, segTree, 2 * node + 2, m + 1, e);
        segTree[node] = gcd(segTree[2 * node + 1], segTree[2 * node + 2]);
    }
}

ll query(vector<int>& segTree, int node, int s, int e, int l, int r) {
    if (r < s || e < l) {
        return 0;
    }
    if (l <= s && e <= r) {
        return segTree[node];
    }
    int m = (s + e) / 2;
    int left = query(segTree, 2 * node + 1, s, m, l, r);
    int right = query(segTree, 2 * node + 2, m + 1, e, l, r);
    return gcd(left, right);
}

// Main solve function
void solve() {
    ll n, q; cin >> n >> q;
    vector<int> a(n), arr(n - 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        while (q--) {
            ll l, r; cin >> l >> r;
            cout << 0 << " ";
        }
        cout << endl;
        return ;
    }
    for (int i = 0; i < n - 1; i++) arr[i] = abs(a[i] - a[i + 1]);
    vector<int> segTree(4 * (n - 1));
    build(arr, segTree, 0, 0, arr.size() - 1);
    while (q--) {
        ll l, r; cin >> l >> r;
        l--, r--;
        if (l == r) {
            cout << 0 << " ";
            continue;
        }
        r--;
        cout << query(segTree, 0, 0, arr.size() - 1, l, r) << " ";
    }
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}