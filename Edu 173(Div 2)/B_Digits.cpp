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
    ll n, d; cin >> n >> d;
    set<int> st = {1};
    if (d % 3 == 0 || n >= 3) st.insert(3);
    if (d == 5) st.insert(5);
    if (d == 7 || n >= 3) st.insert(7);
    if (d == 9 || n >= 6) st.insert(9);
    if (d % 3 == 0 && n >= 3) st.insert(9);
    for (auto i : st) cout << i << " ";
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}