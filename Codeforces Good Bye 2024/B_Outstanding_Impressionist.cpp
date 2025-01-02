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
    map<int, int> mpp;
    set<int> st;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[i] = {l, r};
        if (l == r) {
            mpp[l]++;
            st.insert(l);
        }
    }
    vector<char> b(n, '0');
    vector<int> c(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        c[i] = c[i - 1] + (st.find(i) != st.end());
    }
    for (int i = 0; i < n; i++) {
        if (a[i].first == a[i].second) {
            if (mpp[a[i].first] == 1) b[i] = '1';
        } else {
            if (c[a[i].second] - c[a[i].first - 1] <= a[i].second - a[i].first)
                b[i] = '1';
        }
    }
    for (auto i: b) cout << i;
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}